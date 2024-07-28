package exemplo00;

public class Aluno extends Pessoa {
    private String registroAcademico;
    private double indiceDeRendimentoAcademico;
    
    public Aluno(String RA, double IRA){
        registroAcademico = RA;
        indiceDeRendimentoAcademico = IRA;
    }
    
    public Aluno(String nome){
        // chama o construtor não-padrão da classe mãe
        super(nome);
        indiceDeRendimentoAcademico = 7;
    }
    
    public double getIRA(){
        return indiceDeRendimentoAcademico;
    }
    
    public String getRA(){
        return registroAcademico;
    }
    
    public void atualizarIRA() {
        // código de processamento
    }
}
