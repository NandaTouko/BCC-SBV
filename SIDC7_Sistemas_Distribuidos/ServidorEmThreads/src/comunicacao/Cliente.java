package comunicacao;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Cliente {
    public static void main(String[] args) {
        try {
            Socket sClient = new Socket("127.0.0.1", 8189);

            // Preparar para receber dados do servidor
            BufferedReader in = new BufferedReader(new InputStreamReader(sClient.getInputStream(), 
                    StandardCharsets.UTF_8));

            // Preparar para enviar dados para o servidor
            PrintWriter out = new PrintWriter(new OutputStreamWriter(sClient.getOutputStream(),
                    StandardCharsets.UTF_8), true);

            // Scanner para entrada do teclado
            Scanner teclado = new Scanner(System.in);

            // Thread para receber mensagens do servidor
            Thread threadRecebeMensagens = new Thread(() -> {
                try {
                    String linha;
                    while ((linha = in.readLine()) != null) {
                        System.out.println(linha); // Imprime a mensagem recebida
                    }
                } catch (IOException e) {
                    System.out.println("Conexão com o servidor foi encerrada.");
                }
            });

            threadRecebeMensagens.start(); // Inicia a thread de recebimento

            // Enviar mensagens ao servidor
            System.out.println("Digite mensagens para o chat. Escreva 'TCHAU' para sair.");
            boolean fim = false;
            while (!fim) {
                String mensagem = teclado.nextLine();
                out.println(mensagem);

                // Encerra se o cliente digitar 'TCHAU'
                if (mensagem.equalsIgnoreCase("TCHAU")) {
                    fim = true;
                }
            }

            // Fecha a conexão
            sClient.close();
        } catch (IOException ex) {
            System.out.println("Não foi possivel conectar no servidor.");
        }
        
    }
}
