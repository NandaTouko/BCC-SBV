import java.util.Scanner;

public class Bee1010 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    int code1 = input.nextInt();
    int qtd1 = input.nextInt();
    double value1 = input.nextDouble();
    int code2 = input.nextInt();
    int qtd2 = input.nextInt();
    double value2 = input.nextDouble();

    double totalValue = (qtd1 * value1) + (qtd2 * value2);

    System.out.printf("VALOR A PAGAR: R$ %.2f\n", totalValue);

    input.close();
  }
}
