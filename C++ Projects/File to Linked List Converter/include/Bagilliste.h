#ifndef BAGILLISTE_H
#define BAGILLISTE_H
#include <fstream>
#include "Dugum.h"
#include <sstream>
using namespace std;
class Bagilliste
{
private:
	
public:
int inputlength;
	int BitKazanci;
	Bagilliste();
	int karakter;
    fstream textfile;
	void yazdir(Dugum* head);
	int inputlengthdondur();
	int BitKazancidondur();
	void Add(Dugum* head, string metin[100]);
	void dosyaOku(string metin[100]);
};
#endif;