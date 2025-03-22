#include <iostream>
#include <locale.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	double sayi, sonuc;

	cout << "Bir sayý girin :";
	cin >> sayi;
	sonuc = sqrt(sayi);

	cout << sayi << " sayýsýnýn karekökü : " << sonuc << endl;

	system("pause");
	return 0;

}