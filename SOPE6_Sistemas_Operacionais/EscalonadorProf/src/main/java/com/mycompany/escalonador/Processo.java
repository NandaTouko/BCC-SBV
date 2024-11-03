/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.escalonador;

import java.util.ArrayList;

/**
 *
 * @author bv205941
 */
public class Processo {
    private int ID;
    private ArrayList<Character> lista = new ArrayList();
    private int tempo;
    private int entrada;
    private String instrucoes;
    private int ponteiro=0;

    /**
     * @return the ID
     */
    public int getID() {
        return ID;
    }

    /**
     * @param ID the ID to set
     */
    public void setID(int ID) {
        this.ID = ID;
    }

    /**
     * @return the lista
     */
    public ArrayList<Character> getLista() {
        return lista;
    }

    /**
     * @param lista the lista to set
     */
    public void setLista(ArrayList<Character> lista) {
        this.lista = lista;
    }

    /**
     * @return the tempo
     */
    public int getTempo() {
        return tempo;
    }

    /**
     * @param tempo the tempo to set
     */
    public void setTempo(int tempo) {
        this.tempo = tempo;
    }

    /**
     * @return the entrada
     */
    public int getEntrada() {
        return entrada;
    }

    /**
     * @param entrada the entrada to set
     */
    public void setEntrada(int entrada) {
        this.entrada = entrada;
    }

    /**
     * @return the instrucoes
     */
    public String getInstrucoes() {
        return instrucoes;
    }

    /**
     * @param instrucoes the instrucoes to set
     */
    public void setInstrucoes(String instrucoes) {
        this.instrucoes = instrucoes;
    }

    /**
     * @return the ponteiro
     */
    public int getPonteiro() {
        return ponteiro;
    }

    /**
     * @param ponteiro the ponteiro to set
     */
    public void setPonteiro(int ponteiro) {
        this.ponteiro = ponteiro;
    }
    
    public Character proximo(){
        return lista.get(ponteiro++);
    }
    
    public boolean finalizou(){
        return ponteiro == lista.size();
    }
    
    public void inserirChar(Character X){
        lista.add(X);
    }
    
}
