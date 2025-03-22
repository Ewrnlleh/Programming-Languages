/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nesneproje;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.ResultSet;

/**
 *
 * @author Emrullah
 */
public class KullaniciPostgreSQL implements IKullaniciVeritabaniServisi{

    private boolean kullaniciDogrulaKontrol;

     private static KullaniciPostgreSQL single_instance = null; 
    
    private KullaniciPostgreSQL() 
    { 
        this.kullaniciDogrulaKontrol = false;
    }
    
    public static KullaniciPostgreSQL getInstance() 
    { 
        if (single_instance == null) 
            single_instance = new KullaniciPostgreSQL(); 
  
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
    public void kullaniciKaydet(Kullanici kullanici) {
        
        Connection conn=this.baglan();
        try{
            Statement stmt = conn.createStatement();
            String veri = kullanici.getKullaniciAdi();
            String veri2 = kullanici.getSifre();
            stmt.executeUpdate("INSERT INTO kullanici(kullaniciadi, sifre) VALUES (\'"+veri+"\',\'"+veri2+"\')");
            
            conn.close();
            stmt.close();
        }
        catch (Exception e) {
            System.out.println("Kullanıcı eklenemedi");
            e.printStackTrace();
        }
        System.out.println("Yeni kullanıcı kayıt edildi.\n");
    }

    @Override
    public void kullaniciDogrula(Kullanici kullanici) {
        
        String sql = "SELECT *  FROM \"kullanici\" ";
        Connection conn=this.baglan();
        try
        {
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);

            conn.close();

            while(rs.next())
            {
                if(kullanici.getKullaniciAdi().equals(rs.getString("kullaniciadi"))&&kullanici.getSifre().equals(rs.getString("sifre"))){
                    kullaniciDogrulaKontrol = true;
                }

            }
            
            rs.close();
            stmt.close();
        
        }
        catch (Exception e) {
            System.out.println("Kişi bulunamadı");
            e.printStackTrace();
        }
    }
    
    public boolean getKullaniciDogrulaKontrol(){
        return kullaniciDogrulaKontrol;
    }
    
}
