/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package app;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author bv3024679
 */
public class Eficiencia {
    public static void main(String[] args) throws FileNotFoundException{
        File arquivo = new File("C:\\Users\\bv3024679\\Downloads\\microdados_eficiencia_academica_2022\\2021 - Eficiência Acadêmica.csv");
        System.out.println(arquivo.isFile());
        Scanner leitor = new Scanner(arquivo);
        
        while(leitor.hasNext()){
            System.out.println(leitor.nextLine());
        }
    }
}
