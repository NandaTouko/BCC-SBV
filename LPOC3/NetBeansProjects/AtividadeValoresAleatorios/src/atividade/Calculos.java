package atividade;

import java.util.Random;

public class Calculos {
    private double [] array = new double[10000];
    private double media;
    private double variancia;
    private double moda;
    private double mediana;
    
    public void gerarArrayAleatorio() {
        Random r = new Random(System.currentTimeMillis());
        
        for(int i = 0; i < array.length; i++){
            array[i] = r.nextDouble(1000.0);
        }
    }
    
    public double getValorPosicaoArray(int i){
        return array[i];
    }
    
    public void calcularMedia(){
        double soma = 0;
        
        for(int i = 0; i < array.length; i++){
            soma += array[i];
        }
        
        media = (soma/array.length);
    }
    
    public void calcularVariancia(){
        double soma = 0;
        
        for(int i = 0; i < array.length; i++){
            soma += (Math.pow((array[i] - media), 2));
        }
        
        variancia = (soma/array.length);
    }
    
    public void calcularModa(){
        for(int i = 0; i < array.length; i++){
            for(int j = 0; j < array.length; j++){
                if(array[i] == array[j]){
                    moda = array[i];
                    break;
                }
            }
        }
    }
    
    public void calcularMediana(){
        double chave;
        int i;
        
        for(int j = 1; j < array.length; j++){
           chave = array[j]; 
           
           i = j - 1;
           
           while(i >= 1 && array[i] > chave){
               array[i+1] = array[i];
               i = i - 1;
           }
           
           array[i+1] = chave;
        }
        
        if(array.length%2 == 0){
            mediana = ((array[4999]+array[5000])/2);
        }else{
            mediana = array[4999];
        }
    }
}
