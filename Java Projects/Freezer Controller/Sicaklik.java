/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nesneproje;

import java.util.Random;

/**
 *
 * @author Emrullah
 */
public class Sicaklik {
    
    private static Sicaklik single_instance = null; 
    
    private Sicaklik() 
    { 
    }
    
    public static Sicaklik getInstance() 
    { 
        if (single_instance == null) 
            single_instance = new Sicaklik(); 
  
        return single_instance; 
    } 
    
    private int sicaklikDegeri;
    
    public int getSicaklikDegeri(){
        return sicaklikDegeri;
    }
    public void setSicaklikDegeri(int kullaniciAdi){
        this.sicaklikDegeri = sicaklikDegeri;
    }
    
    public void sicaklikUret(){
        Random rand = new Random(); 
        
        sicaklikDegeri = rand.nextInt(50); 
  
    }
    
    
}
