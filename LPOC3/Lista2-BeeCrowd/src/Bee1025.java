import java.util.Arrays;
import java.util.Scanner;

public class Bee1025 {
	public static int buscaBinaria(int busca, int[] array, int inicio, int fim) {
		int meio = (inicio + fim) / 2;

		if (inicio >= fim) {
			return -1; // Não encontrado
		}

		if (array[meio] == busca) {
			return meio;
		} else {
			if (array[meio] < busca) {
				return buscaBinaria(busca, array, (meio + 1), fim);
			} else {
				return buscaBinaria(busca, array, inicio, (meio - 1));
			}
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int qtdMarmore, qtdConsultas, cont = 1;

		do {
			qtdMarmore = input.nextInt();
			qtdConsultas = input.nextInt();
			int[] marmores = new int[qtdMarmore];

			for (int i = 0; i < qtdMarmore; i++) {
				marmores[i] = input.nextInt();
			}

			Arrays.sort(marmores);

			if (qtdConsultas != 0) {
				System.out.printf("CASE# %d:\n", cont);
			}

			for (int i = 0; i < qtdConsultas; i++) {
				int consulta = input.nextInt();

				int resposta = buscaBinaria(consulta, marmores, 0, marmores.length);

				if (resposta == -1) {
					System.out.printf("%d not found\n", consulta);
				} else {
					System.out.printf("%d found at %d\n", consulta, (resposta + 1));
				}
			}

			cont++;

		} while ((qtdMarmore > 0 && qtdMarmore <= 10000) && (qtdConsultas > 0 && qtdConsultas <= 10000) && cont <= 65);

		input.close();
	}
}
