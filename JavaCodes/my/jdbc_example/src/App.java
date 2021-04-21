import java.sql.*;

 public class App {
    public static void main(String[] args) throws Exception {
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/world","root","password");
            Statement start = con.createStatement();
            ResultSet rs = start.executeQuery("select Name from country where Population < 10000");
            while(rs.next()){
                System.out.println(rs.getString(1));
            }
            con.close();
        }catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
