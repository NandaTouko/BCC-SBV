package ex8;

public class Principal {
	public static void main(String[] args) {
		Telefone tel = new Telefone();

		tel.setCodArea(16);
		tel.setNumero("996089808");
		tel.setTipo("Celular");

		System.out.println("Seu " + tel.getTipo() + " é: (" + tel.getCodArea() + ")" + tel.getNumero());
		System.out.println("Ele é " + (tel.isNumeroValido() ? "válido!" : "inválido!"));
	}
}
