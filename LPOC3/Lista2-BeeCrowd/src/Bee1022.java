import java.util.Scanner;

public class Bee1022 {
	// mdc seguindo o teorema de Euclides
	public static int mdc(int a, int b) {
		int resto = a % b;

		if (resto == 0) {
			return b;
		} else {
			return mdc(b, resto);
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int numOperacoes = input.nextInt();
		int n1, d1, n2, d2, nf = 0, df = 0, f;
		char op;

		while (numOperacoes != 0) {
			// Fração 1
			n1 = input.nextInt();
			input.next();
			d1 = input.nextInt();

			// Operador
			op = input.next().charAt(0);

			// Fração 2
			n2 = input.nextInt();
			input.next();
			d2 = input.nextInt();

			if (op == '+') {
				nf = (n1 * d2) + (n2 * d1);
				df = d1 * d2;
			} else if (op == '-') {
				nf = (n1 * d2) - (n2 * d1);
				df = d1 * d2;
			} else if (op == '*') {
				nf = n1 * n2;
				df = d1 * d2;
			} else if (op == '/') {
				nf = n1 * d2;
				df = d1 * n2;
			}

			f = Math.abs(mdc(nf, df));
			System.out.println(nf + "/" + df + " = " + (nf / f) + "/" + (df / f));

			numOperacoes--;
		}

		input.close();
	}
}
