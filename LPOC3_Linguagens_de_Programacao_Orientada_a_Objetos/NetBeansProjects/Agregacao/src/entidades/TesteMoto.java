package entidades;

public class TesteMoto {
    public static void main(String[] args) {
        Motor m1 = new Motor();
        Roda r1 = new Roda();
        Roda r2 = new Roda();
        Moto moto = new Moto();
        
        moto.setMotor(m1);
        moto.setRodaDianteira(r1);
        moto.setRodaTraseira(r2);
        
        moto.ligar();
    }
}
