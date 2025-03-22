/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nesneproje;

/**
 *
 * @author Emrullah
 */
public class Kullanici {
    private String kullaniciAdi;
    private String sifre;
    
    
    private static Kullanici single_instance = null; 
    
    private Kullanici() 
    { 
    }
    
    public static Kullanici getInstance() 
    { 
        if (single_instance == null) 
            single_instance = new Kullanici(); 
  
        return single_instance; 
    } 
    
    
    public String getKullaniciAdi(){
        return kullaniciAdi;
    }
    public void setKullaniciAdi(String kullaniciAdi){
        this.kullaniciAdi = kullaniciAdi;
    }
    
    public String getSifre(){
        return sifre;
    }
    public void setSifre(String sifre){
        this.sifre = sifre;
    }
}
