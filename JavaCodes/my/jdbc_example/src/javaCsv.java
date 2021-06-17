package my.jdbc_example.src;
import java.util.*;
import java.io.*;
public class javaCsv {
    public static void main(String[] args) throws Exception{
        String path = "practice.csv";
        String line = "";
        try{
            BufferedReader br = new BufferedReader(new FileReader(path));
            int counter = 0;
            while((line = br.readLine()) != null){
                String[] values = line.split(",");
                System.out.println(values[1 ]);
                counter++;
                if(counter == 10)
                {
                    break;
                }
            }
        } 
        catch(FileNotFoundException e){
            e.printStackTrace();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}
