import java.net.*;

// import jdk.internal.org.jline.utils.InputStreamReader;

import java.io.*;
public class echoClient {
    public static void main(String[] args) throws Exception
    {

        System.out.println("Client Started .....");
        Socket soc = new Socket("localhost",9806);
        BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter a string : ");
        String str = userInput.readLine();
        PrintWriter out = new PrintWriter(soc.getOutputStream(),true);
        out.println(str);
        
        BufferedReader in = new BufferedReader(new InputStreamReader(soc.getInputStream()));
        System.out.println(in.readLine());
    }
}
