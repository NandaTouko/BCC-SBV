/*
 * https://www.beecrowd.com.br/judge/pt/problems/view/1067
 */
package Iniciante;

import java.util.Scanner;

/**
 * Exercício do BeeCrowd - Nível Iniciante - 1067
 * @author bv3024679
 */
public class Bee1067 {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        
        System.out.print("Digite o valor de X (1 <= X <= 1000): ");
        int x = teclado.nextInt();
        
        if(1 <= x && x <= 1000){
            for(int i = 1; i <= x; i++){
                if(i%2 != 0){
                    System.out.printf("%d\n", i);
                }
            }
        } else {
            System.out.println("X tem que ser entre 1 e 1000");
        }
    }
} 
