// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//





#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
double fakto(int x)
{
	if (x <= 1) return 1;
	else return x * fakto(x - 1);
}

double usAl(int taban, int us)
{
	if (us == 0) return 1;
	else return (taban*usAl(taban, us - 1));
}

int main()
{
	int x, elemansayisi, n;
	double seriAcilimToplami = 0.0;
	cout << "e^x 'deki x degerini giriniz=";
	cin >> x;

	cout << "Seri kacinci elemana kadar acilsin=";
	cin >> elemansayisi;

	for (n = 0; n < elemansayisi; n++)
	{
		cout << seriAcilimToplami << endl;
		seriAcilimToplami += (usAl(x, n) / fakto(n));
	}
	cout << seriAcilimToplami;

	system("PAUSE");
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
