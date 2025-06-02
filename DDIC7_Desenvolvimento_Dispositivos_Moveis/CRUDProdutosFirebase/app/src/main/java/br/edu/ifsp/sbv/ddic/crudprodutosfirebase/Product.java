package br.edu.ifsp.sbv.ddic.crudprodutosfirebase;

public class Product {
    private String key;
    private String description;
    private double value;

    public Product(String description, double value, String key) {
        this.description = description;
        this.value = value;
        this.key = key;
    }

    public Product() {}

    public String getKey() {
        return key;
    }

    public void setKey(String key) {
        this.key = key;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }
}
