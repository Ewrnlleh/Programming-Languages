/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nesneproje;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

/**
 *
 * @author Emrullah
 */
public class SogutucuPostgreSQL implements ISogutucuVeritabaniServisi {

      private static SogutucuPostgreSQL single_instance = null; 
    
    private SogutucuPostgreSQL() 
    { 
    }
    
    public static SogutucuPostgreSQL getInstance() 
    { 
        if (single_instance == null) 
            single_instance = new SogutucuPostgreSQL(); 
  
        return single_instance; 
    } 
    private Connection baglan(){
        Connection conn = null;
        try
        {
            conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/nesneproje","postgres","1234");
            if (conn != null)
                System.out.println("Veritabanına bağlandı!\n");
            else
                System.out.println("Bağlantı girişimi başarısız!");
        }catch (Exception e) {
            e.printStackTrace();
        }
        return conn;
    }
    
    @Override
    public void sogutucuAc() {
        
          Connection conn=this.baglan();
      try{
            Statement stmt = conn.createStatement();
            stmt.executeUpdate("INSERT INTO sogutucu(sogutucudurumu) VALUES (\'"+true+"\')");
            
            conn.close();
            stmt.close();
        }
        catch (Exception e) {
            System.out.println("Sogutucu Acılamadı.");
            e.printStackTrace();
        }
        System.out.println("Soğutucu Açıldı.");
    }

    @Override
    public void sogutucuKapa() {
             Connection conn=this.baglan();
      try{
            Statement stmt = conn.createStatement();
            stmt.executeUpdate("INSERT INTO sogutucu(sogutucudurumu) VALUES (\'"+false+"\')");
            
            conn.close();
            stmt.close();
        }
        catch (Exception e) {
            System.out.println("Sogutucu Kapatılamadı.");
            e.printStackTrace();
        }
      System.out.println("Soğutucu Kapandı.");
    }
 
}
    
