package app;

import java.util.Scanner;

/**
 * Exercício do Lanche com IF
 * @author BV3024679
 */
public class LancheComIF {
    public static void main(String[] args){
        Scanner teclado = new Scanner(System.in);
        
        System.out.print("Código do Item: ");
        int codigo = teclado.nextInt();
        
        System.out.print("Quantidade: ");
        int quantidade = teclado.nextInt();
        
        double valor = 0;
        
        if(codigo == 1){
            valor = quantidade * 4;
        } else if(codigo == 2){
            valor = quantidade * 4.5;
        } else if(codigo == 3){
            valor = quantidade * 5;
        } else if(codigo == 4){
            valor = quantidade * 2;
        } else if(codigo == 5){
            valor = quantidade * 1.5;
        }
        
        if(valor > 0){
            System.out.printf("Total: R$ %.2f \n", (valor));
        }else{
            System.out.println("O código digitado não possui um lanche correspondente.");
        }
    }
}
