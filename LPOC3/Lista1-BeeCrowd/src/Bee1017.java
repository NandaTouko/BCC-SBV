import java.util.Scanner;

public class Bee1017 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    int h = input.nextInt();
    int vm = input.nextInt();

    double mult = vm * h;
    double l = mult / 12;

    System.out.printf("%.3f\n", l);

    input.close();
  }
}
