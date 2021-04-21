import java.net.ServerSocket;
import java.net.Socket;

public class echoServer {
    public static void main(String[] args) throws Exception{
        System.out.println("Waiting for the client .... ");
        ServerSocket ss = new ServerSocket(9806);
        Socket soc = ss.accept();
        System.out.println("Connection Established. ... . . .");
    }
}
