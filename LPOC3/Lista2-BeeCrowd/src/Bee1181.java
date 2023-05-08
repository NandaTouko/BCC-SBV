import java.util.Scanner;

public class Bee1181 {
	public static final int TAM_MATRIZ = 12;

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double[][] M = new double[TAM_MATRIZ][TAM_MATRIZ];

		int numLinha = input.nextInt();
		String somaOuMedia = input.next();
		double soma = 0;

		for (int i = 0; i < TAM_MATRIZ; i++) {
			for (int j = 0; j < TAM_MATRIZ; j++) {
				M[i][j] = input.nextDouble();

				if (i == numLinha) {
					soma += M[i][j];
				}
			}
		}

		if (somaOuMedia.equals("S")) {
			System.out.printf("%.1f\n", soma);
		} else if (somaOuMedia.equals("M")) {
			System.out.printf("%.1f\n", (soma / TAM_MATRIZ));
		}

		input.close();
	}
}