package plugins.quorum.Libraries.Interface.Accessibility.IOS;

import org.robovm.apple.foundation.NSArray;
import org.robovm.apple.foundation.NSRange;
import org.robovm.apple.uikit.*;
import quorum.Libraries.Interface.Controls.Button_;
import quorum.Libraries.Interface.Controls.TextField_;

public class TextFieldIOS extends ItemIOS implements UIKeyInput, UITextInputTraits {
    public boolean isAccessibilityElement() {
        return true;
    }
    public TextFieldIOS(UIAccessibilityContainer container)
    {
        super(container);
    }

    public void Initialize(TextField_ field) {
        UIAccessibilityTraits traits = UIAccessibilityTraits.SearchField;
        this.setAccessibilityTraits(traits);
        super.Initialize(field);
    }

    @Override
    public boolean isFirstResponder() {
        return true;
    }

    @Override
    public boolean canBecomeFirstResponder() {
        return true;
    }

    @Override
    public boolean canResignFirstResponder() {
        return true;
    }

    public void Focus() {
        System.out.println("Focus set to " + item.GetName());
        becomeFirstResponder();
    }

    public void FocusLost() {
        System.out.println("Lost focus from " + item.GetName());
        resignFirstResponder();
    }

    @Override
    public boolean hasText() {
        return true;
    }

    @Override
    public void insertText(String text) {
        System.out.println(text);
    }

    @Override
    public void deleteBackward() {
        System.out.println("Delete backwards");
    }

    @Override
    public UITextAutocapitalizationType getAutocapitalizationType() {
        return UITextAutocapitalizationType.None;
    }

    @Override
    public void setAutocapitalizationType(UITextAutocapitalizationType v) {

    }

    @Override
    public UITextAutocorrectionType getAutocorrectionType() {
        return UITextAutocorrectionType.Default;
    }

    @Override
    public void setAutocorrectionType(UITextAutocorrectionType v) {

    }

    @Override
    public UITextSpellCheckingType getSpellCheckingType() {
        return UITextSpellCheckingType.Default;
    }

    @Override
    public void setSpellCheckingType(UITextSpellCheckingType v) {

    }

    @Override
    public UITextSmartQuotesType getSmartQuotesType() {
        return null;
    }

    @Override
    public void setSmartQuotesType(UITextSmartQuotesType v) {

    }

    @Override
    public UITextSmartDashesType getSmartDashesType() {
        return UITextSmartDashesType.Default;
    }

    @Override
    public void setSmartDashesType(UITextSmartDashesType v) {

    }

    @Override
    public UITextSmartInsertDeleteType getSmartInsertDeleteType() {
        return UITextSmartInsertDeleteType.Default;
    }

    @Override
    public void setSmartInsertDeleteType(UITextSmartInsertDeleteType v) {

    }

    @Override
    public UIKeyboardType getKeyboardType() {
        return UIKeyboardType.Default;
    }

    @Override
    public void setKeyboardType(UIKeyboardType v) {

    }

    @Override
    public UIKeyboardAppearance getKeyboardAppearance() {
        return UIKeyboardAppearance.Default;
    }

    @Override
    public void setKeyboardAppearance(UIKeyboardAppearance v) {

    }

    @Override
    public UIReturnKeyType getReturnKeyType() {
        return null;
    }

    @Override
    public void setReturnKeyType(UIReturnKeyType v) {

    }

    @Override
    public boolean enablesReturnKeyAutomatically() {
        return false;
    }

    @Override
    public void setEnablesReturnKeyAutomatically(boolean v) {

    }

    @Override
    public boolean isSecureTextEntry() {
        return false;
    }

    @Override
    public void setSecureTextEntry(boolean v) {

    }

    @Override
    public UITextContentType getTextContentType() {
        return null;
    }

    @Override
    public void setTextContentType(UITextContentType v) {

    }

    @Override
    public UITextInputPasswordRules getPasswordRules() {
        return null;
    }

    @Override
    public void setPasswordRules(UITextInputPasswordRules v) {

    }
}
