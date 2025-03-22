#include <iostream>
#include <string>

#include "Dugum.h"
using namespace std;
Dugum::Dugum(Dugum* geri, string veri, Dugum* ileri)
{
	this->geri = geri;
	this->veri = veri;
	this->ileri = ileri;
}
Dugum::~Dugum()
{
}