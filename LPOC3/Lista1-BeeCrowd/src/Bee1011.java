import java.util.Scanner;

public class Bee1011 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    double raio = input.nextDouble();
    double pi = 3.14159;

    double volume = (4.0 / 3) * pi * (raio * raio * raio);

    System.out.printf("VOLUME = %.3f\n", volume);

    input.close();
  }
}
