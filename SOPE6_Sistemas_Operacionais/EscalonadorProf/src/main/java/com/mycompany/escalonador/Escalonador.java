/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.escalonador;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author bv205941
 */
public class Escalonador {
    private String nomeArquivo = "D:\\nanda\\Repositórios\\Meus\\BCC-SBV\\SOPE6_Sistemas_Operacionais\\AlgoritmosEscalonamento\\src\\algoritmos\\processos.txt";
    
    private ArrayList<Processo> tarefaPronta = new ArrayList();
    private ArrayList<Processo> tarefaNova = new ArrayList();
    private ArrayList<Processo> tarefaFinalizada = new ArrayList();
    private Processo processoAtual = null;
    
    private int tempoTotal=0;
    private int tempoQuantum=0;
    private int quantum=6;
    
    private int idProcesso=0;
    
    public void lerArquivo(){
        String linha1 = "";
        String linha2 = "";
        String linha3 = "";
        String linha4 = "";
            
        try{
            BufferedReader arquivo = new BufferedReader(new FileReader(nomeArquivo));
            
            linha1 = arquivo.readLine();
            linha2 = arquivo.readLine();
            linha3 = arquivo.readLine();
            linha4 = arquivo.readLine();
            
            arquivo.close();
        }
        catch(IOException ex)
        {
            ex.getStackTrace();
        }
        
        
        //Iniciando carga Processo 1
        Processo p = new Processo();
        int entrada= Integer.parseInt(linha1.substring(0,3));
        int numInt = linha1.length() - 3;
        p.setEntrada(entrada);
        p.setID(++idProcesso);
        p.setInstrucoes(linha1.substring(3));
        
        for (int i=3;i<linha1.length();i++){
            p.inserirChar(linha1.charAt(i));
        }
        
        tarefaNova.add(p);
        
        //Iniciando carga Processo 2
        p = new Processo();
        entrada= Integer.parseInt(linha2.substring(0,3));
        numInt = linha2.length() - 3;
        p.setEntrada(entrada);
        p.setID(++idProcesso);
        p.setInstrucoes(linha2.substring(3));
        
        for (int i=3;i<linha2.length();i++){
            p.inserirChar(linha2.charAt(i));
        }
        
        tarefaNova.add(p);
        
        //Iniciando carga Processo 3
        p = new Processo();
        entrada= Integer.parseInt(linha3.substring(0,3));
        numInt = linha3.length() - 3;
        p.setEntrada(entrada);
        p.setID(++idProcesso);
        p.setInstrucoes(linha3.substring(3));
        
        for (int i=3;i<linha3.length();i++){
            p.inserirChar(linha3.charAt(i));
        }
        
        tarefaNova.add(p);
        
        //Iniciando carga Processo 4
        p = new Processo();
        entrada= Integer.parseInt(linha4.substring(0,3));
        numInt = linha4.length() - 3;
        p.setEntrada(entrada);
        p.setID(++idProcesso);
        p.setInstrucoes(linha4.substring(3));
        
        for (int i=3;i<linha4.length();i++){
            p.inserirChar(linha4.charAt(i));
        }
        
        tarefaNova.add(p);
    }
    
    public void executarEscalonamento(){
        while(true){
            if(processoAtual != null){
                Character c = processoAtual.proximo();
                System.out.println("Processo no processador: " + processoAtual.getID() + " / Instrução: " + c);
                processador(c);
                
                if (processoAtual.finalizou()){
                    tarefaFinalizada.add(processoAtual);
                    tempoQuantum = 0;
                    System.out.println("Processo Finalizado: " + processoAtual.getID() + " / Tempo Total: " + processoAtual.getTempo());
                    processoAtual = null;
                }
            }
            
            //Verificar lista tarefa novas
            //Caso exista tarefa no tempo de entrar para pronta            
            if(!tarefaNova.isEmpty()){
                Processo p = tarefaNova.get(0);
                if(p.getEntrada() <= tempoTotal)
                {
                    System.out.println("Processo na lista Pronta: " + p.getID() + " / Instruções: " + p.getInstrucoes());
                    tarefaPronta.add(tarefaPronta.size(),p);
                    tarefaNova.remove(0);
                }
            }
            
            //Verificar se o processo Atual vai sair do processador
            if(processoAtual != null){
                if(!tarefaPronta.isEmpty()){
                    if(tempoQuantum>quantum)
                    {
                        System.out.println("Processo saindo do processador/quantum: " + processoAtual.getID() + " / Tempo Total: " + processoAtual.getTempo());
                        tarefaPronta.add(tarefaPronta.size(), processoAtual);
                        processoAtual = tarefaPronta.remove(0);
                        tempoQuantum = 0;
                    }
                }
            }
            else
            {
                if(!tarefaPronta.isEmpty()){
                    processoAtual = tarefaPronta.remove(0);
                    tempoQuantum = 0;
                }
                else if (tarefaNova.isEmpty())
                {
                    System.out.println("Tempo Atual: " + tempoTotal);
                    break;
                }
                else
                {
                    try{
                        Thread.sleep(1000);
                    }catch(InterruptedException e){
                        e.getStackTrace();
                    }
                    tempoTotal += 1;                    
                }
            }
            
            System.out.println("Tempo Atual: " + tempoTotal);
        }        
    }
    
    public void processador(Character c){
        try{
        switch(c){
            case 'A': Thread.sleep(5000); 
            tempoTotal+=5; 
            tempoQuantum +=5; 
            processoAtual.setTempo(processoAtual.getTempo()+5);
            break;
            case 'B': Thread.sleep(7000); 
            tempoTotal+=7; 
            tempoQuantum +=7; 
            processoAtual.setTempo(processoAtual.getTempo()+7);
            break;
            case 'C': Thread.sleep(9000); 
            tempoTotal+=9; 
            tempoQuantum +=9; 
            processoAtual.setTempo(processoAtual.getTempo()+9);
            break;
            case 'D': Thread.sleep(10000); 
            tempoTotal+=10; 
            tempoQuantum +=10; 
            processoAtual.setTempo(processoAtual.getTempo()+10);
            break;
            default: break;
        }
        }catch(InterruptedException e){
            e.getStackTrace();
        }
            
    }
    
    public static void main(String[] args) {
        Escalonador es = new Escalonador();
        es.lerArquivo();
        es.executarEscalonamento();
    }
}
