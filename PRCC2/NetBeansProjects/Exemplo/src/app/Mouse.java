package app; // a classe Mouse está dentro do pacote app

public class Mouse { // seria uma struct em C
    // atributos da classe
    String cor;
    int posicaoX;
    int posicaoY;
    
    // comportamentos - Em C não teria isso
    void mover(int deltaX, int deltaY){ // se chama método, pq está dentro da classe
        posicaoX = posicaoX + deltaX;
        posicaoY += deltaY;
    }
    
    void atribuirCor(String c){
        cor = c;
    }
    
    String qualSuaCor(){
        return cor;
    }
    
    String qualSuaPosicao(){
        return "(" + posicaoX + ", " + posicaoY + ")";
    }
}
