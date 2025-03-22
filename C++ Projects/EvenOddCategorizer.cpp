
#include <iostream>
#include <locale.h>		
using namespace std;

int main()
{

	setlocale(LC_ALL, "Turkish");

	int X = 0, Y = 0;
	int D = 0, F = 0;

	int Q;

	do {
		cout << "asdasd ";
		cin >> Q;

		if (Q > 0)
		{
			if (Q % 2 == 0)
			{
				Y += Q;
				F++;
			}
			else
			{
				X += Q;
				D++;
			}
		}
	} while (Q >= 0);

	system("pause");

	return 0;
}


