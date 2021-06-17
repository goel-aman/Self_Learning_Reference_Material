package my.jdbc_example.src;

import java.sql.*;

public class third {
    public static void main(String[] args) throws Exception {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/aman", "root", "password");
            Statement start = con.createStatement();
            String name = "Clinton";
            String gender = "Female";
            int count = start.executeUpdate("delete from student where name = '" + name + "'") ;// + "(" + "'" + name + "'" + "," +"'" + gender + "'" +")");
            System.out.println(count + " row/s affected ..");
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

