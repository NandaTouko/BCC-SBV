package comunicacao;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Cliente {
    public static void main(String[] args) {
        try {
            Socket sClient = new Socket("127.0.0.1", 8189);
        
            // Preparar para receber dados dos servidor
            InputStream inStream = sClient.getInputStream();
            Scanner in = new Scanner(inStream, StandardCharsets.UTF_8);
            
            // Preparar para enviar dados para o servidor
            OutputStream outStream = sClient.getOutputStream();
            PrintWriter out = new PrintWriter(outStream, true, StandardCharsets.UTF_8);
            
            // Loop de Comunicação
            Scanner teclado = new Scanner(System.in);
            boolean fim = false;
            
            while(!fim) {
                System.out.print("Digite: ");
                String mensagem = teclado.nextLine();
                
                // Enviar a mensagem para o servidor
                out.println(mensagem);
                
                if (in.hasNextLine()) {
                    String linha = in.nextLine();
                    fim = linha.equalsIgnoreCase("Foi bom falar contigo.");
                    
                    System.out.println("Servidor: " + linha);
                }
            }
            
            // Fechar a conexão
            sClient.close();
        } catch (IOException ex) {
            System.out.println("Não foi possivel conectar no servidor.");
        }
        
    }
}
