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
		
		void islem(string adi, string tarih) //yap�lan islemlerin tarih ile kayd�
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

Banka::Banka(){ // ilk de�erlerin atanmas�
	bakiye=0;
	hesapAdi="Tanimlanmadi";
	hesapNumarasi=0;
	islemSay=0;
}

void Banka::hesapAc(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"Hesap Ad�n�z� Giriniz: ";
		cin>>hesapAdi;
		cout<<"Hesap Numaran�z� Giriniz: ";
		while(!(cin >> hesapNumarasi)){ //kullan�c�dan al�nan karakter kontrol�
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "L�tfen sadece say� giriniz: ";
    	}
		cout<<endl;
		time_t zaman = time(0); // i�lemin yap�ld��� zaman
		char* tarih = ctime(&zaman);
		islem("Hesap A��ld�",tarih);
	}
	else{
		cout<<"Zaten Hesap A�t�n�z!\n"<<endl;
	}
}

void Banka::paraYatir(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"�nce Hesap A��n�z!\n"<<endl;
	}
	else{
		int fiyat = 0;
		cout<<"Yat�rmak istedi�iniz para miktar�n� giriniz: ";
		while(!(cin >> fiyat)){
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "L�tfen sadece say� giriniz: ";
    	}
		bakiye = bakiye + fiyat; //yat�r�lan miktar
		cout<<"Yeni Bakiye: "<<bakiye<<endl;
		cout<<endl;
		time_t zaman = time(0);
		char* tarih = ctime(&zaman);
		islem("Para Yat�r�ld�",tarih);
	}
}

void Banka::paraCek(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"�nce Hesap A��n�z!\n"<<endl;
	}
	else{
		int fiyat = 0;
		cout<<"Cekmek istediginiz para miktar�n� giriniz: ";
		while(!(cin >> fiyat)){
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "L�tfen sadece say� giriniz: ";
    	}
		if(fiyat > bakiye){ // bakiye kontrol�
			cout<<"Hesab�n�zda bu miktarda para bulunmamaktad�r."<<endl;
			cout<<endl;
		}
		else{
			bakiye = bakiye - fiyat; //�ekilen miktar
			cout<<"Yeni Bakiye: "<<bakiye<<endl;
			cout<<endl;
			time_t zaman = time(0);
			char* tarih = ctime(&zaman);
			islem("Para �ekildi",tarih);
		}
	}
}

void Banka::bakiyeSorgula(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"�nce Hesap A��n�z!\n"<<endl;
	}
	else{
		cout<<"Hesap Ad�: "<<hesapAdi<<endl;
		cout<<"Hesap Numaras�: "<<hesapNumarasi<<endl;
		cout<<"Bakiyeniz: "<<bakiye<<endl;
		cout<<endl;
	}
}

void Banka::hesapOzeti(){
	if(hesapAdi=="Tanimlanmadi")
	{
		cout<<"�nce Hesap A��n�z!\n"<<endl;
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
		cout<<"�nce Hesap A��n�z!\n"<<endl;
	}
	else{
		bakiye=0; // degerlerin s�f�rlanmas�
		hesapAdi="Tanimlanmadi"; 
		hesapNumarasi=0;
		islemSay=0;
	}
	
}

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Turkish"); // t�rk�e karakter kullan�m�
	
	int secim;
	int dongu = 1;
	Banka hesap; // s�n�ftan �retilen nesne
	
	do{
		cout<<"1) Hesap A�\n";
		cout<<"2) Para Yat�r\n";
		cout<<"3) Para �ek\n";
		cout<<"4) Bakiye Sorgula\n";
		cout<<"5) Hesap �zeti\n";
		cout<<"6) Hesap Kapat\n";
		cout<<"7) Programdan ��k��\n";
		cout<<"Se�iminiz: ";
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
