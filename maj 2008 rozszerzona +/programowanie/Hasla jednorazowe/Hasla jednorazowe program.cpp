#include <bits/stdc++.h> 
using namespace std;

vector <string> slowa, hasla, haslapb;
string dlmin, dlmaks;
int ilemin = 1, ilemaks = 1; //zliczam aby upewnic sie ze jest tylko jedno najkrotsze i jedno najdluzsze haslo

int dlugoscpalindromu (string skopia, string s)  //zwraca indeks ostatniej ok
{

		int indeks = skopia.size()-1;

		while (indeks >=0)
		{
			int k = indeks, p = 0;
			while (skopia[k] == skopia[p] && k >0 &&  p < indeks)
			{	
				k--;
				p++;
			}
			if (k==0 && indeks == p)
				return indeks;
			indeks--;
		}
}

int main ()
{
	ifstream odczyt("slowa.txt");
	ofstream wypis("hasla_a.txt");
	ofstream wypisslowa_a("slowa_a.txt");
	ofstream haslab("hasla_b.txt");
	for (int i = 1; i <= 1000; i ++)
	{
		string s, skopia;
		odczyt >> s;
		skopia = s;
		//cout << skopia<< endl;
		slowa.push_back(s);		//przechowuje wczytane slowo
		reverse(s.begin(), s.end());		
		
		//najdluzszy palindrom
		int dlp = dlugoscpalindromu(skopia, s);
		for (int j = 0; j< s.size()-dlp-1; j++)
		{
			if (s[j]!= ' ')
			haslab <<s[j];
		}
		haslab << skopia<< endl;
		//podpunkt a
		if (i == 1)
		{
			dlmin = s;
			dlmaks = s;
		}
		else
		{
			if (dlmin.size() == s.size())
				ilemin++;
			if (dlmaks.size() == s.size())
				ilemaks++;
			if (dlmin.size() > s.size())
				{
					dlmin = s;
					ilemin = 1;
				}
			if (dlmaks.size() < s.size())
				{
					dlmaks = s;
					ilemaks = 1;
				}
		}
		
		hasla.push_back(s);
		wypis << hasla[i-1] << "\n";	
		
	}
	//podpunkt a 
	//cout << ilemin<<  " "<< ilemaks<<endl;
	wypisslowa_a<< "najkrotsze slowo: "<< dlmin<<" dlugosci: "<< dlmin.size()<< "\n"; 
	wypisslowa_a<< "najdluzsze slowo: "<< dlmaks<<" dlugosci: "<< dlmaks.size()<< "\n"; 
	odczyt.close();
	ifstream odczytb("hasla_b.txt");
	ofstream wypisb("slowa_b.txt");
	wypisb << "1.\n";
	
	long long sumadlugoscihasel=0;
	for (int i = 1; i <=1000; i++)
	{
		string s;
		odczytb >> s;
		sumadlugoscihasel+=s.size();
		if (s.size()==12)
			wypisb<<s<<"\n";
		haslapb.push_back(s);
		
		if (i == 1)
		{
			dlmin = s;
			dlmaks = s;
		}
		else
		{
			if (dlmin.size() == s.size())
				ilemin++;
			if (dlmaks.size() == s.size())
				ilemaks++;
			if (dlmin.size() > s.size())
				{
					dlmin = s;
					ilemin = 1;
				}
			if (dlmaks.size() < s.size())
				{
					dlmaks = s;
					ilemaks = 1;
				}
		}

	}
	wypisb<< "2.\n";
	wypisb<< "najkrotsze slowo: "<< dlmin<< "\n"; 
	wypisb<< "najdluzsze slowo: "<< dlmaks<<"\n"; 
	wypisb<< "3.\n";
	wypisb<< sumadlugoscihasel;
}
