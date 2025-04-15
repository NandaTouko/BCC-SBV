package comunicacao;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class ThreadCliente implements Runnable {
    private Socket socket;
    private PrintWriter out;
    private String nome;

    public ThreadCliente(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream(), StandardCharsets.UTF_8))) {
            out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream(), StandardCharsets.UTF_8), true);

            // Identifica o cliente pelo nome
            out.println("Digite seu nome:");
            nome = in.readLine();
            System.out.println(nome + " entrou no chat!");

            String mensagem;
            while ((mensagem = in.readLine()) != null) {
                String mensagemFormatada = nome + ": " + mensagem;
                System.out.println(mensagemFormatada);
                Servidor.broadcast(mensagemFormatada, this);
            }
        } catch (IOException e) {
            System.out.println("Conexão com o cliente encerrada.");
        } finally {
            try {
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            Servidor.removerCliente(this);
        }
    }

    public void enviarMensagem(String mensagem) {
        if (out != null) {
            out.println(mensagem);
        }
    }
}
