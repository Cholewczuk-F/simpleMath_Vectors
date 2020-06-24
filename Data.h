#pragma once
#include <vector>

using namespace std;

class Data
{
public:
	Data();

protected:


private:

	vector<int> dane;
	vector<int> maxMinSrednia;

	void WczytajDane(vector<int>& dane);
	vector<int> Max_Min_Srednia(vector<int> dane);
	void readMaxMinSrednia(vector<int> daneReturn);
	void Srednia_Wartosc(vector<int> dane);
	//void Szukaj_Wartosci(vector<int> dane);
};

