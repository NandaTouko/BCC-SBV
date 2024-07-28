package exemplo01;

public class Conta {
    private double saldo;
    
// 1. Sem tratamento nenhum 
//    public void depositar(double valor) {
//        saldo += valor;
//    }
    
// 2. Limita o tratamento, pois somente exibe no terminal
//    public void depositar(double valor) {
//        if(valor > 0){
//            saldo += valor;
//        } else {
//            System.out.println("Valor Inválido");
//        }
//    }
    
// 3. Trato a exceção com retorno boolean   
//    public boolean depositar(double valor) {
//        if(valor > 0){
//            saldo += valor;
//            return true;
//        } else {
//            return false;
//        }
//    }
    
// 4. Usa o tratamento de exceção    
    public void depositar(double valor) throws IllegalArgumentException {
        if(valor < 0){
            // sinaliza uma exceção
            throw new IllegalArgumentException("Valor do depósito não pode ser negativo");
        }
        
        saldo += saldo;
    }
    
    public double getSaldo() {
        return saldo;
    }
}
