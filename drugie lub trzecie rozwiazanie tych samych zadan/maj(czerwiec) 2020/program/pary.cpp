#include <bits/stdc++.h>
using namespace std;
bool czypierwsza (int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}
int goldbach(int n)
{
	for (int i = 2; i <= n; i ++)
	{
		if (czypierwsza(i))
		{
			if (czypierwsza(n-i))
				return i;
		}
	}
}
int indnajdlpodciagu (string s)
{
	int dllok = 1, dlglob = 1;
	int ind = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i-1])
		{
			dllok++;
		}
		else
		{
			if (dllok > dlglob)
			{
				ind = i-1;
				dlglob = dllok;
				dllok = 1;
			}
		}
	}
	return ind;
}
int main ()
{
	ifstream wej("pary.txt");
	ofstream wyj("wyniki.txt");
	int liczba[100];
	string slowo[100];
	for (int i = 0; i < 100; i++)
	{
		wej >> liczba[i] >> slowo[i];
		//cout << liczba[i] << " " << slowo[i] << endl;
	}
	wyj << "1)\n";
	for (int i = 0; i < 100; i++)
	{
		if (liczba[i] % 2 == 0 && liczba[i] > 4)
		{
			int x = goldbach(liczba[i]);
			wyj << liczba[i] << " " << x << " " << liczba[i] - x << "\n" ;
		}
	}
	wyj << "\n\n2)\n";
	for (int i = 0; i < 100; i++)
	{
		bool czyprzerwac = 0;
		int x = indnajdlpodciagu(slowo[i]);
		if ( x == 0)
			{
				wyj << slowo[i][0] << " " << 1 << endl;	
				czyprzerwac = 1;
			}
		int dl = 0;
		for (int j = x; j > 0; j--)
		{
			if (czyprzerwac) break;
			wyj << slowo[i][x];
			dl++;
			if (slowo[i][j] != slowo[i][j-1])
			{
				wyj << " " << dl << endl;
				czyprzerwac = 1;
				break;
			}
		}
		if (czyprzerwac == 0)
			wyj << " " << dl << endl;
	}
	int lmin = 1000; string slowomin;
	for (int i = 0; i < 100; i++)
	{
		if (slowo[i].size() == liczba[i])
		{
			if (lmin == 1000)
			{
				lmin = liczba[i];
				slowomin = slowo[i];
			}
			else
			{
				if (liczba[i] < lmin)
				{
					lmin = liczba[i];
					slowomin = slowo[i];
				}
				else if (liczba[i] == lmin && slowo[i] < slowomin)
				{
					slowomin = slowo[i];
				}
			}
		}
	}
	wyj << "\n\n3)\n" << lmin << " " <<slowomin << endl;
	
}
