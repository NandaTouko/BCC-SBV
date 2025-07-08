package br.edu.ifsp.sbv.ddic.projetofinal.modelo;

import com.google.gson.annotations.SerializedName;

public class Receita {
    @SerializedName("idMeal")
    private String id;

    @SerializedName("strMeal")
    private String nome;

    @SerializedName("strInstructions")
    private String modoPreparo;

    @SerializedName("strMealThumb")
    private String imagem;

    @SerializedName("strCategory")
    private String categoria;

    public String getId() { return id; }
    public void setId(String id) { this.id = id; }

    public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; }

    public String getModoPreparo() { return modoPreparo; }
    public void setModoPreparo(String modoPreparo) { this.modoPreparo = modoPreparo; }

    public String getImagem() { return imagem; }
    public void setImagem(String imagem) { this.imagem = imagem; }

    public String getCategoria() { return categoria; }
    public void setCategoria(String categoria) { this.categoria = categoria; }
}
