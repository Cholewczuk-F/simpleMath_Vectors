#include "Data.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//modyfikacje:-wartości liczone przez jedną funkcję : zwróciła wektor z wartościami(min, max, pozycje)


Data::Data() {
	WczytajDane(dane);
	//Max_Min(dane);
	maxMinSrednia = Max_Min_Srednia(dane);
	readMaxMinSrednia(maxMinSrednia);
	Srednia_Wartosc(dane);
	//Szukaj_Wartosci(dane);
}

void Data::readMaxMinSrednia(vector<int> daneReturn) {
	cout << "Wartość maksymalna: " << daneReturn[0] << ", pozycja: " << daneReturn[1] << "		Wartość minimalna: " << daneReturn[2] << ", pozycja: " << daneReturn[3] << endl;

	cout << "Wartość szukana: " << daneReturn[4] << " ";
	if (daneReturn.size() == 6) {
		cout << ", Pozycja: " << daneReturn[5] << endl;
	}
	else {
		cout << "- Nie odnaleziono." << endl;
	}
}

void Data::WczytajDane(vector<int>& dane)
{
	int userNumber; string inputBuffer = "";
	cout << "Podaj dowolną ilość liczb całkowitych. Aby zakończyć: 'koniec'.\n";

	while (inputBuffer != "koniec")
	{
		cout << "Liczba " << dane.size() + 1 << ": ";
		getline(cin, inputBuffer);
		stringstream numberStream(inputBuffer);
		if (numberStream >> userNumber)
		{
			dane.push_back(userNumber);
		}
	}
	cout << "Podano " << int(dane.size()) << " liczb.\n";
}

vector<int> Data::Max_Min_Srednia(vector<int> dane)
{
	int max = dane[0], min = dane[0], max_id = 0, min_id = 0, rozmiar = dane.size();

	vector<int> daneReturn;

	for (int i = 0; i < rozmiar; i++)
	{
		if (dane[i] > max)
		{
			max = dane[i];
			max_id = i;
		}
		else if (dane[i] < min)
		{
			min = dane[i];
			min_id = i;
		}
	}
	/*cout << "Wartość maksymalna: " << max << ", pozycja: " << max_id << "		Wartość minimalna: " << min << ", pozycja: " << min_id << endl;*/

	daneReturn.push_back(max);
	daneReturn.push_back(max_id);
	daneReturn.push_back(min);
	daneReturn.push_back(min_id);

	int szukana; string inputBuffer = "";
	cout << "Podaj teraz wartość, której pozycję program ma zwrócić: ";

	while (true)
	{
		getline(cin, inputBuffer);
		stringstream numberStream(inputBuffer);
		if (numberStream >> szukana)
		{
			break;
		}
		else
		{
			cout << "Nieprawidłowa wartość. Wartość: ";
		}
	}

	daneReturn.push_back(szukana);

	bool odnaleziono = false;

	for (int i = 0; i < rozmiar; i++)
	{
		if (szukana == dane[i])
		{
			//cout << "Szukana: " << szukana << " pozycja: " << i << " w tablicy.\n";
			odnaleziono = true;
			daneReturn.push_back(i);
		}
		else if (i == rozmiar - 1 && odnaleziono == false)
		{
			//cout << "Nie odnaleziono szukanej liczby.\n";
		}
	}
	return daneReturn;
}

void Data::Srednia_Wartosc(vector<int> dane)
{
	int i = 0;
	double srednia = 0, rozmiar = dane.size();

	for (auto element : dane)
	{
		srednia += element;
	}
	srednia = srednia / rozmiar;
	cout << "Średnia tablicy wynosi: " << srednia << "\n\n";
}

//void Data::Szukaj_Wartosci(vector<int> dane)
//{
//	int szukana; int rozmiar = dane.size(); string inputBuffer = "";
//	cout << "Podaj teraz wartość, której pozycję program ma zwrócić: ";
//
//	while (true)
//	{
//		getline(cin, inputBuffer);
//		stringstream numberStream(inputBuffer);
//		if (numberStream >> szukana)
//		{
//			break;
//		}
//		else
//		{
//			cout << "Nieprawidłowa wartość. Wartość: ";
//		}
//	}
//
//	bool odnaleziono = false;
//
//	for (int i = 0; i < rozmiar; i++)
//	{
//		if (szukana == dane[i])
//		{
//			cout << "Szukana: " << szukana << " pozycja: " << i << " w tablicy.\n";
//			odnaleziono = true;
//		}
//		else if (i == rozmiar - 1 && odnaleziono == false)
//		{
//			cout << "Nie odnaleziono szukanej liczby.\n";
//		}
//	}
//}