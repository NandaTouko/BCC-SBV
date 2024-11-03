package algoritmos;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

/*
    Amanda Moreira (BV3024679)
    Giovana Naiara Silva (BV3025063)
    João Vitor Ribeiro Maciel (BV3015505)
*/

public class SJForFCFS {

    private String nomeArquivo = "D:\\nanda\\Repositórios\\Meus\\BCC-SBV\\SOPE6_Sistemas_Operacionais\\AlgoritmosEscalonamento\\src\\algoritmos\\processos.txt";

    private ArrayList<Processo> tarefaPronta = new ArrayList();
    private ArrayList<Processo> tarefaNova = new ArrayList();
    private ArrayList<Processo> tarefaFinalizada = new ArrayList();
    private Processo processoAtual = null;

    private int tempoTotal = 0;

    private int idProcesso = 0;

    public void lerArquivo() {
        String[] linhas = new String[4];

        try {
            BufferedReader arquivo = new BufferedReader(new FileReader(nomeArquivo));

            linhas[0] = arquivo.readLine();
            linhas[1] = arquivo.readLine();
            linhas[2] = arquivo.readLine();
            linhas[3] = arquivo.readLine();

            arquivo.close();
        } catch (IOException ex) {
            ex.getStackTrace();
        }

        // Carga de Processos Para Cada Linha
        for (int i = 0; i < 4; i++) {
            Processo p = new Processo();
            int entrada = Integer.parseInt(linhas[i].substring(0, 3));
            p.setEntrada(entrada);
            p.setID(++idProcesso);
            p.setInstrucoes(linhas[i].substring(3));

            for (int j = 3; j < linhas[i].length(); j++) {
                p.inserirChar(linhas[i].charAt(j));
            }

            tarefaNova.add(p);
        }
    }

    public void executarEscalonamento(String SJForFCFS) {
        while (true) {
            if (processoAtual != null) {
                Character c = processoAtual.proximo();
                System.out.println("Processo no processador: " + processoAtual.getID() + " / Instrução: " + c);
                processador(c);

                if (processoAtual.finalizou()) {
                    tarefaFinalizada.add(processoAtual);
                    int tempoEspera = tempoTotal - processoAtual.getTempo() - processoAtual.getEntrada();
                    System.out.println("Processo Finalizado: " + processoAtual.getID() 
                                        + " / Tempo de Execução: " + processoAtual.getTempo()
                                        + " / Tempo de Espera: " + tempoEspera
                                        + " / Entradas e saídas do processador: 1");
                    processoAtual = null;
                }
            }

            // Verificar lista de tarefas novas
            // Caso exista tarefa no tempo de entrar para pronta            
            if (!tarefaNova.isEmpty()) {
                Processo p = tarefaNova.get(0);
                if (p.getEntrada() <= tempoTotal) {
                    System.out.println("Processo na lista Pronta: " + p.getID() + " / Instruções: " + p.getInstrucoes());
                    tarefaPronta.add(p);
                    tarefaNova.remove(0);
                }
            }

            // Se não há processo atual, escolhe o próximo processo baseado no SJF
            if (processoAtual == null) {
                if (!tarefaPronta.isEmpty()) {
                    // Ordenar a lista de tarefas prontas pelo tempo de execução
                    if(SJForFCFS.equals("SJF")) {
                        Collections.sort(tarefaPronta, (Processo p1, Processo p2) -> Integer.compare(p1.getTempoExecucao(), p2.getTempoExecucao()));
                    }                    
                    processoAtual = tarefaPronta.remove(0);
                } else if (tarefaNova.isEmpty()) {
                    System.out.println("Tempo Atual: " + tempoTotal);
                    break;
                } else {
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    tempoTotal += 1;
                }
            }

            System.out.println("Tempo Atual: " + tempoTotal);
        }
    }

    public void processador(Character c) {
        try {
            switch (c) {
                case 'A':
                    Thread.sleep(5000);
                    tempoTotal += 5;
                    processoAtual.setTempo(processoAtual.getTempo() + 5);
                    break;
                case 'B':
                    Thread.sleep(7000);
                    tempoTotal += 7;
                    processoAtual.setTempo(processoAtual.getTempo() + 7);
                    break;
                case 'C':
                    Thread.sleep(9000);
                    tempoTotal += 9;
                    processoAtual.setTempo(processoAtual.getTempo() + 9);
                    break;
                case 'D':
                    Thread.sleep(10000);
                    tempoTotal += 10;
                    processoAtual.setTempo(processoAtual.getTempo() + 10);
                    break;
                default:
                    break;
            }
        } catch (InterruptedException e) {
            e.getStackTrace();
        }

    }

    public static void main(String[] args) {
        SJForFCFS fcfs = new SJForFCFS();
        fcfs.lerArquivo();
        
        System.out.println("--- Escalonamento FCFS ---");
        fcfs.executarEscalonamento("FCFS");
        
        System.out.println("--- Escalonamento SJF ---");
        SJForFCFS sjf = new SJForFCFS();
        sjf.lerArquivo();
        sjf.executarEscalonamento("SJF");
    }
}
