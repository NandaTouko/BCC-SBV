package exemplo03;

public class TesteInterface {
    public static void main(String [] args){
        Gato g = new Gato();
        Cachorro c = new Cachorro();
        Radio r = new Radio();
        
        Som [] barulhentos =  new Som[3];
        
        barulhentos[0] = g;
        barulhentos[1] = c;
        barulhentos[2] = r;
        
        for(Som b: barulhentos) {
            b.emitirSom();
        }
    }
}
