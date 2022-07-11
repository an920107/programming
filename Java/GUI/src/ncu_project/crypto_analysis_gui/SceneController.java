package ncu_project.crypto_analysis_gui;

import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.fxml.LoadException;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.stage.Stage;

import java.io.IOException;

public class SceneController {

        public enum Scenes {
            MENU(new FXMLLoader(SceneController.class.getResource("/resources/Menu.fxml"))),
            LOADING(new FXMLLoader(SceneController.class.getResource("/resources/LoadingScene.fxml"))),
            TRADER(new FXMLLoader(SceneController.class.getResource("/resources/Trader.fxml")));

            private FXMLLoader loader;
            private Scene scene;
            private Object controller;

            Scenes(FXMLLoader loader) {
                this.loader = loader;
                try {
                    this.scene = new Scene((Parent)loader.load());
                    this.controller = loader.getController();
                } catch (IOException exception) {
                    exception.printStackTrace();
                }
            }

            private Scene getScene() { return scene; }
            private Object getController() { return controller; }

            private void reload() {
                try {
                    this.scene = new Scene((Parent)loader.load());
                } catch (LoadException exception) {
                    // Do nothing
                } catch (IOException exception) {
                    exception.printStackTrace();
                }
            }
        }



        public static Stage stage;

        public static void show(Scenes loader, boolean newLoad) {
            if (newLoad) reload(loader);

            stage.setScene(loader.getScene());
            stage.show();

            if (newLoad) {
                loader.getScene().setOnKeyPressed(new EventHandler<KeyEvent>() {
                    @Override
                    public void handle(KeyEvent event) {
                        if (loader.getController() instanceof KeyPressed)
                            ((KeyPressed)loader.getController()).keyPressed(event);
                    }
                });

                if (loader.getController() instanceof Initializable)
                    ((Initializable)loader.getController()).local_initialize();
            }
            else {
                if (loader.getController() instanceof Pausable)
                    ((Pausable)loader.getController()).resume();
            }
        }

        public static void reload(Scenes loader) {
            loader.reload();
        }

        public static Object getController(Scenes loader) {
            return loader.getController();
        }
    }

