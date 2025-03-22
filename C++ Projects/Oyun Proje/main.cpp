

#include <iostream>
#include <Windows.h>

using namespace std;

const int yatay = 20;
const int dikey = 80;
const char gemiKarakter = 219;
const char mermiKarakter = 219;
const char dusmanKarakter = 219;
char sahne[yatay][dikey];
char tuslar[256];


enum YON
{
	YON_YUKARI = 1,
	YON_ASAGI = 2,
	YON_SAG = 4,
	YON_SOL = 16,
	YON_DUR = 256,
};

struct Eleman
{
	int x;
	int y;

	YON yon;
	char karakter;
};

Eleman gemiG�vdesi[5];
Eleman mermi;
Eleman dusman[9];


void koordinatxy(int x,int y) // koordinat vermek i�in gerekli.
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void sahneCiz() // Oyun alan�n� �izer.
{
	for (int x = 0; x < yatay; x++)
	{
		for (int y = 0; y < dikey; y++)
		{
			cout << sahne[x][y];
		}
		cout << endl;
	}

	cout << endl <<" Tuslar:  A=Yukari   D=Asagi   K=Ates";
}
void sinirOlustur() // Oyun alan�n�n �er�evesini olu�turur.
{

	for (int y = 0; y < yatay; y++)
	{
		sahne[y][0] = 219;
		sahne[y][dikey - 1] = 219;
	}

	for (int x = 0; x < dikey; x++)
	{
		sahne[0][x] = 219;
		sahne[yatay - 1][x] = 219;
	}


}
void sahneTemizle() // Sahnedeki karakterlerin hepsini siler.
{
	for (int x = 0; x < yatay; x++)
	{
		for (int y = 0; y < dikey; y++)
		{
			sahne[x][y] = ' ';
		}
	}
}
void kursoruGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void klavyeOku(char tuslar[])
{
	for (int x = 0; x < 256; x++)
		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
}
void klavyeKontrol() // Klavyeden bas�lan tu�a g�re oyunda kontrolu sa�lar.
{
	klavyeOku(tuslar);

	if (tuslar['A'] != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			gemiG�vdesi[i].yon = YON_YUKARI;
		}
	}
	if (tuslar['D'] != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			gemiG�vdesi[i].yon = YON_ASAGI;
		}
	}
	if (tuslar['K'] != 0)
	{
		mermi.yon = YON_SAG;
	}




}


void gemiOlustur() // Geminin prototipini olu�turur.
{
	gemiG�vdesi[0].x = 8;
	gemiG�vdesi[0].y = 4;

	gemiG�vdesi[1].x = 8;
	gemiG�vdesi[1].y = 2;

	gemiG�vdesi[2].x = 10;
	gemiG�vdesi[2].y = 4;

	gemiG�vdesi[3].x = 12;
	gemiG�vdesi[3].y = 2;

	gemiG�vdesi[4].x = 12;
	gemiG�vdesi[4].y = 4;

	for (int i = 0; i < 5; i++)
	{
		gemiG�vdesi[i].karakter = gemiKarakter;
	}
}
void gemiSahnede() // Geminin oyun alan�nda g�sterilmesini sa�lar.
{
	for (int i = 0; i < 5; i++)
	{
		int x = gemiG�vdesi[i].x;
		int y = gemiG�vdesi[i].y;
		sahne[x][y] = gemiG�vdesi[i].karakter;
	}
}
void gemiHareket() // Geminin yukar� ve a�a�� kontrol�n� sa�lar.
{
	for (int i = 0; i < 5; i++)
	{
		switch(gemiG�vdesi[i].yon)
		{
		case YON_YUKARI:
			gemiG�vdesi[i].x++;
			break;
		case YON_ASAGI:
			gemiG�vdesi[i].x--;
			break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		gemiG�vdesi[i].yon = YON_DUR;
	}


}

void mermiOlustur() // Mermi prototipini olu�turur.
{
	switch(mermi.yon)
	case YON_SAG:
	{
		mermi.x = gemiG�vdesi[2].x;
		mermi.y = gemiG�vdesi[2].y;
		mermi.karakter = mermiKarakter;

		break;
	}

	mermi.yon = YON_DUR;

	

}
void mermiSahnede() // Merminin oyun alan�nda g�sterilmesini sa�lar.
{
	int x = mermi.x;
	int y = mermi.y;
	sahne[x][y] = mermi.karakter;

}
void mermiHareket() // Merminin oyunda sa�a do�ru ilerlemesini sa�lar.
{
	mermi.y++;
	
}	

void dusmanOlustur() // D��man gemisinin prototipini olu�turur.
{
	int a = rand() % 15;

	for (int i = 0; i < 3; i++)
	{
		dusman[i].x = 2+a;
		dusman[i].y = dikey - i;
	}
	for (int i = 3; i < 6; i++)
	{
		dusman[i].x = 3+a;
		dusman[i].y = dikey - i;
	}
	for (int i = 6; i < 9; i++)
	{
		dusman[i].x = 4+a;
		dusman[i].y = dikey - i;
	}
	for (int i = 0; i < 9; i++)
	{
		if (i == 4)
			dusman[i].karakter = ' ';
		else
			dusman[i].karakter = dusmanKarakter;
	}
		
}
void dusmanSahnede() // D��man gemisinin oyun alan�nda g�sterilmesini sa�lar.
{
	
	for (int i = 0; i < 9; i++)
	{
		int x = dusman[i].x;
		int y = dusman[i].y;
		sahne[x][y] = dusman[i].karakter;
	}
	if (dusman[0].y == 0)
	{
		dusmanOlustur();
	}
}
void dusmanHareket() // D��man gemisinin sola do�ru ilerlemesini sa�lar.
{
	for (int i = 0; i < 9; i++)
	{
		dusman[i].y--;
	}
	for (int i = 0; i < 9; i++)
	{
		if (dusman[i].x == mermi.x && dusman[i].y == mermi.y)
		{
			for (int i = 0; i < 9; i++)
			{
				dusman[i].karakter = ' ';
				mermi.karakter = ' ';
			}
		}
	}
}



int main()
{
	
	kursoruGizle();

	gemiOlustur();
	dusmanOlustur();
	

	while (true)
	{

		sahneTemizle();

		sinirOlustur();
		klavyeKontrol();
		
		
		mermiOlustur();


		gemiHareket();
		gemiSahnede();

		mermiHareket();
		mermiSahnede();
		
		dusmanHareket();
		dusmanSahnede();


		koordinatxy(0, 0);
		sahneCiz();


		Sleep(50);


	}





	
}