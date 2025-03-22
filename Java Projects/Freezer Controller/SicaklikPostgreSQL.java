/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nesneproje;

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.ResultSet;

/**
 *
 * @author Emrullah
 */
public class SicaklikPostgreSQL implements ISicaklikVeritabaniServisi {

    private static SicaklikPostgreSQL single_instance = null; 
    
    private SicaklikPostgreSQL() 
    { 
    }
    
    public static SicaklikPostgreSQL getInstance() 
    { 
        if (single_instance == null) 
            single_instance = new SicaklikPostgreSQL(); 
  
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
    public void sicaklikYaz(Sicaklik sicaklik) {
        
        Connection conn=this.baglan();
      try{
            Statement stmt = conn.createStatement();
            stmt.executeUpdate("INSERT INTO sicaklik(sicaklikdegeri) VALUES (\'"+sicaklik.getSicaklikDegeri()+"\')");
            
            conn.close();
            stmt.close();
        }
        catch (Exception e) {
            System.out.println("Sıcaklık Degeri kaydedilemedi.");
            e.printStackTrace();
        }
    }

    @Override
    public void sicaklikOku(Sicaklik sicaklik) {
       
        String sql = "SELECT *  FROM \"sicaklik\" ";
        Connection conn=this.baglan();
        try
        {
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);

            conn.close();

            while(rs.next())
            {
               sicaklik.setSicaklikDegeri(rs.getInt("sicaklikdegeri"));
            }
            
            rs.close();
            stmt.close();
            
            System.out.println("Sogutucunun sicaklik degeri: "+sicaklik.getSicaklikDegeri());
        
        }
        catch (Exception e) {
            System.out.println("Sıcaklık degeri okunamadı.");
            e.printStackTrace();
        }
        
    }
    
}
