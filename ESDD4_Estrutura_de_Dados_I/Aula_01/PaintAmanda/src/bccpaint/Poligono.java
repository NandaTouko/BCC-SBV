package bccpaint;

import java.awt.Graphics2D;
import java.awt.geom.Path2D;

public class Poligono extends Forma {

  private int qtdLados;

  public Poligono(int qtdLados) {
    this.qtdLados = qtdLados;
  }

  @Override
  public void desenhar(Graphics2D g2d) {
    g2d = (Graphics2D) g2d.create();
    
    double xP2 = xFim;
    double yP2 = yFim;
    double somarAngulo = (2 * Math.PI) / qtdLados;

    Path2D.Double poligono = new Path2D.Double();
    
    for(int i = 0; i < qtdLados; i++){
      poligono.moveTo( xP2, yP2 );
      
      double cA = xP2 - xIni;
      double cO = yP2 - yIni;
      double angulo = Math.atan2(cO, cA);
      double h = Math.hypot(cA, cO);
      
      xP2 = Math.cos(angulo + somarAngulo) * h;
      yP2 = Math.sin(angulo + somarAngulo) * h;
      poligono.lineTo( xP2, yP2 );
    }
    
    poligono.closePath();

    g2d.setColor( corPreenchimento );
    g2d.fill( poligono );

    g2d.setColor( corContorno );
    g2d.draw( poligono );
  }

}
