//Aleksandra Labeda
#include <bits/stdc++.h>
using namespace std;
bool czy_pierwsza(int x)
{
	for (int i =2; i<= sqrt(x); i++)
	{
		if (x % i == 0)
		return 0;
	}
	return 1;
}
int main ()
{
	int liczby[101]; string slowa[101]; int ltakiesame[101]; string stakiesame[101];
	ifstream wej("pary.txt");
	ofstream wyj("wyniki_4.txt");
	
	wyj<< "4.2 ======================================\n";
	int pom = 1, liczbaminimalna = 1000;
	for (int i = 1; i <= 100; i++)
	{
		wej>>liczby[i]>>slowa[i];
		// 2)
		ltakiesame[i] = 0;
		if (liczby[i] == slowa[i].size())
		{
			ltakiesame[pom] = liczby[i];
			stakiesame[pom] = slowa[i];
			liczbaminimalna = min(liczbaminimalna, liczby[i]);
			pom++;
		}
		int najspojny = 1, najspojnylok=1, dl = 1, indp=0; 
		for (int j = 1; j<slowa[i].size(); j++)
		{
			if (slowa[i][j] == slowa[i][j-1] )
				najspojnylok++;
			else 
			{
				if (slowa[i][j] != slowa[i][j-1])
				{
					if (najspojnylok > najspojny)
					{
						najspojny = najspojnylok;
						indp = j - najspojnylok;
						dl = najspojny;
						najspojnylok = 1;
						
					}
					else
					{
						najspojnylok = 1;
					}
				}
			}
		}
		for (int j = indp; j <indp + dl;  j++)
			wyj << slowa[i][j];
		wyj <<" "<< dl<< endl;
	}
	//1) hipoteza goldbacha
	wyj<< "\n\n4.1 =================================================\n";
	for (int i = 1; i<= 100; i++)
	{
		if (liczby[i]%2 == 0 && liczby[i] > 4)
		{
			for (int j = 2; j<= liczby[i]-2; j++ )
			{
				if (czy_pierwsza(j) && czy_pierwsza(liczby[i]-j))
					{wyj <<liczby[i]<<" "<<  j <<" "<< liczby[i]-j << endl; break;}
			}			
		}
	}
	
	//3) 
	wyj << "\n\n4.3 ====================================\n";
	string slowominimalne = stakiesame[1];
	for (int i = 2; i<=pom; i++)
	{
		if (ltakiesame[i] == liczbaminimalna)
			if (stakiesame[i] < slowominimalne)
				slowominimalne = stakiesame[i];
	}
	wyj << liczbaminimalna<<  " "<< slowominimalne;
}
