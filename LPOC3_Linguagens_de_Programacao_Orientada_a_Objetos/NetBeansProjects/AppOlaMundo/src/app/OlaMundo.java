package app;

import java.util.Scanner;

/**
 * Classe de exemplo de utilização do Java
 * @author bv3024679
 */
public class OlaMundo {
    public static void main(String[] args){
        Scanner teclado = new Scanner(System.in);
        System.out.print("Qual o seu nome? ");
        String nome = teclado.nextLine();
        System.out.println("Olá, " + nome + "! Seja bem-vindo(a).");
        
        System.out.print("Em qual ano nasceu? ");
        int ano = teclado.nextInt();
        
        if(ano > 1900 && ano < 2023){
            int idade = 2023 - ano;
            System.out.println("Você tem " + idade + " anos!");
        }else{
            System.out.println("Você forneceu um ano que não está no intervalo de 1900 à 2023!");
        }
    }
}
