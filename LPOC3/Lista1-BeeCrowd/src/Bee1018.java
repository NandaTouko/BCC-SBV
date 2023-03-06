import java.util.Scanner;

public class Bee1018 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    int money = input.nextInt();

    System.out.printf("%d\n", money);

    if (money > 0 && money < 1000000) {
      System.out.println((money / 100) + " nota(s) de R$ 100,00");
      int resto = money % 100;

      System.out.println((resto / 50) + " nota(s) de R$ 50,00");
      resto %= 50;

      System.out.println((resto / 20) + " nota(s) de R$ 20,00");
      resto %= 20;

      System.out.println((resto / 10) + " nota(s) de R$ 10,00");
      resto %= 10;

      System.out.println((resto / 5) + " nota(s) de R$ 5,00");
      resto %= 5;

      System.out.println((resto / 2) + " nota(s) de R$ 2,00");
      resto %= 2;

      System.out.println((resto / 1) + " nota(s) de R$ 1,00");
    }

    input.close();
  }
}
