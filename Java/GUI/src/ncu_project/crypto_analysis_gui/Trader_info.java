package ncu_project.crypto_analysis_gui;

import javafx.scene.control.Button;
import javafx.scene.image.Image;

public class Trader_info {
    public String ID = "";
    public static Image image;
    public String Name= "";
    public String PNL = "";
    public Button Load = new Button();

    public Trader_info(String id,String name,String pnl){
        ID = id;
        Name=name;
        PNL=pnl;
    }
}
