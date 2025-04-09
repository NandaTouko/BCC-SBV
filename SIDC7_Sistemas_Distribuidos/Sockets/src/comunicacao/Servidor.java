package comunicacao;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Servidor {
    public static void main(String[] args) {
        try {
            // Criando o servidor para olhar para a porta 8189
            ServerSocket ssServer = new ServerSocket(8189);
            
            System.out.println("Aguardando conexao...");            
            // Fica escutando a porta até aparecer alguém para que aceite a conexão
            Socket sIncoming = ssServer.accept();
            System.out.println("Chegou alguem...");
            
            // Preparar para receber dados do cliente
            InputStream inStream = sIncoming.getInputStream();
            Scanner in = new Scanner(inStream, StandardCharsets.UTF_8);
            
            // Preparar para enviar dados para o cliente
            OutputStream outStream = sIncoming.getOutputStream();
            PrintWriter out = new PrintWriter(outStream, true, StandardCharsets.UTF_8);
            
            // Loop de Comunicação
            boolean fim = false;
            
            // Envia ou recebe dados
            while (!fim && in.hasNextLine()) {
                // Consumir os dados do cliente
                String linha = in.nextLine();
                System.out.println("Cliente: " + linha);
                
                // Cliente mandou uma continha
                if (linha.matches("^\\d+[\\+\\-\\*/]\\d+$")) {
                    // Quebra antes e depois do operador
                    String[] partes = linha.split("(?<=[\\+\\-\\*/])|(?=[\\+\\-\\*/])");
                    int num1 = Integer.parseInt(partes[0]);
                    int num2 = Integer.parseInt(partes[2]);
                    int resultado = 0;
                    
                    switch (partes[1]) {
                        case "+":
                            resultado = num1 + num2;
                            break;
                        case "-":
                            resultado = num1 - num2;
                            break;
                        case "*":
                            resultado = num1 * num2;
                            break;
                        case "/":
                            resultado = num1 / num2;
                            break;
                    }
                    
                    out.println(resultado);
                } else if(linha.matches("^[^;]+;\\w+$")) {
                    String[] partes = linha.split(";");
                    String frase = partes[0].toLowerCase();
                    String palavra = partes[1].toLowerCase();
                    
                    int posicao = frase.indexOf(palavra);
                    if (posicao != -1) {
                        out.println("A palavra começa na posição: " + posicao);
                    } else {
                        out.println("A palavra não está presente na frase.");
                    }
                } else if (linha.equalsIgnoreCase("TCHAU")) {
                    // Fim da comunicação
                    fim = true;
                    out.println("Foi bom falar contigo.");
                } else {
                    out.println("Ok");
                }            
                
            }
            
            // Fechar a conexão
            sIncoming.close();
        } catch (IOException ex) {
            System.out.println("Não foi possível iniciar o servidor.");
        }
    }
}
