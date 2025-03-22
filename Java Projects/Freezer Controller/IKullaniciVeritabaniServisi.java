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
public interface IKullaniciVeritabaniServisi {
    
    public void kullaniciKaydet(Kullanici kullanici);
    public void kullaniciDogrula(Kullanici kullanici);
    public boolean getKullaniciDogrulaKontrol();
}
