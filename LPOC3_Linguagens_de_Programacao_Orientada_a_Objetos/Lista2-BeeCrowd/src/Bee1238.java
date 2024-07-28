import java.io.IOException;
import java.util.Scanner;

public class Bee1238 {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		int linhas = Integer.parseInt(input.nextLine());

		String palavra1;
		String palavra2;

		for (int i = 0; i < linhas; i++) {
			var linha = input.nextLine().split(" ");

			try {
				palavra1 = linha[0];
			} catch (Exception e) {
				palavra1 = "";
			}

			try {
				palavra2 = linha[1];
			} catch (Exception e) {
				palavra2 = "";
			}

			combinar(palavra1, palavra2);
		}

		input.close();
	}

	private static void combinar(String p1, String p2) {
		String combinacao = "";

		for (int i = 0; i < p1.length(); i++) {
			try {
				combinacao += String.valueOf(p1.charAt(i)) + String.valueOf(p2.charAt(i));
			} catch (Exception e) {
				combinacao += String.valueOf(p1.charAt(i));
			}
		}

		if (p2.length() > p1.length()) {
			int qtde = p2.length() - p1.length();

			for (int i = p2.length() - qtde; i < p2.length(); i++) {
				combinacao += String.valueOf(p2.charAt(i));
			}
		}
		System.out.println(combinacao);
	}
}