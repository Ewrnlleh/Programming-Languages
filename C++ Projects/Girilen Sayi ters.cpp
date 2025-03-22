#include <iostream>

using namespace std;

int main()
{
	int basamaksayisi = 0;
	long long sayi;
	
	cout << "sayi giriniz:";
	cin >> sayi;
	
	while (sayi != 0)
	{

		cout << sayi % 10;
		sayi = sayi / 10;
		basamaksayisi++;
	}

	cout << endl << "basamak sayisi:" << basamaksayisi << endl;
	
	system("pause");
}