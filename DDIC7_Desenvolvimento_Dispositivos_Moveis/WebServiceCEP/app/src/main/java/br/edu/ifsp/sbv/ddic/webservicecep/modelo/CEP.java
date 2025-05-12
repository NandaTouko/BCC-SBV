package br.edu.ifsp.sbv.ddic.webservicecep.modelo;

import org.json.JSONException;
import org.json.JSONObject;

public class CEP {
    private String cep;
    private String logradouro;
    private String bairro;
    private String cidade;
    private String uf;
    private String estado;

    public CEP(){}

    public CEP(JSONObject json) throws JSONException {
        this.cep = json.getString("cep");
        this.logradouro = json.getString("logradouro");
        this.bairro = json.getString("bairro");
        this.cidade = json.getString("localidade");
        this.uf = json.getString("uf");
        this.estado = json.getString("estado");
    }

    public String getCep() {
        return cep;
    }

    public String getLogradouro() {
        return logradouro;
    }

    public String getBairro() {
        return bairro;
    }

    public String getCidade() {
        return cidade;
    }

    public String getUf() {
        return uf;
    }

    public String getEstado() {
        return estado;
    }
}
