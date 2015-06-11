/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.quorum.projects;

import java.awt.Image;
import java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import javax.swing.DefaultListModel;
import javax.swing.ImageIcon;
import javax.swing.JFileChooser;
import org.openide.filesystems.FileObject;
import org.openide.filesystems.FileUtil;
import javax.swing.JOptionPane;
import org.netbeans.api.project.Project;
import java.util.Properties;
import javax.swing.SwingUtilities;

/**
 *
 * @author stefika
 */
public class GamePanel extends javax.swing.JPanel {
    private Project project;
    private DefaultListModel imageSheets = new DefaultListModel();
    private DefaultListModel images = new DefaultListModel();
    private HashMap<String, List<String>> imagesHash = new HashMap<>();
    
    /**
     * Creates new form GamePanel
     */
    public GamePanel() {
        initComponents();
        imageSheetList.setModel(imageSheets);
        imageList.setModel(images);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        imageFileChooser = new javax.swing.JFileChooser();
        folderChooser = new javax.swing.JFileChooser();
        rebuildImageSheetOnCompileCheckBox = new javax.swing.JCheckBox();
        jScrollPane1 = new javax.swing.JScrollPane();
        imageSheetList = new javax.swing.JList();
        addImageSheetButton = new javax.swing.JButton();
        editImageSheetButton = new javax.swing.JButton();
        removeImageSheetButton = new javax.swing.JButton();
        imageSheetLabel = new javax.swing.JLabel();
        buildImageSheetButton = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        imageList = new javax.swing.JList();
        imageLabel = new javax.swing.JLabel();
        addImageToSheetButton = new javax.swing.JButton();
        addFolderToSheetButton = new javax.swing.JButton();
        removeImageFromSheetButton = new javax.swing.JButton();
        previewLabel = new javax.swing.JLabel();
        pathTextField = new javax.swing.JTextField();
        buildLabel = new javax.swing.JLabel();
        isEnabledCheckBox = new javax.swing.JCheckBox();

        folderChooser.setFileSelectionMode(javax.swing.JFileChooser.DIRECTORIES_ONLY);

        org.openide.awt.Mnemonics.setLocalizedText(rebuildImageSheetOnCompileCheckBox, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.rebuildImageSheetOnCompileCheckBox.text")); // NOI18N

        imageSheetList.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        imageSheetList.setToolTipText(org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.imageSheetList.toolTipText")); // NOI18N
        imageSheetList.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                imageSheetListValueChanged(evt);
            }
        });
        jScrollPane1.setViewportView(imageSheetList);
        imageSheetList.getAccessibleContext().setAccessibleName(org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.imageSheetList.AccessibleContext.accessibleName")); // NOI18N
        imageSheetList.getAccessibleContext().setAccessibleDescription(org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.imageSheetList.AccessibleContext.accessibleDescription")); // NOI18N
        imageSheetList.getAccessibleContext().setAccessibleParent(this);

        org.openide.awt.Mnemonics.setLocalizedText(addImageSheetButton, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.addImageSheetButton.text")); // NOI18N
        addImageSheetButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addImageSheetButtonActionPerformed(evt);
            }
        });

