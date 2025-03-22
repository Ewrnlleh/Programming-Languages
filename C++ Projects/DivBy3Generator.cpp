#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int sayiAdedi;
	
	cout << "Sayi Adedi Giriniz :";
	cin >> sayiAdedi;

	srand(time(NULL));
	for (int i = 0; i < sayiAdedi; i++)
	{
		
		int a = 1 + rand() % 100;

			if (a % 3 == 0)
		{
			cout << a << endl;
		}
	}

	system("pause");
	return 0;

}