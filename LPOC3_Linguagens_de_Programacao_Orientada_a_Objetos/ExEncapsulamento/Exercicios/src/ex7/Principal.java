package ex7;

public class Principal {
	public static void main(String[] args) {
		Circulo c = new Circulo();

		c.setRaio(4);

		System.out.print("Um círculo com raio " + c.getRaio() + " tem o perímetro ");
		System.out.printf("%.2f\n", c.calcPerimetro());
	}
}
