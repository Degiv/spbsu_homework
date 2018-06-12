package sample;

import javafx.fxml.FXML;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.Slider;
import javafx.scene.text.Text;

public class Controller {
    @FXML
    private ProgressBar progressBar;
    @FXML
    private Slider slider;

    /**
     * actions when slider's toggle drags
     */
    public void initialize() {
        slider.valueProperty().addListener((observable, oldValue, newValue) -> progressBar.progressProperty().setValue((double)newValue / 100));
    }
}