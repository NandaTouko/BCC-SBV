package exemplo03;

public class Repositor extends Funcionario {
    private String setor;
    
    public Repositor(String nome, String cpf){
        super(nome, cpf);
    }
    
    public void setSetor(String setor){
        this.setor = setor;
    }
    
    public String getSetor(){
        return setor;
    }
}
