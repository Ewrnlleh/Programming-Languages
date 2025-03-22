

#include <iostream>
#include <iomanip>

using namespace std;

struct Islem
{
	int giris[6][6] = { 7,2,4,6,7,8,
						3,7,6,8,6,8,
						3,6,8,4,2,7,
						1,2,3,5,7,8,
						1,5,7,7,8,7,
						5,7,8,4,2,5, };

	int cikis[100][100];
	int cekirdek[5][5];
	int girisBoyutHesapla();
};


int Islem::girisBoyutHesapla()
{
	int x;
	x = sqrt(sizeof(giris) / sizeof(giris[0][0]));
	return x;
}

int main()
{

	int cekirdek_boyut, giris_boyut, cikis_boyut;
	int kayma_miktari;
	Islem deger;


	giris_boyut = deger.girisBoyutHesapla();
	

	cout << "cekirdek boyutunu giriniz:";
	cin >> cekirdek_boyut;
	cout << endl << "kayma miktarini giriniz:";
	cin >> kayma_miktari;
	

	if (giris_boyut < cekirdek_boyut || cekirdek_boyut < kayma_miktari || (giris_boyut - cekirdek_boyut) % kayma_miktari != 0)
	{
		cout << endl << "bu islem yapilamaz...";
	}

	else
	{
		for (int x = 0; x < cekirdek_boyut; x++)
		{
			for (int y = 0; y < cekirdek_boyut; y++)
			{
				cout << endl << "cekirdek" << "["<<x<<"]"<< "["<<y<<"]=";
				cin >> deger.cekirdek[x][y];
			}
		}
		
		cikis_boyut = ((giris_boyut - cekirdek_boyut) / kayma_miktari) + 1;

		int i=0, j=0;

		for (int k = 0; k < cikis_boyut; k++)
		{
			for (int l = 0; l < cikis_boyut; l++)
			{

				deger.cikis[k][l] = 0;

				i = (k * kayma_miktari);

				for (int x = 0; x < cekirdek_boyut; x++)
				{

					j = (l * kayma_miktari);

					for (int y = 0; y < cekirdek_boyut; y++)
					{
						deger.cikis[k][l] += (deger.cekirdek[x][y]) * (deger.giris[i][j]);
						j++;
					}

					i++;

				}
			}
		}

		for (int k = 0; k < cikis_boyut; k++)
		{
			for (int l = 0; l < cikis_boyut; l++)
			{
				cout << setw(5) << deger.cikis[k][l];
			}
			cout << endl;
		}
	}
	
	system("pause");
	return 0;

}		




