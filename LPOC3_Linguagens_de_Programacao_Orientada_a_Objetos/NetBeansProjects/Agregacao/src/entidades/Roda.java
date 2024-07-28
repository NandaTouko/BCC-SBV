package entidades;

/**
 * @author bv3024679
 */
public class Roda {
    private String material;
    private double diametro;
    private String marca;
    
    // Métodos para alterar valores
    public void setMaterial(String material) {
        this.material = material;
    }
    
    public void setDiametro(double d) {
        diametro = d;
    }
    
    public void setMarca(String marca) {
        this.marca = marca;
    }
    
    // Métodos para ler valores
    public String getMaterial() {
        return material;
    }
    
    public double getDiametro() {
        return diametro;
    }
    
    public String getMarca() {
        return marca;
    }
    
    // Ações
    public void girar(){
        System.out.println("Roda girando...");
    }
}
