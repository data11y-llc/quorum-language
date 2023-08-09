package plugins.quorum.Libraries.Interface.Accessibility;

import java.net.URISyntaxException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.logging.Level;
import java.util.logging.Logger;

import dev.accesskit.*;
import dev.accesskit.Tree;
import org.lwjgl.glfw.GLFWNativeCocoa;
import plugins.quorum.Libraries.Game.DesktopDisplay;
import plugins.quorum.Libraries.Interface.Accessibility.accesskit.*;
import plugins.quorum.Libraries.Interface.AccessibilityManager;
import quorum.Libraries.Interface.Controls.*;
import quorum.Libraries.Interface.Events.ControlActivationEvent_;
import quorum.Libraries.Interface.Events.FocusEvent_;
import quorum.Libraries.Interface.Events.MenuChangeEvent_;
import quorum.Libraries.Interface.Events.ProgressBarValueChangedEvent_;
import quorum.Libraries.Interface.Events.SelectionEvent_;
import quorum.Libraries.Interface.Events.TextChangeEvent_;
import quorum.Libraries.Interface.Events.TreeChangeEvent_;
import quorum.Libraries.Interface.Events.TreeTableChangeEvent_;
import quorum.Libraries.Interface.Events.WindowFocusEvent_;
import quorum.Libraries.Interface.Item_;
import quorum.Libraries.Interface.Selections.TextBoxSelection_;
import quorum.Libraries.Interface.Selections.TextFieldSelection_;

/**
 *
 * @author andreasstefik
 */
public class MacAccessibility {
    public java.lang.Object me_ = null;
    private MacosSubclassingAdapter adapter;
    private boolean isWindowFocused = true;
    private final RootItemKit root = new RootItemKit();
    private final HashMap<NodeId, ItemKit> items = new HashMap<NodeId, ItemKit>();
    private NodeId focus = root.GetNodeID();
    private final HashSet<NodeId> dirtyNodes = new HashSet<NodeId>();
    private boolean isFocusDirty = false;

