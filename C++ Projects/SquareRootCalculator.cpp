#include <iostream>
#include <locale.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	double sayi, sonuc;

	cout << "Bir say� girin :";
	cin >> sayi;
	sonuc = sqrt(sayi);

	cout << sayi << " say�s�n�n karek�k� : " << sonuc << endl;

	system("pause");
	return 0;

}