package br.edu.ifsp.sbv.hellofxml;

import java.net.URL;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * JavaFX App
 */
public class App extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        URL url = getClass().getResource("PrimeiraTela.fxml");
        Parent raiz = FXMLLoader.load(url);
        
        Scene cena = new Scene(raiz);
        
        stage.setTitle("Batata");
        stage.setScene(cena);
        stage.show();
    }
    
    public static void main(String[] args) {
        launch();
    }
}