    public MacAccessibility() {
        try
        {
            java.io.File file = new java.io.File(AccessibilityManager.class.getProtectionDomain().getCodeSource().getLocation().toURI().getPath());
            String runLocation = file.getParentFile().getAbsolutePath();
            String nativeFile = runLocation + "/jni/libaccesskit_jni.dylib";
            System.load(nativeFile);

            long handle = GLFWNativeCocoa.glfwGetCocoaWindow(DesktopDisplay.window);

            adapter = MacosSubclassingAdapter.forWindow(handle, new TreeUpdateSupplier() {
                @Override
                public TreeUpdate get() {
                    return BuildFullTree();
                }
            });
        }
        catch (URISyntaxException ex)
        {
            Logger.getLogger(AccessibilityManager.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static void Traverse(ItemKit itemKit, TreeUpdate update) {
        update.add(itemKit.GetNodeID(), itemKit.Build());
        for (ItemKit child : itemKit.GetChildren()) {
            Traverse(child, update);
        }
    }

    private TreeUpdate BuildFullTree() {
        TreeUpdate update = new TreeUpdate();
        Traverse(root, update);
        update.setTree(new Tree(root.GetNodeID()));
        SetTreeUpdateFocus(update);
        return update;
    }

    private void SetItemToDirty(Item_ item) {
        if(item != null) {
            ItemKit kit = items.get(ItemKit.GetNodeID(item));
            if(kit != null) {
                dirtyNodes.add(kit.GetNodeID());
            }
        }
    }

    public void  NameChanged(Item_ item) {
//        SetItemToDirty(item);
    }

    public void  DescriptionChanged(Item_ item) {
//        SetItemToDirty(item);
    }

    public void  BoundsChanged(Item_ item) {
        SetItemToDirty(item);
    }

    public void  TextFieldUpdatePassword(TextField_ item) {
        SetItemToDirty(item);
    }

    public void  NativeUpdate() {
        if (!dirtyNodes.isEmpty() || isFocusDirty) {
            adapter.updateIfActive(new TreeUpdateSupplier() {
                @Override
                public TreeUpdate get() {
                    TreeUpdate update = new TreeUpdate();
                    for (NodeId id : dirtyNodes) {
                        ItemKit kit = items.get(id);
                        update.add(id, kit.Build());
                    }
                    SetTreeUpdateFocus(update);
                    return update;
                }
            });
            dirtyNodes.clear();
            isFocusDirty = false;
        }
    }

    public void  ProgressBarValueChanged(ProgressBarValueChangedEvent_ item) {
        SetItemToDirty(item.GetProgressBar());
    }

    public void  SelectionChanged(SelectionEvent_ event) {
        /*
        Not sure what we do with this one yet, but I suspect it is relevant for radio groups and trees.
         */
    }

    public void TextSelectionChanged(TextBoxSelection_ selection)
    {
//        SetItemToDirty(selection.GetTextBox());
    }

    public void TextSelectionChanged(TextFieldSelection_ selection)
    {
//        SetItemToDirty(selection.GetTextField());
    }

    public boolean Select(Item_ item)
    {
        /*
        Not sure what we do in access kit here, but this is when the selection has changed, for example to a tree item.
        I don't think this is directly a focus call, it's a selection call, so this may be different at the access kit level.
         */
        return false;
    }

    public void  ButtonActivated(Button_ button) {
        if(button == null) {
            return;
        }
    }

    public void  ToggleButtonToggled(ToggleButton_ button) {
        SetItemToDirty(button);
    }

    private void SetTreeUpdateFocus(TreeUpdate update) {
        if (isWindowFocused) {
            update.setFocus(focus);
        } else {
            update.clearFocus();
        }
    }


    public void  FocusChanged(FocusEvent_ event) {
        Item_ item = event.GetNewFocus();
        if(item != null) {
            NodeId id = ItemKit.GetNodeID(item);
            ItemKit kit = items.get(id);
            if(kit != null) {
                focus = id;
                isFocusDirty = true;
            }
        }
    }

    private ItemKit GetKitFromCode(Item_ item) {
        int code = item.GetAccessibilityCode();
        ItemKit itemKit = null;
        if (code == item.Get_Libraries_Interface_Item__NOT_ACCESSIBLE_() || !item.IsShowing()) {
            return null;
        } else if (code == item.Get_Libraries_Interface_Item__ITEM_()) {
            itemKit = new ItemKit();
        } else if (code == item.Get_Libraries_Interface_Item__CUSTOM_()) {
            itemKit = new ItemKit();
        } else if (code == item.Get_Libraries_Interface_Item__CHECKBOX_()) {
            CheckboxKit kit = new CheckboxKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__RADIO_BUTTON_()) {
            RadioButtonKit kit = new RadioButtonKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__BUTTON_()) {
            ButtonKit kit = new ButtonKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TOGGLE_BUTTON_()) {
            ToggleButtonKit kit = new ToggleButtonKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TEXTBOX_()) {
            TextboxKit kit = new TextboxKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__MENU_BAR_()) {
            MenuBarKit kit = new MenuBarKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__MENU_ITEM_()) {
            MenuItemKit kit = new MenuItemKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__PANE_()) {
            PaneKit kit = new PaneKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TREE_()) {
            TreeKit kit = new TreeKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TREE_ITEM_()) {
            TreeItemKit kit = new TreeItemKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TOOLBAR_()) {
            ToolbarKit kit = new ToolbarKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TAB_()) {
            ToggleButtonKit kit = new ToggleButtonKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TAB_PANE_()) {
            TabPaneKit kit = new TabPaneKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TABLE_()) {
            TableKit kit = new TableKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__CELL_()) {
            CellKit kit = new CellKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TEXT_FIELD_()) {
            TextFieldKit kit = new TextFieldKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__LIST_()) {
            ListKit kit = new ListKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__LIST_ITEM_()) {
            ListItemKit kit = new ListItemKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TREE_TABLE_()) {
            TreeTableKit kit = new TreeTableKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__DIALOG_()) {
            DialogKit kit = new DialogKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__POPUP_MENU_()) {
            PopupMenuKit kit = new PopupMenuKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__PROGRESS_BAR_()) {
            ProgressBarKit kit = new ProgressBarKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__TREE_TABLE_CELL_()) {
            TreeTableCellKit kit = new TreeTableCellKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__GROUP_()) {
            GroupKit kit = new GroupKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__CHART_()) {
            ChartKit kit = new ChartKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__CHART_SECTION_()) {
            ChartSectionKit kit = new ChartSectionKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__CHART_ITEM_()) {
            ChartItemKit kit = new ChartItemKit();
            itemKit = kit;
        } else if (code == item.Get_Libraries_Interface_Item__LABEL_()) {
            LabelKit kit = new LabelKit();
            itemKit = kit;
        }
        return itemKit;
    }
    public boolean NativeAdd(Item_ item)
    {
        isWindowFocused = true;
        //first has this item already been added
        ItemKit existingKit = items.get(ItemKit.GetNodeID(item));
        if(existingKit != null) {
            return true;
        }

        //second, if it's been added, accesskit seems to require parent hierarchies, at least in this design
        //be ordered parent to child. That might be dangerous quorum side, because that's definitely a contract
        //someone could violate, but we'll give it a try for the end of the hackathon.
        //as such, try the parent next
        Item_ parent = item.GetAccessibleParent();
        ItemKit parentKit;
        if (parent != null) {
            parentKit = items.get(ItemKit.GetNodeID(parent));

            if(parentKit == null) { //the parent isn't actually a node, it needs to be added to the hierarchy
                boolean addedParent = NativeAdd(parent); //if false, the contract is violated. Throw an exception
                parentKit = items.get(ItemKit.GetNodeID(parent)); //it was added, so it must be in there.
                //if the parent kit is still null, just add it to the root
                if(parentKit == null) {
                    parentKit = root;
                }
            }
        } else {
            parentKit = root;
        }

        int code = item.GetAccessibilityCode();
        Role role = null;
        ItemKit itemKit = GetKitFromCode(item);

        if(itemKit != null) {
            itemKit.SetItem(item);
            NodeId id = itemKit.GetNodeID();
            items.put(id, itemKit);
            dirtyNodes.add(id);
            parentKit.AddChild(itemKit);
            dirtyNodes.add(parentKit.GetNodeID());
            return true;
        }

        return false;
    }

    public boolean NativeRemove(Item_ item)
    {
        if(item != null) {
            ItemKit kit = items.remove(ItemKit.GetNodeID(item));
            if(kit != null) {
                ItemKit parent = kit.GetParent();
                NodeId parentID = parent.GetNodeID();
                if (items.containsKey(parentID)) {
                    dirtyNodes.add(parentID);
                }
                dirtyNodes.remove(kit.GetNodeID());
                kit.RemoveFromParent();
            }
        }
        return false;
    }

    public void  MenuChanged(MenuChangeEvent_ event) {
        /*

        Mac menus are weird. How does this impact Access Kit?
         */
    }

    public void  TreeChanged(TreeChangeEvent_ event) {
        /*
        There's no trees yet, but this is the structure of the tree. I'm guessing we just refresh it.
        This may be too heavyweight.
         */
        SetItemToDirty(event.GetTree());
    }

    public void  TreeTableChanged(TreeTableChangeEvent_ event) {
//        SetItemToDirty(event.GetTreeTable());
    }

    public void  ControlActivated(ControlActivationEvent_ event) {
        /*
        I don't know what this one does exactly and the documentation Quorum side is vague. UIA doesn't
        have an implementation for it, so it may not do anything. I'm leaving it blank for now.
         */
    }

    public void  TextChanged(TextChangeEvent_ event) {
        /*
        In the UIA implementation, we call up for this control, which I don't think will work here without a callback.
        For now, I've hooked it up to say it's dirty. This is impractical because it will trigger every character press
        an entire flush of the text. We can also trigger partial updates here, but getting the state to match exactly
        could be error prone. Food for thought.
         */
        Control_ control = event.GetControl();
//        SetItemToDirty(control);
    }

    public void  WindowFocusChanged(WindowFocusEvent_ event) {}

    public void  Notify(Item_ item, String value) {
        /*
        This is kind of similar to an ARIA live region.
         */
    }

    public void  Notify(Item_ item, String value, int notificationType) {
        /*
        This is kind of similar to an ARIA live region.
         */
    }

    public void  Shutdown() {
        /*
        I don't know what you are supposed to do to shut down access kit, but this is where it should happen.
         */
    }
}
