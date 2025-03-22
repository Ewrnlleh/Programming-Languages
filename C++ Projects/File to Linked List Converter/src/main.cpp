#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Dugum.h"
#include "Bagilliste.h"
using namespace std;
string input[100];
int main()
{
	Bagilliste* liste = new Bagilliste();	
	liste->dosyaOku(input);
	Dugum* head = new Dugum(NULL, input[0] + " -0 ", NULL);
	head->ileri = new Dugum(head, input[1] + " -0 ", NULL);
	liste->Add(head, input);
    liste->yazdir(head);
	system("pause");
	return 0;
}