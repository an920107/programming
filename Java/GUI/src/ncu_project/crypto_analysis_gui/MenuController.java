package ncu_project.crypto_analysis_gui;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.event.ActionEvent;
import javafx.scene.image.Image;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.ImagePattern;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;

import java.util.ArrayList;
import java.util.List;

public class MenuController implements Initializable {
    @FXML
    AnchorPane MainFrame;
    @FXML
    Button current;
    @FXML
    Button history;
    @FXML
    Line current_line;
    @FXML
    Line history_line;
    @FXML
    ListView<AnchorPane> traders;
    @FXML
    AnchorPane settingpane;
    @FXML
    Rectangle block;
    @FXML
    ChoiceBox<String> language;
    @FXML
    ChoiceBox<String> theme;
    @FXML
    Label l_language;
    @FXML
    Label l_theme;
    @FXML
    Label l_name;
    @FXML
    Label l_pnl;
    @FXML
    TextField search_bar;
    @FXML
    Label aboutus;
    @FXML
    Label l_aboutus_info;
    @FXML
    Label l_chart_doc;
    @FXML
    Label l_chart_info;

    static String search_name="";
    public  List<AnchorPane> list_generate(int AllorTop) {
        ArrayList<Trader>[] trader_info = new ArrayList[3];
        try {
            trader_info = new ArrayList[]{MySQL.getTraders(), MySQL.getTop(),MySQL.getTraders(search_name)};
        } catch (Exception e) {
            e.printStackTrace();
        }
        traders.setMinHeight(trader_info[AllorTop].size()*60+5);

        String name_src;
        String PNL_src;
        String image_src;
        String id_src;

        List<AnchorPane> current_list = new ArrayList<>();
        for (Trader i : trader_info[AllorTop]) {
            name_src = i.getName();
            PNL_src = Double.toString(i.getProfit()) + '%';
            image_src = String.valueOf(i.getPhoto());
            id_src  = String.valueOf(i.getID());

            Label name = new Label(name_src);
            name.setMinWidth(200);
            name.setStyle("-fx-text-fill:white;-fx-alignment:center;");

            Label PNL = new Label(PNL_src);
            PNL.setMinWidth(200);
            if (PNL_src.charAt(0) != '-') PNL.setStyle("-fx-text-fill: #25a69a; -fx-alignment:center;");
            else PNL.setStyle("-fx-text-fill: #ee534f; -fx-alignment:center;");

            Image image = new Image(image_src);
            //ImageView photo = new ImageView(image);
            //photo.setFitHeight(40);
            //photo.setFitWidth(40);
            Circle roundimg = new Circle(10, 10, 20);
            roundimg.setFill(new ImagePattern(image));

            Button check = new Button("🔍");
            check.setStyle("-fx-background-color:#317a81; -fx-background-radius:6px; -fx-text-fill: white; -fx-padding:1 15 1 15; -fx-font-size: 14px");
            String finalName_src = name_src;
            String finalImage_src = image_src;
            String finalPNL_src = PNL_src;
            String finalId_src = id_src;
            check.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent actionEvent) {
                    //todo
                    TraderController.image_src = finalImage_src;
                    TraderController.name_src = finalName_src;
                    TraderController.pnl_src = finalPNL_src;
                    TraderController.id_src = finalId_src;
                    TraderController temp = new TraderController();
                    TraderController.coin = i.getPairs();
                    SceneController.show(SceneController.Scenes.TRADER, true);

                }
            });

            Line dressed_line = new Line(411.0f, 10.0f, 10.0f, 10.0f);
            dressed_line.setStyle("-fx-stroke:white;");
            dressed_line.setOpacity(0.5);


            AnchorPane info = new AnchorPane();
            info.getChildren().add(roundimg);
            info.getChildren().add(name);
            info.getChildren().add(PNL);
            info.getChildren().add(check);
            info.getChildren().add(dressed_line);
            AnchorPane.setTopAnchor(roundimg, 5.0);
            AnchorPane.setLeftAnchor(roundimg, 20.0);

            AnchorPane.setTopAnchor(name, 15.0);
            AnchorPane.setLeftAnchor(name, 37.7);

            AnchorPane.setTopAnchor(PNL, 15.0);
            AnchorPane.setLeftAnchor(PNL, 167.0);

            AnchorPane.setTopAnchor(check, 13.5);
            AnchorPane.setLeftAnchor(check, 345.0);

            AnchorPane.setTopAnchor(dressed_line, 53.0);
            AnchorPane.setLeftAnchor(dressed_line, 10.0);
            info.setStyle("-fx-background-color: #303030;-fx-border-color:#303030;");

            current_list.add(info);
        }
        //ObservableList<HBox> trader_list = FXCollections.observableArrayList(info_list);
        return current_list;
    }

    @FXML
    private void setCurrent(ActionEvent e){
        search_name="";
        search_bar.setText("");
        traders.getItems().clear();
        current.setOpacity(1.0);
        history.setOpacity(0.5);
        current_line.setVisible(true);
        history_line.setVisible(false);
        buttonState =1;

        traders.getItems().addAll(list_generate(1));
    }

    @FXML
    private void setHistory(ActionEvent e){
        search_name="";
        search_bar.setText("");
        traders.getItems().clear();
        current.setOpacity(0.5);
        history.setOpacity(1.0);
        current_line.setVisible(false);
        history_line.setVisible(true);
        buttonState=0;

        traders.getItems().addAll(list_generate(0));
    }

    @FXML
    private void setting_list(ActionEvent e) {
        if (!block.isVisible()) {
            block.setVisible(true);
            settingpane.setVisible(true);
        } else {
            block.setVisible(false);
            settingpane.setVisible(false);
        }
    }
    @FXML
    private void changeLanguage(ActionEvent e){
        ChoiceBox<String> language = this.language;
        Button current = this.current;
        Button history = this.history;
        Label l_language = this.l_language;
        Label l_theme =this.l_theme;
        Label l_name = this.l_name;
        Label l_pnl = this.l_pnl;
        TextField search_bar = this.search_bar;
        Label aboutus = this.aboutus;
        Label l_aboutus_info = this.l_aboutus_info;

        if(language.getSelectionModel().getSelectedItem().equals("中文")){
            current.setText("當前最佳");
            history.setText("歷史上榜");
            l_language.setText("語言");
            l_theme.setText("主題");
            search_bar.setPromptText("搜尋交易員");
            l_name.setText("名稱");
            l_pnl.setText("收益率");
            aboutus.setText("關於我們");
            l_aboutus_info.setText("    開發團隊:\n      Squid,\n      Jason,\nCheung4843,\n     Warner");
            l_chart_doc.setText("圖表文件");
            l_chart_info.setText("三角形: 開倉,\n  圓形  : 平倉,\n  藍色  : 多倉操作,\n  粉色  : 空倉操作,\n半透明: 虧損操作");
            LanState=0;
        }else{
            current.setText(" Current");
            history.setText(" History");
            l_language.setText("Language");
            l_theme.setText("Theme");
            search_bar.setPromptText("Search for traders");
            l_name.setText("Name");
            l_pnl.setText("PNL");
            aboutus.setText("AboutUs");
            l_aboutus_info.setText("Development Team:\n\t  Squid,\n\t  Jason,\n    Cheung4843,\n\t Warner");
            l_chart_doc.setText("Chart Doc");
            l_chart_info.setText("triangle: open,\n   circle  : close,\n    blue   : long,\n    pink   : short,\n  ghost  : loss_order");
            LanState=1;
        }

    }

    @FXML
    private void getSearchName(ActionEvent e){
        if(!search_bar.getText().equals("")) {
            System.out.println(search_bar.getText());
            search_name = search_bar.getText();
            traders.getItems().clear();
            traders.getItems().addAll(list_generate(2));
            search_name ="";

            current.setOpacity(0.5);
            history.setOpacity(0.5);
            current_line.setVisible(false);
            history_line.setVisible(false);
        }
    }

    static int buttonState=1;
    static int LanState=0;

    public void local_initialize() {
        //setting choice box
        //CloseButton closeButton = new CloseButton();
        //MainFrame.getChildren().add(closeButton);

        if(buttonState==1) {
            current.setOpacity(1.0);
            history.setOpacity(0.5);
            current_line.setVisible(true);
            history_line.setVisible(false);
        }else if(buttonState == 0){
            current.setOpacity(0.5);
            history.setOpacity(1);
            current_line.setVisible(false);
            history_line.setVisible(true);
        }
        if(language.getItems().size()==0) {
            language.getItems().add("中文");
            language.getItems().add("English");
            theme.getItems().add("JaStyle");
            theme.getItems().add("nothing change");
        }
        language.getSelectionModel().select(LanState);
        theme.getSelectionModel().select(0);
        changeLanguage(new ActionEvent());

        if(traders.getItems().size()!=0) traders.getItems().clear();
        traders.getItems().addAll(list_generate(buttonState));
    }



}
