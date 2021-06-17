package my.jdbc_example.src;
import java.util.*;
import java.io.*;
import java.net.InetAddress;

public class networking{
    public static void main(String args[]) throws Exception{
        InetAddress Ip = InetAddress.getLocalHost();
        System.out.println("Ip of my system is := " + Ip.getHostAddress());
        System.out.println("Host Nme: - " + Ip.getHostName());
    }
}