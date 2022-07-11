package ncu_project.crypto_analysis_gui;

import javafx.animation.AnimationTimer;
import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ProgressBar;

public class LoadingScene implements Initializable {
    @FXML
    private void enterMenu(ActionEvent e){
        SceneController.show(SceneController.Scenes.MENU,true);
    }

    @FXML
    ProgressBar bar;
    @FXML
    Button startButton;



    private AnimationTimer timer= new AnimationTimer() {
        int count;
        @Override
        public void handle(long l) {

            if(count == 60){
                bar.setProgress(0.75);
            }else if(count == 240) {
                bar.setProgress(1);
            }else if(300<count) {
                bar.setOpacity(1-count%100/100f);
            }
            count++;
        }

        @Override
        public void start() {
            count=0;
            bar.setProgress(0.0);
            startButton.setVisible(false);
            super.start();
        }

        @Override
        public void stop() {
            bar.setVisible(false);
            startButton.setVisible(true);
            super.stop();
        }
    };

    @Override
    public void local_initialize() {

        timer.start();
        Task<Void> task = new Loading_sync();
        Thread thread = new Thread(task);
        timer.start();
        //sync_load
        thread.setDaemon(true);
        thread.start();
        task.setOnSucceeded(e->{ timer.stop();});
    }

}
