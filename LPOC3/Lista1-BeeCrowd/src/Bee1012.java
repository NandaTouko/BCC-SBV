import java.util.Scanner;

public class Bee1012 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    double a = input.nextDouble();
    double b = input.nextDouble();
    double c = input.nextDouble();
    double pi = 3.14159;

    System.out.printf("TRIANGULO: %.3f\n", ((a * c) / 2));
    System.out.printf("CIRCULO: %.3f\n", (pi * (c * c)));
    System.out.printf("TRAPEZIO: %.3f\n", (((a + b) * c) / 2));
    System.out.printf("QUADRADO: %.3f\n", (b * b));
    System.out.printf("RETANGULO: %.3f\n", (a * b));

    input.close();
  }
}
