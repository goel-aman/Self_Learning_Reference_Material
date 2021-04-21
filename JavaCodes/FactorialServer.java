import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;
public class FactorialServer {
    public static void main(String[] args) throws Exception{
        System.out.println("Waiting for clients");
        ServerSocket ss = new ServerSocket(9806);
        Socket soc = ss.accept();
        System.out.println("Connection Established");
        BufferedReader in = new BufferedReader(new InputStreamReader(soc.getInputStream()));
        int number = Integer.parseInt(in.readLine());
        PrintWriter out = new PrintWriter(soc.getOutputStream(),true);
        out.println("Factorial of " + number + " is : " + calculateFactorial(number));

    }
    
    static int calculateFactorial(int number){
        int fact = 1;
        for(int i = 1;i<=number;i++){
            fact = fact * i;
        }
        return fact;
    }
}
