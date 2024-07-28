package app;

/**
 * @author BV3024679
 */
public class Teste {
    public static void main(String [] args){
        Aluno aluno1 = new Aluno();
        Aluno aluno2 = new Aluno();
        Professor professor = new Professor();
        
        aluno1.nome = "Adilson";
        aluno1.bv = "BV3018741";
        
        aluno2.nome = "João Vitor";
        aluno2.bv = "BV3015505";
        
        professor.nome = "Gabriel";
        professor.disciplina = "PROO";
        
        aluno1.assistirAula(professor);
        aluno2.assistirAula(professor);
    }
}
