import java.util.Scanner;

public class Bee1022 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int numOperacoes = input.nextInt();

		int[] numerador = new int[numOperacoes];
		String[] barra = new String[numOperacoes];
		int[] denominador = new int[numOperacoes];
		String[] operador = new String[numOperacoes];
		int[] numerador1 = new int[numOperacoes];
		String[] barra1 = new String[numOperacoes];
		int[] denominador1 = new int[numOperacoes];
		int[] numeradorF = new int[numOperacoes];
		int[] denominadorF = new int[numOperacoes];

		for (int i = 0; i < numOperacoes; i++) {
			numerador[i] = input.nextInt();
			barra[i] = input.next();
			denominador[i] = input.nextInt();
			operador[i] = input.next();
			numerador1[i] = input.nextInt();
			barra1[i] = input.next();
			denominador1[i] = input.nextInt();
		}

		for (int i = 0; i < numOperacoes; i++) {
			if (operador[i].equals("+") || operador[i].equals("-")) {
				denominadorF[i] = denominador[i] * denominador1[i];
				numeradorF[i] = (numerador[i] * (denominadorF[i] / denominador[i]));

				if (operador[i].equals("+")) {
					numeradorF[i] += (numerador1[i] * (denominadorF[i] / denominador1[i]));
				} else {
					numeradorF[i] -= (numerador1[i] * (denominadorF[i] / denominador1[i]));
				}
			} else if (operador[i].equals("*")) {
				numeradorF[i] = numerador[i] * numerador1[i];
				denominadorF[i] = denominador[i] * denominador1[i];
			} else if (operador[i].equals("/")) {
				numeradorF[i] = numerador[i] * denominador1[i];
				denominadorF[i] = denominador[i] * numerador1[i];
			}
		}

		for (int i = 0; i < numOperacoes; i++) {
			System.out.print(numeradorF[i] + "/" + denominadorF[i] + " = ");

			while ((numeradorF[i] % 2 == 0) && (denominadorF[i] % 2 == 0)) {
				numeradorF[i] = numeradorF[i] / 2;
				denominadorF[i] = denominadorF[i] / 2;
			}

			while ((numeradorF[i] % 3 == 0) && (denominadorF[i] % 3 == 0)) {
				numeradorF[i] = numeradorF[i] / 3;
				denominadorF[i] = denominadorF[i] / 3;
			}

			System.out.println(numeradorF[i] + "/" + denominadorF[i]);
		}

		input.close();
	}
}
