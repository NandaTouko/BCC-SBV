package exemplo01;

import exemplo00.Pessoa;

public class Professor extends Pessoa {
   private String formacao;
   
   public void setFormação(String formacao){
       // eh possivel acessar, pois tá com o extends
       nome = "João";
       this.formacao = formacao;
   }
}
