#include <bits/stdc++.h>
using namespace std;
bool czynumeryczne(string s)
{
	for (int i =0; i < s.size(); i++)
	{
		if (int(s[i]) <48 || int(s[i]) >57)
			return 0;
	}
	return 1;
}
bool czy4asci(string s)
{
	if (s.size() < 4) return 0;
	for (int i = 0; i <= s.size() - 4; i++)
	{
		int tab[4];
		for (int j = 0; j < 4; j++)
		{
			tab[j] = int(s[i+j]);	
		}	 	
		sort(tab, tab+4);
		int licz= 1;
		for (int j =1; j < 4; j++)
		{
			if (tab[j] == tab[0] + j)
				licz++;
		}
		if (licz == 4)
		return 1;
	}
	return 0;
}
bool czywarunki (string s)
{
	bool czyliczba = 0, czymala = 0, czyduza = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c >= '0' && c <= '9') czyliczba = 1;
		if (c >= 'a' && c <= 'z') czymala = 1;
		if (c >= 'A' && c <= 'Z') czyduza = 1; 
	}
	if (czyliczba && czymala && czyduza)
		return 1;
	return 0;
}
int main ()
{
	ifstream wej("hasla.txt");
	ofstream wyj("wyniki.txt");
	string hasla[200];
	int numzlicz = 0;
	for (int i = 0; i < 200; i++)
	{
		wej >> hasla[i];
		if (czynumeryczne(hasla[i]))
			numzlicz++;
	}
	wyj << "1)\n" << numzlicz << "\n\n2)\n";
	sort(hasla, hasla+200);
	for (int i = 2; i < 200; i++)
	{
		if (i!= 199)
		{
			if (hasla[i] == hasla[i-1] && hasla[i] != hasla[i+1])
				wyj << hasla[i] << endl;
		}
		else
		{
			if (hasla[i] == hasla[i-1])
				wyj << hasla[i] ;
		}
	}
	int ile = 0, ilewarunki = 0;
	for (int i = 0; i < 200; i++)
	{
		if (czy4asci(hasla[i]))
			ile++;
		if (czywarunki(hasla[i]))
			ilewarunki++;
	}
	wyj <<"\n3)\n"<< ile << "\n\n";
	wyj << "4)\n" << ilewarunki;
	
}
