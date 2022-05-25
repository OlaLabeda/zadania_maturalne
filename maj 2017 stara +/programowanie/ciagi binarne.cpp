#include <bits/stdc++.h>
using namespace std;
long long int zbinarnegonadzies (string s)
{
	long long int suma = 0;
	long long int l = 1;
	for (int i = s.size()-1; i>= 0; i--)
	{
		suma+= (s[i]-48)*l;
		l *= 2;
		if (suma > 65535)
		return 0;
	}
	return suma;
}
int main ()
{
	string napisy[500]; //kazdy ma dlugosc podzielna przez 4
	ifstream wej("binarne.txt");
	ofstream wyj("zadanie4.txt");
	//dwucykliczny - dwa razy ten sam napis
	// 100100 => 100 100
	int dwucykliczne = 0;
	string najdlnapis = "";
	int ileniepoprawnych = 0; bool ktorato =0;
	for (int i = 0; i< 500; i++)
	{
		wej >> napisy[i];
		int dl = napisy[i].size();
		bool czy = 1;
		for (int j = 0; j < dl/2; j++)
		{
			if (napisy[i][j] != napisy[i][dl/2 + j])
			{
				czy = 0; 
				break;
			}
		}
		if (czy) 
		{
			dwucykliczne ++;
			if (najdlnapis.size() < napisy[i].size())
				najdlnapis = napisy[i];
		}
	}
	wyj <<"1)\n" <<"liczba dwucyklicznych:\n"<< dwucykliczne << endl <<"najdluzszy napis:\n"<< najdlnapis<< endl <<"dlugosc:\n"<< najdlnapis.size()<< "\n\n";
	int najkrslowo;
	for (int i = 0; i < 500; i++)
	{
		bool czysiezgadza = 1;
		for (int j = 0; j < napisy[i].size(); j+= 4)
		{
			int suma = 0;
			int pom = 8;
			for (int k = j; k - 4 < j; k++)
			{
				suma += int(napisy[i][k] - 48)*pom;
				pom/=2;
				if (suma > 9)
				{
					czysiezgadza = 0;
					if (ktorato == 0)
					{
						najkrslowo = napisy[i].size();
						ktorato = 1;
					}
					else najkrslowo = min(najkrslowo, int(napisy[i].size()));
					break;
				}
			}
		}
		if (czysiezgadza == 0) ileniepoprawnych++;
	}
	wyj << endl<< "2)\n" <<"liczbaniepoprawnych:\n"<< ileniepoprawnych << endl<<"min dlugosc:\n"<< najkrslowo<< endl;
	long long maks = 0;
	string makss;
	for (int i = 0; i< 500; i++)
	{
		if (maks < zbinarnegonadzies(napisy[i]))
			{
				maks =zbinarnegonadzies(napisy[i]);
				makss = napisy[i];
			}
	}
	wyj <<"\n3)\n"<<  maks <<endl << makss<< endl;
}
