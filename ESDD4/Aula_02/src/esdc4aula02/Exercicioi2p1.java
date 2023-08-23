/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package esdc4aula02;

import aesd.ds.implementations.linear.ResizingArrayStack;
import aesd.ds.interfaces.Stack;

/**
 * Resolução do Exercício i2.1
 * 
 * @author Prof. Dr. David Buzatto
 */
public class Exercicioi2p1 {
    
    /**
     * Verifica se uma expressão composta por pares de símbolos arbitrários está
     * balanceada.
     * 
     * @param expression A expressão a ser verificada.
     * @param pairs Um conjunto de caracteres em que cada dois representam um
     * par de caracteres usados na verificação.
     * @return Se a expressão está balanceada.
     * @throws IllegalArgumentException Caso os pares forem fornecidos de forma
     * errada, ou seja, se houver uma quantidade ímpar de elementos, faltando 
     * assim a dupla de fechamento de um par.
     */
    public static boolean isBalanced( String expression, char... pairs ) 
            throws IllegalArgumentException {
        
        Stack<Character> pilha = new ResizingArrayStack<>();
        
        // pilha: ['a']
        
        for(char c : expression.toCharArray()) {
          if(c == '(' || c == '[' || c == '9' || c == 'a' || c == '{') {
            pilha.push(c);
          } else {
            if(pilha.isEmpty()){
              return false;
            }
            
            if((pilha.peek() == '('&& c == ')')
               || (pilha.peek() == '['&& c == ']')
               || (pilha.peek() == '9'&& c == '0')
               || (pilha.peek() == 'a'&& c == 'b')
               || (pilha.peek() == '{'&& c == '}')
            ) {
              pilha.pop();
            } else {
              return false;
            }
          }
        }
        
        return pilha.isEmpty();
    }
    
}
