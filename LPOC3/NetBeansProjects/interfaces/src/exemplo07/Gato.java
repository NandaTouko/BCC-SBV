/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package exemplo07;

/**
 *
 * @author Bv3024679
 */
public class Gato extends Animal {

    public Gato(double peso) {
        super(peso);
    }

    @Override
    public void emitirSom() {
        System.out.println("Miau");
    }
    
}
