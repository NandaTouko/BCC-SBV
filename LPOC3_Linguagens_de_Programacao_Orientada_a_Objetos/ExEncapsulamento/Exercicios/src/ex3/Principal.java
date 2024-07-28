package ex3;

public class Principal {
    public static void main(String[] args) {
        Retangulo r = new Retangulo();

        r.setComprimento(52.8);
        r.setLargura(24.8);

        System.out.println("Área: " + r.getComprimento() + " x " + r.getLargura() + " = " + r.calcularArea());
    }
}
