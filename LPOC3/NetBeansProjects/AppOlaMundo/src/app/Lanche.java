package app;

import java.util.Scanner;

/**
 * Exercício do Lanche com Switch
 * @author BV3024679
 */
public class Lanche {
    public static void main(String[] args){
        Scanner teclado = new Scanner(System.in);
        
        System.out.print("Código do Item: ");
        int codigo = teclado.nextInt();
        
        System.out.print("Quantidade: ");
        int quantidade = teclado.nextInt();
        
        double valor = 0;
        
        /*
            switch(codigo) {
                case 1 -> {
                    valor = quantidade * 4;
                    //segunda instrução
                };
                case 2 -> valor = quantidade * 4.5;
                case 3 -> valor = quantidade * 5;
                case 4 -> valor = quantidade * 2;
                case 5 -> valor = quantidade * 1.5;
            }
        */
        
        switch(codigo) {
            case 1:
                valor = quantidade * 4;
                break;
            case 2:
                valor = quantidade * 4.5;
                break;
            case 3:
                valor = quantidade * 5;
                break;
            case 4:
                valor = quantidade * 2;
                break;
            case 5:
                valor = quantidade * 1.5;
                break;
        }
        
        if(valor > 0){
            System.out.printf("Total: R$ %.2f \n", (valor));
        }else{
            System.out.println("O código digitado não possui um lanche correspondente.");
        }
    }
}
