import java.util.Scanner;

public class Bee1015 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    double p1_x = input.nextDouble();
    double p1_y = input.nextDouble();
    double p2_x = input.nextDouble();
    double p2_y = input.nextDouble();

    double distancia = Math.sqrt((Math.pow((p2_x - p1_x), 2) + Math.pow((p2_y - p1_y), 2)));

    System.out.printf("%.4f\n", distancia);

    input.close();
  }
}
