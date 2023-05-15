/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/javafx/FXMLController.java to edit this template
 */
package br.edu.ifsp.sbv.gui;

import br.edu.ifsp.sbv.hellofxml.App;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author sp070142
 */
public class PrimeiraTelaController implements Initializable {
    
    @FXML
    private AnchorPane rootPane;
    
    @FXML
    private ImageView imgViewLuffy;
    
    @FXML
    private Button buttonOk;
        
    @FXML
    public void exibir() throws IOException {
        System.out.println("Clicou");
        URL url = App.class.getResource("SegundaTela.fxml");
        FXMLLoader fxml = new FXMLLoader(url);
        Parent raiz = fxml.load();
        
        // converte a janela da cena atual para stage
        Stage stage = (Stage) rootPane.getScene().getWindow();
        stage.setScene(new Scene(raiz));
        stage.setTitle("Segunda Tela");
        stage.show();
    }
    

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
