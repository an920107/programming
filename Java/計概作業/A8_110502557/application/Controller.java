package A8_110502557.application;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.Clipboard;
import javafx.scene.input.ClipboardContent;

public class Controller {

    @FXML private TextField inputTextField = new TextField();
    @FXML private TextField outputTextField = new TextField();
    @FXML private Button createButton;
    @FXML private Button saveButton;
    @FXML private Button encodeButton;
    @FXML private Button copyButton;
    @FXML private Button clearButton;
    @FXML private Label statusLabel = new Label();

    private Clipboard clipboard = Clipboard.getSystemClipboard();
    private ClipboardContent clipboardContent = new ClipboardContent();
    private File file = new File(Program.Information.FILENAME);

    public void onCreateButton(ActionEvent event) throws IOException {
        if (file.createNewFile())
            statusLabel.setText(Program.Status.CREATED);
        else statusLabel.setText(Program.Status.CREATE_FAILED);
    }

    public void onSaveButton(ActionEvent event) throws IOException {
        if (!file.exists())
            statusLabel.setText(Program.Status.SAVE_FAILED);
        else {
            FileWriter writer = new FileWriter(file);
            writer.write(outputTextField.getText());
            writer.close();
            statusLabel.setText(Program.Status.SAVED);
        }
    }

    public void onEncodeButton(ActionEvent event) {
        outputTextField.setText(Program.encode(inputTextField.getText()));
        statusLabel.setText(Program.Status.ENCODED);
    }

    public void onCopyButton(ActionEvent event) {
        final String OUTPUT = outputTextField.getText();
        if (OUTPUT == null || OUTPUT.length() == 0)
            statusLabel.setText(Program.Status.COPY_FAILED);
        else {
            clipboardContent.putString(OUTPUT);
            clipboard.setContent(clipboardContent);
            statusLabel.setText(Program.Status.COPIED);
        }
    }

    public void onClearButton(ActionEvent event) {
        inputTextField.setText(null);
        outputTextField.setText(null);
        statusLabel.setText(Program.Status.CLEARED);
    }
}
