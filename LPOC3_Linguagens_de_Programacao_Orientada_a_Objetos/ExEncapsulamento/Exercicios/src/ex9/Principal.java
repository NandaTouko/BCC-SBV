package ex9;

public class Principal {
	public static void main(String[] args) {
		Funcionario f = new Funcionario();

		f.setNome("João Vitor");
		f.setCargo("Separador de Reciclagem");
		f.setSalario(200.50);

		System.out.println(f.getNome() + " trabalha como " + f.getCargo() + " e ganha R$" + f.getSalario());
		System.out.println("Com o reajuste seu salário foi para R$" + f.reajustarSalario(20));
	}
}
