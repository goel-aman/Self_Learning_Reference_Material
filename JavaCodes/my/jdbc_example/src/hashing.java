package my.jdbc_example.src;
import java.util.*;

// Synchronized implementation of Hashing

public class hashing {
    public static void main(String args[]) throws Exception{
        Hashtable<Integer,String> ht = new Hashtable<Integer,String>();
        ht.put(1,"Welcome");
        ht.put(12," to ");
        ht.put(15," FACE ");
        ht.put(3," Prep ");
        System.out.println(ht);
    }
}
