#include <iostream>
#include <locale.h>
#include <string>
#include <ctime>
#include <limits>
using namespace std;

class Banka {
	private:
		string hesapAdi;
		int hesapNumarasi;
		int bakiye;
		int islemSay;
		
		string islemAdi[50];
		string islemTarihi[50];
		
		void islem(string adi, string tarih) //yapýlan islemlerin tarih ile kaydý
		{
			islemAdi[islemSay]=adi;
			islemTarihi[islemSay]=tarih;
			islemSay++;
		}

	public:
		Banka();
		void hesapAc();
		void paraYatir();
		void paraCek();
		void bakiyeSorgula();
		void hesapOzeti();
		void hesapKapat();
		
};

Banka::Banka(){ // ilk deðerlerin atanmasý
	bakiye=0;
	hesapAdi="Tanimlanmadi";
	hesapNumarasi=0;
	islemSay=0;
}

void Banka::hesapAc(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"Hesap Adýnýzý Giriniz: ";
		cin>>hesapAdi;
		cout<<"Hesap Numaranýzý Giriniz: ";
		while(!(cin >> hesapNumarasi)){ //kullanýcýdan alýnan karakter kontrolü
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Lütfen sadece sayý giriniz: ";
    	}
		cout<<endl;
		time_t zaman = time(0); // iþlemin yapýldýðý zaman
		char* tarih = ctime(&zaman);
		islem("Hesap Açýldý",tarih);
	}
	else{
		cout<<"Zaten Hesap Açtýnýz!\n"<<endl;
	}
}

void Banka::paraYatir(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"Önce Hesap Açýnýz!\n"<<endl;
	}
	else{
		int fiyat = 0;
		cout<<"Yatýrmak istediðiniz para miktarýný giriniz: ";
		while(!(cin >> fiyat)){
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Lütfen sadece sayý giriniz: ";
    	}
		bakiye = bakiye + fiyat; //yatýrýlan miktar
		cout<<"Yeni Bakiye: "<<bakiye<<endl;
		cout<<endl;
		time_t zaman = time(0);
		char* tarih = ctime(&zaman);
		islem("Para Yatýrýldý",tarih);
	}
}

void Banka::paraCek(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"Önce Hesap Açýnýz!\n"<<endl;
	}
	else{
		int fiyat = 0;
		cout<<"Cekmek istediginiz para miktarýný giriniz: ";
		while(!(cin >> fiyat)){
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Lütfen sadece sayý giriniz: ";
    	}
		if(fiyat > bakiye){ // bakiye kontrolü
			cout<<"Hesabýnýzda bu miktarda para bulunmamaktadýr."<<endl;
			cout<<endl;
		}
		else{
			bakiye = bakiye - fiyat; //çekilen miktar
			cout<<"Yeni Bakiye: "<<bakiye<<endl;
			cout<<endl;
			time_t zaman = time(0);
			char* tarih = ctime(&zaman);
			islem("Para Çekildi",tarih);
		}
	}
}

void Banka::bakiyeSorgula(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"Önce Hesap Açýnýz!\n"<<endl;
	}
	else{
		cout<<"Hesap Adý: "<<hesapAdi<<endl;
		cout<<"Hesap Numarasý: "<<hesapNumarasi<<endl;
		cout<<"Bakiyeniz: "<<bakiye<<endl;
		cout<<endl;
	}
}

void Banka::hesapOzeti(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"Önce Hesap Açýnýz!\n"<<endl;
	}
	else{
	for(int i=0; i<islemSay;i++){ //kaydedilen islemlerin goruntulenmesi
		cout<<islemAdi[i];
		cout<<" - ";
		cout<<islemTarihi[i];
		cout<<endl;
		}
	}	
}

void Banka::hesapKapat(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"Önce Hesap Açýnýz!\n"<<endl;
	}
	else{
		bakiye=0; // degerlerin sýfýrlanmasý
		hesapAdi="Tanimlanmadi"; 
		hesapNumarasi=0;
		islemSay=0;
	}
	
}

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Turkish"); // türkçe karakter kullanýmý
	
	int secim;
	int dongu = 1;
	Banka hesap; // sýnýftan üretilen nesne
	
	do{
		cout<<"1) Hesap Aç\n";
		cout<<"2) Para Yatýr\n";
		cout<<"3) Para Çek\n";
		cout<<"4) Bakiye Sorgula\n";
		cout<<"5) Hesap Özeti\n";
		cout<<"6) Hesap Kapat\n";
		cout<<"7) Programdan Çýkýþ\n";
		cout<<"Seçiminiz: ";
		cin>>secim;
		system("cls");
	
		switch(secim){
			
			case 1: hesap.hesapAc();
				break;
			case 2: hesap.paraYatir();
				break;
			case 3: hesap.paraCek();
				break;
			case 4: hesap.bakiyeSorgula();
				break;
			case 5: hesap.hesapOzeti();
				break;
			case 6: hesap.hesapKapat();
				break;
			case 7: dongu = 0;
				break;
		}
	}while(dongu);
	
	return 0;
}
