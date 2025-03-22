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
public class NesneProje {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Kullanici kullanici = Kullanici.getInstance();
        Sicaklik sicaklik = Sicaklik.getInstance();
        int secim=0;
        KonsolMenu konsol = KonsolMenu.getInstance();
        IKullaniciVeritabaniServisi kullaniciVeritabani = KullaniciPostgreSQL.getInstance();
        ISicaklikVeritabaniServisi sicaklikVeritabani = SicaklikPostgreSQL.getInstance();
        ISogutucuVeritabaniServisi sogutucuVeritabani = SogutucuPostgreSQL.getInstance();
        
        while (secim != 3){ //Çıkış
            secim = konsol.menu();
            if(secim == 1){ // Kullanıcı Girişi, Veritabanı Doğrulama
                konsol.menuKullaniciBilgileri();
                kullanici.setKullaniciAdi(konsol.getKullaniciAdi());
                kullanici.setSifre(konsol.getSifre());
                kullaniciVeritabani.kullaniciDogrula(kullanici);
                if(kullaniciVeritabani.getKullaniciDogrulaKontrol()){
                    System.out.println("Kullanıcı Doğrulandı.");
                     while (secim != 4){
                         secim = konsol.menu2();
                         if(secim==1){//sıcaklık görüntüle
                             sicaklik.sicaklikUret();
                             sicaklikVeritabani.sicaklikYaz(sicaklik);
                             sicaklikVeritabani.sicaklikOku(sicaklik);
                             
                         }
                         if(secim==2){//sogutucu ac
                             sogutucuVeritabani.sogutucuAc();
                         }
                         if(secim==3){// sogutucu kapa
                             sogutucuVeritabani.sogutucuKapa();
                         }
                     }
                }
                else{
                    System.out.println("Kullanıcı bulunamadı.");
                }

            }
            if(secim == 2){ // Yeni Kullanıcı Kaydı, Veritabanına Ekleme
                konsol.menuKullaniciBilgileri();
                kullanici.setKullaniciAdi(konsol.getKullaniciAdi());
                kullanici.setSifre(konsol.getSifre());
                kullaniciVeritabani.kullaniciKaydet(kullanici);
            }
        }
    }
    
}
