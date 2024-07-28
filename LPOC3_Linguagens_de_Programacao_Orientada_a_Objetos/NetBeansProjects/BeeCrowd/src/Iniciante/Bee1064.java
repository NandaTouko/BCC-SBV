/*
 * https://www.beecrowd.com.br/judge/pt/problems/view/1064
 */
package Iniciante;

import java.util.Scanner;

/**
 * Exercício do BeeCrowd - Nível Iniciante - 1064
 * @author bv3024679
 */
public class Bee1064 {
    public static void main(String[] args){
        Scanner teclado = new Scanner(System.in);
        
        double valor;
        double soma = 0;
        int cont = 0;
        
        for(int i = 0; i < 6; i++){
            valor = teclado.nextDouble();
            
            if(valor > 0){
                soma += valor;
                cont++;
            }
        }
        
        System.out.printf("%d valores positivos\n", cont);
        System.out.printf("%.1f\n", (soma/cont));
    }
}
