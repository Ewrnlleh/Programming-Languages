#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int final, proje, vize, �dev;

	cout << "vize:";
	cin >> vize;
	cout << "�dev:";
	cin >> �dev;
	cout << "final:";
	cin >> final;
	cout << "proje:";
	cin >> proje;

	float y�li�i = (vize*0.6 + �dev*0.4);

	float y�lsonu = (final*0.5 + proje*0.5);

	float ortalama = (y�li�i*0.6 + y�lsonu*0.4);

	cout << "ortalama:" << ortalama << endl;

	if (ortalama < 40)
	{
		cout << "FF" << endl;
	}
	else if (ortalama < 55)
	{
		cout << "DD" << endl;
	}
	else if (ortalama < 70)
	{
		cout << "CC" << endl;
	}
	else
	{
		cout << "G�zel Not!" << endl;
	}
	system("pause");
	return 0;
}
