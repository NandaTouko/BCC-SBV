import java.util.Scanner;

public class Bee1020 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    int idade = input.nextInt();

    int anos = idade / 365;
    int meses = (idade % 365) / 30;
    int dias = (idade % 365) % 30;

    System.out.println(anos + " ano(s)");
    System.out.println(meses + " mes(es)");
    System.out.println(dias + " dia(s)");

    input.close();
  }
}
