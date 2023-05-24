import java.util.Scanner;

public class Bee1024 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int testes = input.nextInt();
		input.nextLine();

		while (testes != 0) {
			char[] caracteres = input.nextLine().toCharArray();
			char[] cod1Caracteres = new char[caracteres.length];
			int numASCII;

			for (int i = 0; i < caracteres.length; i++) {
				if (Character.isAlphabetic(caracteres[i])) {
					numASCII = (int) caracteres[i];
					caracteres[i] = (char) (numASCII += 3);
				}

				cod1Caracteres[caracteres.length - (i + 1)] = caracteres[i];
			}

			int metade = caracteres.length / 2;

			for (int i = metade; i < caracteres.length; i++) {
				numASCII = (int) cod1Caracteres[i];
				cod1Caracteres[i] = (char) (numASCII -= 1);
			}

			System.out.println(String.copyValueOf(cod1Caracteres));

			testes--;
		}

		input.close();
	}
}
