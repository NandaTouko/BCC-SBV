package ex1;

public class Principal {
    public static void main(String[] args){
        Pessoa p = new Pessoa();
        
        p.setIdade(20);
        p.setNome("Amanda");
        p.setTelefone("(16)99608-9808");
        
        System.out.println("Contato: " + p.getNome() + ", " + p.getIdade() + " ano(s), " + p.getTelefone());
    }
}
