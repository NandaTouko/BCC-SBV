/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package exemplo07;

/**
 *
 * @author Bv3024679
 */
public abstract class Animal {
    //atributo
    private double peso;
    
    //construtor
    public Animal(double peso) {
        this.peso = peso;
    }
    
    //método concreto
    public double getPeso(){
        return peso;
    }
    
    //método abstrato
    public abstract void emitirSom();
}
