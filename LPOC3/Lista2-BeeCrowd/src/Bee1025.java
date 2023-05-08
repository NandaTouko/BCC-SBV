import java.util.ArrayList;
import java.util.Scanner;

public class Bee1025 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int qtdMarmore = input.nextInt();
		int qtdConsultas = input.nextInt();
		int cont = 0;
		int peca = 0;
		int valorConsultado = 0;

		while ((qtdMarmore > 0 && qtdMarmore < 10000) && (qtdConsultas > 0 && qtdConsultas < 10000) && cont < 65) {
			ArrayList<Integer> numInscritos = new ArrayList<Integer>();

			for (int i = 0; i < qtdMarmore; i++) {
				peca = input.nextInt();

				if (peca > 0 && peca < 10000) {
					numInscritos.add(peca);
				}
			}

			for (int i = 0; i < qtdConsultas; i++) {
				valorConsultado = input.nextInt();

				if (valorConsultado > 0 && valorConsultado < 10000) {
					if (numInscritos.contains(valorConsultado)) {
						System.out.println(valorConsultado + " found at " + numInscritos.lastIndexOf(valorConsultado));
					} else {
						System.out.println(valorConsultado + " not found ");
					}
				}
			}

			qtdMarmore = input.nextInt();
			qtdConsultas = input.nextInt();
			cont++;
		}

		input.close();
	}
}
