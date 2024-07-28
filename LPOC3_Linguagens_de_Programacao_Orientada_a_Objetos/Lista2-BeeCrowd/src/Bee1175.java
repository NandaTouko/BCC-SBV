import java.util.Scanner;

public class Bee1175 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int[] nInicial = new int[20];
		int[] nFinal = new int[20];
		int cont = 19;

		for (int i = 0; i < 20; i++) {
			nInicial[i] = input.nextInt();
		}

		for (int i = 0; i < 20; i++) {
			nFinal[i] = nInicial[cont];
			cont--;
		}

		for (int i = 0; i < 20; i++) {
			System.out.println("N[" + i + "] = " + nFinal[i]);
		}

		input.close();
	}
}
