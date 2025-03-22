#include <iostream>
using namespace std;

struct Dugum { //Dugum yapisi olusturma
  int deger; //dugumun degeri
  struct Dugum *sonraki; //dugumun adres degeri
  Dugum(int x)
  {
  	deger = x; //dugum baslangic degerleri atama
  	sonraki = NULL;
  }
};

class BagliListe { //bagliliste sinifi
	public:
		Dugum* head; //baslangic dugumu
		Dugum* sorted; // siralanmis dugum
		
		void push(int deger) //baglilisteye yeni deger ekleme
		{
			Dugum* yenidugum = new Dugum(deger);
			yenidugum->sonraki = head; //yenidugum sonraki adres degeri atama
			head = yenidugum; // basdugumu yenidugume atama
		}
		
		void eklemeSiralama(Dugum* referans){ //baslangic referans degeri alma
			sorted = NULL; //ilk sorted dugum NULL
			Dugum* simdiki = referans; //baslangic dugumunden baslama
			
			while (simdiki != NULL) { //bagliliste de gezinme
				Dugum* sonraki = simdiki->sonraki;
				sortedInsert(simdiki); //siralama fonksiyonuna gonderme
				simdiki = sonraki;
			}
			head = sorted; // son deger sorted dugum
		}
		
		void sortedInsert(Dugum* yenidugum)
		{
			if (sorted == NULL || sorted->deger >= yenidugum->deger) //eger siralanmis dugum yoksa veya siralanmis dugumun degeri yenidugumun degerinden küçükse
			{
				yenidugum->sonraki = sorted;
				sorted = yenidugum;
			}
			else {
				Dugum* simdiki = sorted; //simdiki dugum siralanmis
				
				while (simdiki->sonraki != NULL && simdiki->sonraki->deger < yenidugum->deger) //bir önceki dugumle sonraki dugum deger karsilastirma
				{
					simdiki = simdiki->sonraki; //sonraki dugume gecme
				}
				yenidugum->sonraki =simdiki->sonraki; //dugumleri yer degistirme
				simdiki->sonraki = yenidugum;
			}
		}
		
		void yazdir(Dugum* head) // listede gezinerek tum dugumleri yazdirma islemi
		{
			while (head != NULL){
				cout << head->deger << " ";
				head = head->sonraki;
			}
		}
		
};

int main()
{
	int sayi;
	BagliListe liste; //bir bagliliste sinifi olusturma
	liste.head=NULL; //liste baslangicta null döndürür

	cout << "10 adet sayi giriniz:" << endl;
	for (int i=0; i<10;i++)
	{
		cin >> sayi;
		liste.push(sayi);//listeye deger ekleme
	}
	liste.eklemeSiralama(liste.head); //liste siralama
	cout << "Siralanmis Liste" << endl;
	liste.yazdir(liste.head);//liste goruntuleme
}

