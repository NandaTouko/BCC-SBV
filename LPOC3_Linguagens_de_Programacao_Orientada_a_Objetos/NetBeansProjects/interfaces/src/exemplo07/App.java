/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package exemplo07;

/**
 *
 * @author Bv3024679
 */
public class App {
    public static void main(String[] args) {
        Gato g = new Gato(7.5);
        Animal a = g;
        g.emitirSom();
        System.out.println(a.getPeso());
    }
}
