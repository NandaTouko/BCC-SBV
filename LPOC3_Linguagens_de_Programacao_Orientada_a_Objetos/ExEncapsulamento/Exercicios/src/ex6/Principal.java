package ex6;

public class Principal {
	public static void main(String[] args) {
		Animal a = new Animal();

		a.setEspecie("Pitbull");
		a.setIdade(6);
		a.setPeso(10.6);

		System.out.print("Carlos é um " + a.getEspecie() + ", que tem " + a.getIdade() + " ano(s), ");
		System.out.println("e está " + (a.isPesoIdeal() ? "dentro" : "fora") + " do peso ideal!");
	}
}
