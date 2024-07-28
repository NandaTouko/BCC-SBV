import java.util.Scanner;

public class Bee1047 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    int hi = input.nextInt();
    int mi = input.nextInt();
    int hf = input.nextInt();
    int mf = input.nextInt();

    int sec_i = (hi * 3600) + (mi * 60);
    int sec_f = (hf * 3600) + (mf * 60);

    int dif = sec_i > sec_f ? (86400 - (sec_i - sec_f)) : (sec_i == sec_f ? 86400 : (sec_f - sec_i));

    int difH = dif / 3600;
    int difM = (dif % 3600) / 60;

    System.out.printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", difH, difM);

    input.close();
  }
}
