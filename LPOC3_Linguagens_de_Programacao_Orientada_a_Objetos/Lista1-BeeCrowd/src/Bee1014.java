import java.util.Scanner;

public class Bee1014 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    int km = input.nextInt();
    double l = input.nextDouble();

    System.out.printf("%.3f km/l\n", (km / l));

    input.close();
  }
}
