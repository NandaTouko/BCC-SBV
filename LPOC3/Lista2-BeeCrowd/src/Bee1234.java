import java.util.Scanner;

public class Bee1234 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		while (input.hasNextLine()) {
			boolean upper = true;
			StringBuilder frase = new StringBuilder(input.nextLine());

			for (int i = 0; i < frase.length(); i++) {
				char letra = frase.charAt(i);

				if (Character.isAlphabetic(letra)) {
					if (upper) {
						frase.setCharAt(i, Character.toUpperCase(letra));
						upper = false;
					} else {
						frase.setCharAt(i, Character.toLowerCase(letra));
						upper = true;
					}
				}
			}

			System.out.println(frase);
		}

		input.close();
	}
}
