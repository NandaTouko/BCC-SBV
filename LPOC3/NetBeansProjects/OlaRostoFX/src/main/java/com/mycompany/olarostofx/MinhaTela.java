package com.mycompany.olarostofx;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Arc;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;


/**
 * JavaFX App
 */
public class MinhaTela extends Application {

    @Override
    public void start(Stage stage) {
        // Cria o rosto
        Circle rosto = new Circle(125, 125, 80);
        rosto.setFill(Color.BISQUE);
        rosto.setStroke(Color.BROWN);
        
        // Cria o olho esquerdo
        Circle olhoEsquerdo = new Circle(86, 100, 10);
        olhoEsquerdo.setFill(Color.GREEN);
        olhoEsquerdo.setStroke(Color.WHITE);
        
        // Cria o olho direito
        Circle olhoDireito = new Circle(162, 100, 10);
        olhoDireito.setFill(Color.GREEN);
        olhoDireito.setStroke(Color.WHITE);
        
        // Cria a boca
        Arc boca = new Arc(125, 150, 45, 35, 0, -180);
        boca.setFill(Color.LIGHTSALMON);
        
        // Cria Texto
        Text texto = new Text(50, 240, "Olá, sou o Bob!");
        texto.setFill(Color.LIGHTCORAL);
        texto.setFont(Font.font("Verdana", 20));
        
        // container com os elementos do rosto
        Group raiz = new Group(rosto, olhoEsquerdo, olhoDireito, boca, texto);
        
        // configurar cena
        Scene cena = new Scene(raiz, 250, 320);
        
        // Prepara o stage
        stage.setScene(cena);
        stage.setTitle("Olá");
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}