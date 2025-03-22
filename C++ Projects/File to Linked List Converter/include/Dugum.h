#ifndef DUGUM_H
#define DUGUM_H
#include <iostream>
#include <string>
using namespace std;
class Dugum
{
public:
	Dugum(Dugum* geri, string veri, Dugum* ileri);
	~Dugum();
	Dugum* geri;
	Dugum* ileri;
	string veri;
};
#endif