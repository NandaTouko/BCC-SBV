import java.util.Scanner;

public class Bee1013 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    int a = input.nextInt();
    int b = input.nextInt();
    int c = input.nextInt();

    int maiorAB = (a + b + Math.abs(a - b)) / 2;

    System.out.println((maiorAB > c ? maiorAB : c) + " eh o maior");

    input.close();
  }
}
