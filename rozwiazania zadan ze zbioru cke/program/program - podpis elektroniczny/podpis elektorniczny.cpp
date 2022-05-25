#include <bits/stdc++.h>
using namespace std;	
ofstream wyj("epodpis_wynik.txt");
void skrot(string t)
{
	string s = "ALGORYTM";
	int d = s.size();
	//uzupelnienie dlugosci wiadomosci do wielokrotnosci 8 znakow
	while (t.size() % d !=0) t += ".";
	int n = t.size();
	//przewarzanie wiadomosci
	int p = 0;
	while (p < n)
	{
		for (int j = 0; j < d; j++)
			s[j] = (s[j] + t[p+j]) % 128;
		p+=d;
	}
	cout << n << "\n";
	for (int i = 0; i < s.size(); i++)
		cout << int(s[i] ) << " ";
	//rzutowanie elementow tablicy s na zakres wielkich liter
	for (int j = 0; j < d; j++)
		s[j] = 65 + s[j]%26;

	cout << "\n" << s << "\n\n";
}
int main ()
{
	ifstream wej("wiadomosci.txt");
	ifstream wej2("podpisy.txt");

	string wiad[11];
	int podpisy[11][8];
	for (int i = 0; i < 11; i++)
	{
		getline(wej, wiad[i]);
		if (i == 0)
			skrot(wiad[i]);
		for (int j = 0; j < 8; j++)
			wej2 >> podpisy[i][j];
	}
}
