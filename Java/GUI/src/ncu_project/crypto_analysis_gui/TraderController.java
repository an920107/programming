package ncu_project.crypto_analysis_gui;

import javafx.animation.AnimationTimer;
import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressIndicator;
import javafx.scene.image.Image;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.ImagePattern;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.web.HTMLEditor;

import java.util.ArrayList;

public class TraderController implements Initializable{
    @FXML
    Button back;
    @FXML
    Label name;
    @FXML
    Label pnl;
    @FXML
    Circle image;
    @FXML
    Button currency1;
    @FXML
    Button currency2;
    @FXML
    Button currency3;
    @FXML
    Button currency4;
    @FXML
    Line line1;
    @FXML
    Line line2;
    @FXML
    Line line3;
    @FXML
    Line line4;
    @FXML
    HTMLEditor chart;
    @FXML
    Label l_name;
    @FXML
    Label l_pnl;
    @FXML
    Label l_pair;
    @FXML
    Rectangle block;
    @FXML
    ProgressIndicator loading_animate;
    @FXML
    AnchorPane no_data_msg;
    @FXML
    Label waring1;
    @FXML
    Label waring2;

    static String name_src="NA";
    static String pnl_src="NA";
    static String image_src="NA";
    static String id_src = "";

    private AnimationTimer timer= new AnimationTimer() {
        int count;
        @Override
        public void handle(long l) {
            count++;
        }

        @Override
        public void start() {
            block.setVisible(true);
            loading_animate.setVisible(true);
            count=0;
            super.start();
        }

        @Override
        public void stop() {
            block.setVisible(false);
            loading_animate.setVisible(false);
            if(!Loading_trader_sync.html.equals(""))    chart.setHtmlText(Loading_trader_sync.html);
            else{
                no_data_msg.setVisible(true);
                block.setVisible(true);
            }
            Loading_trader_sync.html="";
            super.stop();
        }
    };

    @FXML
    private void backMenu(ActionEvent e){
        SceneController.show(SceneController.Scenes.MENU,true);
        chart.setHtmlText("<body style='background-color: black;'/>");
    }

    @FXML
    private void set1chart(ActionEvent ee){
        currency1.setOpacity(1);    line1.setVisible(true);
        currency2.setOpacity(0.5);  line2.setVisible(false);
        currency3.setOpacity(0.5);  line3.setVisible(false);
        currency4.setOpacity(0.5);  line4.setVisible(false);

        Loading_trader_sync.request_id_pair=id_src+'-'+currency1.getText();
        Task<Void> task = new Loading_trader_sync();
        Thread thread = new Thread(task);
        timer.start();
        //sync_load
        thread.setDaemon(true);
        thread.start();
        task.setOnSucceeded(e -> {
            timer.stop();
        });
    }

    @FXML
    private void set2chart(ActionEvent ee){
        currency1.setOpacity(0.5);  line1.setVisible(false);
        currency2.setOpacity(1);    line2.setVisible(true);
        currency3.setOpacity(0.5);  line3.setVisible(false);
        currency4.setOpacity(0.5);  line4.setVisible(false);

        Loading_trader_sync.request_id_pair=id_src+'-'+currency2.getText();
        Task<Void> task = new Loading_trader_sync();
        Thread thread = new Thread(task);
        timer.start();
        //sync_load
        thread.setDaemon(true);
        thread.start();
        task.setOnSucceeded(e -> {
            timer.stop();
        });
    }
    @FXML
    private void set3chart(ActionEvent ee){
        currency1.setOpacity(0.5);  line1.setVisible(false);
        currency2.setOpacity(0.5);  line2.setVisible(false);
        currency3.setOpacity(1);    line3.setVisible(true);
        currency4.setOpacity(0.5);  line4.setVisible(false);

        Loading_trader_sync.request_id_pair=id_src+'-'+currency3.getText();
        try {
            Task<Void> task = new Loading_trader_sync();
            Thread thread = new Thread(task);
            timer.start();
            //sync_load
            thread.setDaemon(true);
            thread.start();
            task.setOnSucceeded(e -> {
                timer.stop();
            });
        }catch (Exception e){
            no_data_msg.setVisible(true);
            block.setVisible(true);
        }
    }
    @FXML
    private void set4chart(ActionEvent ee){
        currency1.setOpacity(0.5);  line1.setVisible(false);
        currency2.setOpacity(0.5);  line2.setVisible(false);
        currency3.setOpacity(0.5);  line3.setVisible(false);
        currency4.setOpacity(1);    line4.setVisible(true);

        Loading_trader_sync.request_id_pair=id_src+'-'+currency4.getText();
        Task<Void> task = new Loading_trader_sync();
        Thread thread = new Thread(task);
        timer.start();
        //sync_load
        thread.setDaemon(true);
        thread.start();
        task.setOnSucceeded(e -> {
            timer.stop();
        });
    }
    static ArrayList<String> coin =new ArrayList<>();


    public void local_initialize(){
        no_data_msg.setVisible(false);
        block.setVisible(false);

        if(MenuController.LanState==0){
            l_name.setText("名稱");
            l_pnl.setText("收益率");
            l_pair.setText("交易幣種");
            waring1.setText("目前沒有該交易員數據");
            waring2.setText("請稍後嘗試");
        }
        else if(MenuController.LanState==1){
            l_name.setText("Name");
            l_pnl.setText("PNL");
            l_pair.setText("Currency");
            waring1.setText("No Data Currently");
            waring2.setText("please try again later");
        }

        currency1.setVisible(true);
        currency2.setVisible(true);
        currency3.setVisible(true);
        currency4.setVisible(true);
        line1.setVisible(false);
        line2.setVisible(false);
        line3.setVisible(false);
        line4.setVisible(false);
        currency1.setOpacity(0.5);
        currency2.setOpacity(0.5);
        currency3.setOpacity(0.5);
        currency4.setOpacity(0.5);

        image.setFill(new ImagePattern(new Image(image_src)));
        name.setText(name_src);
        pnl.setText(pnl_src);
        if(pnl_src.charAt(0)!='-')        pnl.setStyle("-fx-text-fill: #25a69a; -fx-alignment:center;");
        else                              pnl.setStyle("-fx-text-fill: #ee534f; -fx-alignment:center;");

        boolean loadingSceed = true;
        try{
            currency1.setText(coin.get(0));
            try{
                currency2.setText(coin.get(1));
                try{
                    currency3.setText(coin.get(2));
                    try{
                        currency4.setText(coin.get(3));
                    }catch (Exception e){
                        currency4.setVisible(false);
                    }
                }catch (Exception e) {
                    currency3.setVisible(false);
                    currency4.setVisible(false);
                }
            }catch (Exception e){
                currency2.setVisible(false);
                currency3.setVisible(false);
                currency4.setVisible(false);
            }
        }catch (Exception e){
            currency1.setVisible(false);
            currency2.setVisible(false);
            currency3.setVisible(false);
            currency4.setVisible(false);

            no_data_msg.setVisible(true);
            block.setVisible(true);
            loadingSceed=false;
        }
        if(loadingSceed)    set1chart(new ActionEvent());
    }
}
