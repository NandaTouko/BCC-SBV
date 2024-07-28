package entidades;

/**
 * @author BV3024679
 */
public class TesteAluno {
    public static void main(String[] args){
        Aluno a = new Aluno();
        
        a.alterarNome("Márcio Cunha");
        a.alterarIdade(20);
        
        System.out.println("Nome: " + a.qualSeuNome());
        System.out.println("Idade: " + a.qualSuaIdade());
    }
}
