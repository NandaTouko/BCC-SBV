import java.util.Scanner;

public class Bee1040 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    double n1 = input.nextDouble();
    double n2 = input.nextDouble();
    double n3 = input.nextDouble();
    double n4 = input.nextDouble();

    double media = (n1 * 0.2) + (n2 * 0.3) + (n3 * 0.4) + (n4 * 0.1);

    System.out.println("Media: " + (Math.floor(media * 10) / 10));

    if (media >= 7) {
      System.out.println("Aluno aprovado.");
    } else if (media <= 6.9 && media >= 5) {
      System.out.println("Aluno em exame.");
      double exame = input.nextDouble();

      System.out.printf("Nota do exame: %.1f\n", exame);
      media = (media + exame) / 2;

      if (media >= 5) {
        System.out.println("Aluno aprovado.");
      } else {
        System.out.println("Aluno reprovado.");
      }

      System.out.printf("Media final: %.1f\n", media);
    } else {
      System.out.println("Aluno reprovado.");
    }

    input.close();
  }
}
