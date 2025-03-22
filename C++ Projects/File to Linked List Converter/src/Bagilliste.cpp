#include "Bagilliste.h"

using namespace std;
Bagilliste::Bagilliste()
{
	string input[100];
	inputlength = 0;
	karakter = 2;
	BitKazanci = 1;
}
void Bagilliste::Add(Dugum* head, string metin[]) {
	fstream textfile;
	textfile.open("icerik.txt");
	for (int i = 0; i < inputlength; i++) {
		Dugum* temp = head;
		while (temp->ileri != NULL) {
			temp = temp->ileri;
		}
		temp->ileri = new Dugum(temp, metin[karakter] + " -0 ", NULL);
		Dugum* kontrolTemp = head;
		for (int i = 0; i < karakter; i++)
		{
			if (kontrolTemp->veri == temp->ileri->veri) {
				BitKazanci = BitKazanci + (int)temp->ileri->veri.length() - 4 - (int)to_string(karakter - i).length();
				temp->ileri->veri = " - " + to_string(karakter - i);
				break;
			}
			else kontrolTemp = kontrolTemp->ileri;
		}
		karakter++;
	}

	textfile.close();
}
void Bagilliste::dosyaOku(string input[]) {
	textfile.open("icerik.txt");
	while (!textfile.eof()) {
		textfile >> input[inputlength];
		inputlength++;
	}
	textfile.close();
}
void Bagilliste::yazdir(Dugum* head) {
	Dugum* temp = head;
	cout << "NULL <-:";
	while (temp->ileri->ileri != NULL) {
		cout << temp->veri;
		temp = temp->ileri;
		if (temp->ileri->ileri != NULL) cout << ":<->:";
		else cout << " :->";
	}
	cout << "NULL" << endl;
	cout << "Bit Kazanci: " << BitKazanci << " byte" << endl;

}
