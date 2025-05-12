package br.edu.ifsp.sbv.exemplowebservices2025.modelo;

import org.json.JSONException;
import org.json.JSONObject;

public class Pokemon {

    private String nome;
    private String image;
    private int altura;
    private int peso;

    public Pokemon(JSONObject json) throws JSONException {
        this.nome = json.getString("name");
        this.altura = json.getInt("height");
        this.peso = json.getInt("weight");
        this.image = json.getJSONObject("sprites").getString("front_default");
    }

    public Pokemon() {

    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public int getAltura() {
        return altura;
    }

    public void setAltura(int altura) {
        this.altura = altura;
    }

    public int getPeso() {
        return peso;
    }

    public void setPeso(int peso) {
        this.peso = peso;
    }
}
