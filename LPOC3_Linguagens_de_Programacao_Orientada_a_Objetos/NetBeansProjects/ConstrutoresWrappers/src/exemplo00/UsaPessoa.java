package exemplo00;

public class UsaPessoa {
    public static void main(String [] args){
        Pessoa p = new Pessoa("Clóvis");
        Pessoa p2 = p; // não aloca outra posição na memória, assim aloca Pessoa p = new Pesssoa(p)
        
        System.out.println("p: " + p.getNome());
        System.out.println("p2: " + p2.getNome());
        System.out.println("p == p2? " + (p == p2));
    }
            
}
