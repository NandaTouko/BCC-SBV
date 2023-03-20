package exemplo00;

public class UsaMatematica {
    public static void main(String[] args){
        Matematica m = new Matematica();
        int[] array = {1, 2, 3, 4, 5};
        
        System.out.println(m.somar(2, 3));
        System.out.println(m.somar(2, 3, 4));
        System.out.println(m.somar(array));
        System.out.println(Math.addExact(2,3));
        
        // Solucao Alternativa
        // m.somar(2, m.somar(3, 4));
    }
}
