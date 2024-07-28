package ex4;

public class Principal {
    public static void main(String[] args){
        Carro c = new Carro();
        
        c.setMarca("Fiat");
        c.setModelo("Uno");
        c.setAnoFabricacao(2000);
        
        System.out.println(c.getMarca() + " " + c.getModelo() + "(" + c.getAnoFabricacao() + ")" + " tem " + c.idadeCarro() + " ano(s)");
    }
}
