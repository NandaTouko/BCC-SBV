package comunicacao;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Servidor {
    private static final int PORTA = 8189;
    private static List<ThreadCliente> clientes = new ArrayList<>();
    
    public static void main(String[] args) {
        // Criando o servidor para olhar para a porta 8189
        try (ServerSocket ssServer = new ServerSocket(PORTA)) {            
            System.out.println("Aguardando conexao...");
            
            while (true) {
                // Fica escutando a porta até aparecer alguém para que aceite a conexão
                Socket sIncoming = ssServer.accept();
                System.out.println("Novo cliente conectado: " + sIncoming.getInetAddress().getHostAddress());

                // Cria uma nova thread para o cliente
                ThreadCliente clienteHandler = new ThreadCliente(sIncoming);
                clientes.add(clienteHandler);

                Thread thread = new Thread(clienteHandler);
                thread.start();
            }
        } catch (IOException ex) {
            System.out.println("Não foi possível iniciar o servidor.");
        }
    }
    
    public static void broadcast(String mensagem, ThreadCliente remetente) {
        for (ThreadCliente cliente : clientes) {
            if (cliente != remetente) {
                cliente.enviarMensagem(mensagem);
            }
        }
    }

    public static void removerCliente(ThreadCliente cliente) {
        clientes.remove(cliente);
    }
}
