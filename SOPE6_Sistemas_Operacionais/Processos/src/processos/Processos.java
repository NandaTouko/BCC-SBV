package processos;

import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author bv3024679
 */
public class Processos {
    public static void main(String[] args) throws IOException {
        if(args.length > 0) {
            Process processo = new ProcessBuilder(args[0]).start();
            System.out.println("PID args[0]: " + processo.pid());
        } else {
            System.out.println("PID do Programa: " + ProcessHandle.current().pid());
            Scanner scanner = new Scanner(System.in);
            scanner.nextLine();
        }
    }
}
