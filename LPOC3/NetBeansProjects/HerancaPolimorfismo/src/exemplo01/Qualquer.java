package exemplo01;

import exemplo00.Aluno;

public class Qualquer {
    public static void main(String [] args){
        Aluno a2 = new Aluno("BV23", 6);
        
        // não acessa nome, pois esta em outro
        // pacote, mesmo sendo protected
        
        //a2.nome;
    }
}
