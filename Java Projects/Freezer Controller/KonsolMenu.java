/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nesneproje;

import java.util.Scanner;
/**
 *
 * @author Emrullah
 */
public class KonsolMenu {
    private String kullaniciAdi;
    private String sifre;
    
    private static KonsolMenu single_instance = null; 
    
    private KonsolMenu() 
    { 
    }
    
    public static KonsolMenu getInstance() 
    { 
        if (single_instance == null) 
            single_instance = new KonsolMenu(); 
  
        return single_instance; 
    } 
    
    public int menu() {

        int secim;
        Scanner giris = new Scanner(System.in);

        System.out.println("Yapmak istediğiniz işlemi seçiniz");
        System.out.println("-------------------------");
        System.out.println("1 - Kullanıcı Girişi");
        System.out.println("2 - Yeni Kullanıcı Ekle");
        System.out.println("3 - Çıkış");
        
        secim = giris.nextInt();
        return secim;    
    }
    
        public int menu2() {

        int secim;
        Scanner giris = new Scanner(System.in);

        System.out.println("1 - Sıcaklık Görüntüle");
        System.out.println("2 - Soğutucu Aç");
        System.out.println("3 - Soğutucu Kapa");
        System.out.println("4 - Geri Dön");
        
        secim = giris.nextInt();
        return secim;    
    }
    
    public KonsolMenu(String kullaniciAdi,String sifre){
        this.kullaniciAdi=kullaniciAdi;
        this.sifre=sifre;
    }
    
    public String getKullaniciAdi(){
        return kullaniciAdi;
    }
    
    public String getSifre(){
        return sifre;
    }
    
    public void menuKullaniciBilgileri() {
        
        Scanner giris = new Scanner(System.in);
        System.out.println("Bilgileri Doldurunuz.");
        System.out.println("-------------------------");
        System.out.print("Kullanıcı adı: ");
        kullaniciAdi = giris.nextLine();
        System.out.print("Şifre: ");
        sifre = giris.nextLine();
    }
    
}
