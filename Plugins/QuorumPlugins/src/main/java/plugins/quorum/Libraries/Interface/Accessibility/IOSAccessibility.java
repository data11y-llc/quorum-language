package plugins.quorum.Libraries.Interface.Accessibility;

import org.robovm.apple.coregraphics.CGRect;
import org.robovm.apple.uikit.*;
import plugins.quorum.Libraries.Game.IOSApplication;
import plugins.quorum.Libraries.Interface.Accessibility.IOS.ButtonIOS;
import plugins.quorum.Libraries.Interface.Accessibility.IOS.ItemIOS;
import quorum.Libraries.Interface.Controls.Button_;
import quorum.Libraries.Interface.Controls.TextField_;
import quorum.Libraries.Interface.Controls.ToggleButton_;
import quorum.Libraries.Interface.Events.*;
import quorum.Libraries.Interface.Item_;
import quorum.Libraries.Interface.Selections.TextBoxSelection_;
import quorum.Libraries.Interface.Selections.TextFieldSelection_;

import java.util.HashMap;

public class IOSAccessibility {
    public Object me_ = null;
    public HashMap mapAccessibilityElements = new HashMap<Item_, ItemIOS>();

    public void  NameChanged(Item_ item) {}

    public void  DescriptionChanged(Item_ item) {}

    public void  BoundsChanged(Item_ item) {}

    public void  TextFieldUpdatePassword(TextField_ field) {}

    public void  Update() {
    }

    public void  ProgressBarValueChanged(ProgressBarValueChangedEvent_ progress) {}

    public void SelectionChanged(SelectionEvent_ event) {}

    public void ButtonActivated(Button_ button) {}

    public void ToggleButtonToggled(ToggleButton_ button) {}

    public void  FocusChanged(FocusEvent_ event) throws Exception {
        Item_ item = event.GetNewFocus();
        UIAccessibilityElement element = (UIAccessibilityElement) mapAccessibilityElements.get(item);
        System.out.println("Focus Changed to " + element.getAccessibilityLabel());
        UIAccessibilityGlobals.postNotification(UIAccessibilityNotification.LayoutChangedNotification, element);
    }

    public boolean NativeAdd(Item_ item) {
        boolean debug = false;
        int x = 0;
        int y = 0;
        int width = 0;
        int height = 0;

        if(item == null) {
            return false;
        }

        ItemIOS element = new ItemIOS(IOSApplication.accessibilityContainer);
        element.Initialize(item);

        //Get the accessibility code and do custom controls.
        //Many of the traits and properties here are incorrect, but the structure is there which can get us started
        int code = item.GetAccessibilityCode();
        if(code != -1) {
            System.out.println("Name: " + item.GetName() + " Code: " + code);
        }
        if (code == item.Get_Libraries_Interface_Item__NOT_ACCESSIBLE_() || !item.IsShowing()) {
            return false;
        } else if (code == item.Get_Libraries_Interface_Item__ITEM_()) {
            element.setAccessibilityTraits(UIAccessibilityTraits.AllowsDirectInteraction);
        } else if (code == item.Get_Libraries_Interface_Item__CUSTOM_()) {
            element.setAccessibilityTraits(UIAccessibilityTraits.AllowsDirectInteraction);
        } else if (code == item.Get_Libraries_Interface_Item__CHECKBOX_()) {
            element.setAccessibilityTraits(UIAccessibilityTraits.AllowsDirectInteraction);
            //element.setAccessibilityTraits(UIAccessibilityTraits.);
        } else if (code == item.Get_Libraries_Interface_Item__RADIO_BUTTON_()) {
            element.setAccessibilityTraits(UIAccessibilityTraits.AllowsDirectInteraction);
            element.setAccessibilityTraits(UIAccessibilityTraits.Button);
        } else if (code == item.Get_Libraries_Interface_Item__BUTTON_()) {
            ButtonIOS button = new ButtonIOS(IOSApplication.accessibilityContainer);
            button.Initialize((Button_)item);
            element = button;
        } else if (code == item.Get_Libraries_Interface_Item__TOGGLE_BUTTON_()) {
            element.setAccessibilityTraits(UIAccessibilityTraits.AllowsDirectInteraction);
            element.setAccessibilityTraits(UIAccessibilityTraits.Button);
        } else if (code == item.Get_Libraries_Interface_Item__LABEL_()) {
            return false;
        }

        if (item.GetName() != null) {
            element.setAccessibilityIdentifier(item.GetName() + " ID");
            element.setAccessibilityValue(item.GetName() + " Value");
            element.setAccessibilityLabel(item.GetName());
        }
        else {
            element.setAccessibilityLabel("Name");
        }

        if (item.GetDescription() != null) {
            element.setAccessibilityHint(item.GetDescription());
        }
        else {
            element.setAccessibilityHint("Description");
        }


        element.setAccessibilityElement(true);
        for (UIAccessibilityTraits trait : element.getAccessibilityTraits()) {
            System.out.println(trait.toString());
        }

        //accessibilityElement.setAccessibilityValue(item.GetDescription());
        element.setAccessibilityIdentifier("" + item.GetHashCode());
        element.setAccessibilityFrame(new CGRect(x, y, width, height));

        // Add the accessibility element to the list
        IOSApplication.accessibilityContainer.getAccessibilityElements().add(element);
        mapAccessibilityElements.put(item, element);

        // Inform iOS that the accessibility elements have changed
        UIAccessibilityGlobals.postNotification(UIAccessibilityNotification.ScreenChangedNotification, element);

        if(debug){
            System.out.println("The bounds are" + IOSApplication.accessibilityContainer.getFrame().getX() + " " + IOSApplication.accessibilityContainer.getFrame().getY() + " " + IOSApplication.accessibilityContainer.getFrame().getWidth() + " " + IOSApplication.accessibilityContainer.getFrame().getHeight());
        }
        return true;
    }

    public void TextSelectionChanged(TextBoxSelection_ selection)
    {
    }

    public void TextSelectionChanged(TextFieldSelection_ selection)
    {
    }

    public boolean Select(Item_ item)
    {
        return false;
    }

    private class HiddenView extends UIView {
        public HiddenView() {

        }
    }

    private class HiddenButton extends UIButton {
        public HiddenButton() {

        }
    }
    private class HiddenTextField extends UITextField {
        public HiddenTextField () {

            setKeyboardType(UIKeyboardType.Default);
            setReturnKeyType(UIReturnKeyType.Done);
            setAutocapitalizationType(UITextAutocapitalizationType.None);
            setAutocorrectionType(UITextAutocorrectionType.No);
            setSpellCheckingType(UITextSpellCheckingType.No);
            setHidden(true);
        }

        @Override
        public void deleteBackward () {
            //app.input.inputProcessor.keyTyped((char)8);
            //super.deleteBackward();
            //Gdx.graphics.requestRendering();
        }
    }

    public boolean NativeRemove(Item_ item) {
        return false;
    }

    public void  MenuChanged(MenuChangeEvent_ event) {}

    public void  TreeChanged(TreeChangeEvent_ event) {}

    public void  TreeTableChanged(TreeTableChangeEvent_ event) {}

    public void  ControlActivated(ControlActivationEvent_ event) {}

    public void  TextChanged(TextChangeEvent_ event) {}

    public void  WindowFocusChanged(WindowFocusEvent_ event) {}

    public void  Notify(Item_ item, String value) {}

    public void  Notify(Item_ item, String value, int notificationType) {}

    public void  Shutdown() {}
}
