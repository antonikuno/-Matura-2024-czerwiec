#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
string rot13(string slowo){
	string alfabet = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < slowo.size(); i++){
		for (int j = 0; j < alfabet.size(); j++) {
			if (slowo[i] == alfabet[j]) {
				slowo[i] = alfabet[j + 13];
				break;
			}
		}
	}
	return slowo;
}


int main()
{
	fstream plik;
	plik.open("slowa.txt", ios::in);
	string dane;
	vector <string> slowa;

	while (getline(plik, dane)) {
		slowa.push_back(dane);
	}
	/*
	string slowo_rot13, najdlusze_slowo = "";
	int wynik = 0;

	for (int i = 0; i < slowa.size(); i++) {
		slowo_rot13 = rot13(slowa[i]);
		reverse(slowo_rot13.begin(), slowo_rot13.end());

		if (slowo_rot13 == slowa[i]) {
			wynik += 1;
			if (slowa[i].size() > najdlusze_slowo.size()) {
				najdlusze_slowo = slowa[i];
			}
		}
	}
	cout << wynik << " " << najdlusze_slowo << endl;
	*/
	//3.3
	int dl_slowa, ilosc_lit = 1;	//dl_slowa - dlugosc naszego slowa, ilosc_lit - ilosc wystepowania dalej litery w slowie
	string slowo;
	
	for (int i = 0; i < slowa.size(); i++){
		slowo = slowa[i];
		dl_slowa = slowo.length();

		for (int j = 0; j < dl_slowa - 1; j++) {
			ilosc_lit = 1;
			for (int k = j+1; k < dl_slowa; k++) {
				if (slowo[j] == slowo[k]) {
					ilosc_lit += 1;
				}
			}
			if (dl_slowa % 2 == 0) {
				if (ilosc_lit >= (dl_slowa / 2)) {
					cout<<slowo<<endl;
					break;
				}
			}
			if (dl_slowa % 2 != 0) {
				if (ilosc_lit >= ((dl_slowa / 2) + 1)) {
					cout << slowo<<endl;
					break;
				}
			}

		}
	}
}
