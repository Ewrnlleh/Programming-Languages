#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int final, proje, vize, ödev;

	cout << "vize:";
	cin >> vize;
	cout << "ödev:";
	cin >> ödev;
	cout << "final:";
	cin >> final;
	cout << "proje:";
	cin >> proje;

	float yýliçi = (vize*0.6 + ödev*0.4);

	float yýlsonu = (final*0.5 + proje*0.5);

	float ortalama = (yýliçi*0.6 + yýlsonu*0.4);

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
		cout << "Güzel Not!" << endl;
	}
	system("pause");
	return 0;
}