        org.openide.awt.Mnemonics.setLocalizedText(editImageSheetButton, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.editImageSheetButton.text")); // NOI18N
        editImageSheetButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                editImageSheetButtonActionPerformed(evt);
            }
        });

        org.openide.awt.Mnemonics.setLocalizedText(removeImageSheetButton, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.removeImageSheetButton.text")); // NOI18N
        removeImageSheetButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                removeImageSheetButtonActionPerformed(evt);
            }
        });

        org.openide.awt.Mnemonics.setLocalizedText(imageSheetLabel, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.imageSheetLabel.text")); // NOI18N

        org.openide.awt.Mnemonics.setLocalizedText(buildImageSheetButton, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.buildImageSheetButton.text")); // NOI18N
        buildImageSheetButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buildImageSheetButtonActionPerformed(evt);
            }
        });

        imageList.addListSelectionListener(new javax.swing.event.ListSelectionListener() {
            public void valueChanged(javax.swing.event.ListSelectionEvent evt) {
                imageListValueChanged(evt);
            }
        });
        jScrollPane2.setViewportView(imageList);
        imageList.getAccessibleContext().setAccessibleName(org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.imageList.AccessibleContext.accessibleName")); // NOI18N
        imageList.getAccessibleContext().setAccessibleDescription(org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.imageList.AccessibleContext.accessibleDescription")); // NOI18N

        org.openide.awt.Mnemonics.setLocalizedText(imageLabel, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.imageLabel.text")); // NOI18N

        org.openide.awt.Mnemonics.setLocalizedText(addImageToSheetButton, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.addImageToSheetButton.text")); // NOI18N
        addImageToSheetButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addImageToSheetButtonActionPerformed(evt);
            }
        });

        org.openide.awt.Mnemonics.setLocalizedText(addFolderToSheetButton, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.addFolderToSheetButton.text")); // NOI18N
        addFolderToSheetButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addFolderToSheetButtonActionPerformed(evt);
            }
        });

        org.openide.awt.Mnemonics.setLocalizedText(removeImageFromSheetButton, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.removeImageFromSheetButton.text")); // NOI18N
        removeImageFromSheetButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                removeImageFromSheetButtonActionPerformed(evt);
            }
        });

        org.openide.awt.Mnemonics.setLocalizedText(previewLabel, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.previewLabel.text")); // NOI18N
        previewLabel.setToolTipText(org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.previewLabel.toolTipText")); // NOI18N
        previewLabel.setMaximumSize(new java.awt.Dimension(128, 128));
        previewLabel.setMinimumSize(new java.awt.Dimension(128, 128));
        previewLabel.setPreferredSize(new java.awt.Dimension(128, 128));

        pathTextField.setText(org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.pathTextField.text")); // NOI18N

        org.openide.awt.Mnemonics.setLocalizedText(buildLabel, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.buildLabel.text")); // NOI18N
        buildLabel.setToolTipText(org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.buildLabel.toolTipText")); // NOI18N

        org.openide.awt.Mnemonics.setLocalizedText(isEnabledCheckBox, org.openide.util.NbBundle.getMessage(GamePanel.class, "GamePanel.isEnabledCheckBox.text")); // NOI18N
        isEnabledCheckBox.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                isEnabledCheckBoxActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(imageSheetLabel)
                                .addGap(0, 0, Short.MAX_VALUE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 269, Short.MAX_VALUE)
                                .addGap(48, 48, 48)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(addImageSheetButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(editImageSheetButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(removeImageSheetButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(buildImageSheetButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(imageLabel)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jScrollPane2)
                                        .addGap(48, 48, 48)))
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(addImageToSheetButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(addFolderToSheetButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(removeImageFromSheetButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(previewLabel, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 128, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(buildLabel)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(pathTextField))))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(isEnabledCheckBox, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(rebuildImageSheetOnCompileCheckBox)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(rebuildImageSheetOnCompileCheckBox)
                    .addComponent(isEnabledCheckBox))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(pathTextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(buildLabel))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(imageSheetLabel)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(addImageSheetButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(editImageSheetButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(removeImageSheetButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(buildImageSheetButton))
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 175, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(imageLabel)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(addImageToSheetButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(addFolderToSheetButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(removeImageFromSheetButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(previewLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 192, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(31, 31, 31))
        );
    }// </editor-fold>//GEN-END:initComponents

    private void addImageSheetButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addImageSheetButtonActionPerformed
        String input = JOptionPane.showInputDialog(this, "Please enter the name of the image sheet", "Image sheet dialog", JOptionPane.PLAIN_MESSAGE);
        if(input != null) {
            if(!input.isEmpty()) {
                if(!imageSheets.contains(input)) {
                    imageSheets.addElement(input);
                    if(imageSheets.size() == 1) { //default to that one.
                        imageSheetList.setSelectedIndex(0);
                    }
                    List<String> list = imagesHash.get(input);
                    //this is adding a new image sheet. If it already exists, delete the
                    //old one and replace it with an empty list
                    if(list != null) {
                        imagesHash.remove(input);
                    }

                    list = new LinkedList<String>();
                    imagesHash.put(input, list);
                }
            }
        }
    }//GEN-LAST:event_addImageSheetButtonActionPerformed

    private void editImageSheetButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_editImageSheetButtonActionPerformed
        int index = imageSheetList.getSelectedIndex();
        if(index != -1) {
            String get = (String)imageSheets.get(index);
            String input = JOptionPane.showInputDialog(this, "Please enter the name of the image sheet", get);
            imageSheets.set(index, input);
        }
    }//GEN-LAST:event_editImageSheetButtonActionPerformed

    private void removeImageSheetButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_removeImageSheetButtonActionPerformed
        int index = imageSheetList.getSelectedIndex();
        if(index != -1) {
            imageSheets.remove(index);
        }
    }//GEN-LAST:event_removeImageSheetButtonActionPerformed

    private void addImageToSheetButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addImageToSheetButtonActionPerformed
        int index = imageSheetList.getSelectedIndex();
        if(index != -1) {
            int returnVal = imageFileChooser.showOpenDialog(this);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                File file = imageFileChooser.getSelectedFile();
                if(file != null && !file.isDirectory()) {
                    String path = getPathRelativeToProject(file);
                    if(!images.contains(path) && path != null && !path.isEmpty()) {
                        images.addElement(path);
                        if(images.size() == 1) { //default to that one.
                            imageList.setSelectedIndex(0);
                        }
                        String value = (String) imageSheets.get(index);
                        List<String> list = imagesHash.get(value);
                        list.add(path);
                    }
                }
            }
        }
    }//GEN-LAST:event_addImageToSheetButtonActionPerformed

    private void imageSheetListValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_imageSheetListValueChanged
        if(!evt.getValueIsAdjusting()) {
            int index = imageSheetList.getSelectedIndex();
            if(index != -1) {
                String value = (String) imageSheets.get(index);
                List<String> list = imagesHash.get(value);
                if(list != null) {
                    images.clear();
                    Iterator<String> it = list.iterator();
                    while(it.hasNext()) {
                        String next = it.next();
                        images.addElement(next);
                    }
                }
            }
        }
    }//GEN-LAST:event_imageSheetListValueChanged

    private void addFolderToSheetButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addFolderToSheetButtonActionPerformed
        int index = imageSheetList.getSelectedIndex();
        if(index != -1) {
            int returnVal = folderChooser.showOpenDialog(this);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                File file = folderChooser.getSelectedFile();
                if(file != null && file.isDirectory()) {
                    File[] files = file.listFiles();
                    for(int i = 0; i < files.length; i++) {
                        File f = files[i];
                        
                        String path = getPathRelativeToProject(f);
                        int period = path.lastIndexOf(".");
                        String extension = null;
                        if(path.length() > period + 1) {
                            extension = path.substring(period + 1);
                        }
                        if(extension != null && 
                               (extension.compareToIgnoreCase("JPG") == 0 ||
                                extension.compareToIgnoreCase("JPEG") == 0 || 
                                extension.compareToIgnoreCase("PNG") == 0)) {
                            if(!images.contains(path) && path != null && !path.isEmpty()) {
                                images.addElement(path);
                                if(images.size() == 1) { //default to that one.
                                    imageList.setSelectedIndex(0);
                                }
                                String value = (String) imageSheets.get(index);
                                List<String> list = imagesHash.get(value);
                                list.add(path);
                            }
                        }
                    }
                }
            }
        }
    }//GEN-LAST:event_addFolderToSheetButtonActionPerformed

    private void imageListValueChanged(javax.swing.event.ListSelectionEvent evt) {//GEN-FIRST:event_imageListValueChanged
        if(!evt.getValueIsAdjusting()) {
            QuorumProject proj = (QuorumProject) project;
            FileObject directory = proj.getProjectDirectory();
            String projectPath = FileUtil.toFile(directory).getAbsolutePath();
            int index = imageList.getSelectedIndex();
            if(index != -1) {
                String value = (String) images.get(index);
                String path = projectPath + File.separator + value;
                File file = new File(path);
                if(file.exists()) {
                    //load up the file into an image and place it in the JLabel
                    ImageIcon icon = new ImageIcon(file.getAbsolutePath()); 
                    Image image = icon.getImage();
                    image = image.getScaledInstance(previewLabel.getWidth(), previewLabel.getHeight(),  java.awt.Image.SCALE_SMOOTH);
                    icon = new ImageIcon(image);
                    previewLabel.setIcon(icon);
                }
            }
        }
    }//GEN-LAST:event_imageListValueChanged

    private void removeImageFromSheetButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_removeImageFromSheetButtonActionPerformed
        int index = imageList.getSelectedIndex();
        if(index != -1) {
            String remove = (String) images.get(index);
            if(index >=0 && index < images.size()) {
                images.remove(index);
            }
            String value = (String) imageSheets.get(imageSheetList.getSelectedIndex());
            List<String> list = imagesHash.get(value);
            if(list != null) {
                list.remove(remove);
            }
        }
    }//GEN-LAST:event_removeImageFromSheetButtonActionPerformed

    private void buildImageSheetButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buildImageSheetButtonActionPerformed
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                if(imageSheetList.getSelectedIndex() != -1) {
                    ImageSheetManager manager = getManager();
                    QuorumProject proj = (QuorumProject) project;
                    FileObject directory = proj.getProjectDirectory();
                    File path = FileUtil.toFile(directory);
                    manager.buildImageSheet((String) imageSheetList.getSelectedValue(), path);
                }
            }
        });
    }//GEN-LAST:event_buildImageSheetButtonActionPerformed

    private void isEnabledCheckBoxActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_isEnabledCheckBoxActionPerformed
        setEnabledGUI();
    }//GEN-LAST:event_isEnabledCheckBoxActionPerformed

    private void setEnabledGUI() {
        boolean isTrue = false;
        if(isEnabledCheckBox.isSelected()) {
            isTrue = true;
        } else {
            isTrue = false;
        }
        
        rebuildImageSheetOnCompileCheckBox.setEnabled(isTrue);
        pathTextField.setEnabled(isTrue);
        imageSheetList.setEnabled(isTrue);
        addImageSheetButton.setEnabled(isTrue);
        addImageToSheetButton.setEnabled(isTrue);
        buildImageSheetButton.setEnabled(isTrue);
        editImageSheetButton.setEnabled(isTrue);
        addFolderToSheetButton.setEnabled(isTrue);
        imageList.setEnabled(isTrue);
        buildLabel.setEnabled(isTrue);
        imageSheetLabel.setEnabled(isTrue);
        imageLabel.setEnabled(isTrue);
        imageSheetList.setEnabled(isTrue);
        rebuildImageSheetOnCompileCheckBox.setEnabled(isTrue);
        removeImageFromSheetButton.setEnabled(isTrue);
        removeImageSheetButton.setEnabled(isTrue);
    }
    
    public String getPathRelativeToProject(File file) {
        String absolutePath = file.getAbsolutePath();
        QuorumProject proj = (QuorumProject) project;
        FileObject directory = proj.getProjectDirectory();
        String projectPath = FileUtil.toFile(directory).getAbsolutePath();
        Path sourceFile = Paths.get(projectPath);
        Path targetFile = Paths.get(absolutePath); 
        Path relativePath = sourceFile.relativize(targetFile);

        return relativePath.toString();
    }
    
    public ImageSheetManager getManager() {
        ImageSheetManager manager = new ImageSheetManager();
        manager.setImagesHash(imagesHash);
        manager.setBuildPath(pathTextField.getText());
        manager.setEnableImageSheetSupport(isEnabledCheckBox.isSelected());
        manager.setRebuildOnCompile(rebuildImageSheetOnCompileCheckBox.isSelected());
        return manager;
    }
    
    public Project getProject() {
        return project;
    }
    
    public void setProject(Project project) {
        this.project = project;
        loadProperties();
    }
    
    private void loadProperties() {
        Properties properties = project.getLookup().lookup(Properties.class);
        String enabled = properties.getProperty(ImageSheetManager.IMAGE_SHEETS_ENABLED);
        if(enabled != null) {
            isEnabledCheckBox.setSelected(true);
        } else { //by default, this does not exist if it is false
            isEnabledCheckBox.setSelected(false);
        }
        String rebuild = properties.getProperty(ImageSheetManager.REBUILD_IMAGE_SHEETS_ON_COMPILE);
        if(rebuild != null) {
            rebuildImageSheetOnCompileCheckBox.setSelected(true);
        } else { //by default, this does not exist if it is false
            rebuildImageSheetOnCompileCheckBox.setSelected(false);
        }
        String sheets = properties.getProperty(ImageSheetManager.IMAGE_SHEETS);
        ImageSheetManager ism = new ImageSheetManager();
        ism.load(sheets);
        imagesHash = ism.getImagesHash();
        populateTextboxes();
        
        String path = properties.getProperty(ImageSheetManager.IMAGE_SHEET_BUILD_PATH);
        if(path != null) {
            pathTextField.setText(path);
        } else {
            pathTextField.setText("resources");
        }
        setEnabledGUI();
    }
    
    private void populateTextboxes() {
        if(imagesHash != null) {
            Iterator<String> iterator = imagesHash.keySet().iterator();
            int i = 0;
            while(iterator.hasNext()) {
                String next = iterator.next();
                imageSheets.addElement(next);
                if(i == 0) {
                    List<String> get = imagesHash.get(next);
                    Iterator<String> li = get.iterator();
                    images.clear();
                    while(li.hasNext()) {
                        String image = li.next();
                        images.addElement(image);
                    }
                }
                i++;
            }
        }
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton addFolderToSheetButton;
    private javax.swing.JButton addImageSheetButton;
    private javax.swing.JButton addImageToSheetButton;
    private javax.swing.JButton buildImageSheetButton;
    private javax.swing.JLabel buildLabel;
    private javax.swing.JButton editImageSheetButton;
    private javax.swing.JFileChooser folderChooser;
    private javax.swing.JFileChooser imageFileChooser;
    private javax.swing.JLabel imageLabel;
    private javax.swing.JList imageList;
    private javax.swing.JLabel imageSheetLabel;
    private javax.swing.JList imageSheetList;
    private javax.swing.JCheckBox isEnabledCheckBox;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTextField pathTextField;
    private javax.swing.JLabel previewLabel;
    private javax.swing.JCheckBox rebuildImageSheetOnCompileCheckBox;
    private javax.swing.JButton removeImageFromSheetButton;
    private javax.swing.JButton removeImageSheetButton;
    // End of variables declaration//GEN-END:variables
}
