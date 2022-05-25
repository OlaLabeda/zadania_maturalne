#include <bits/stdc++.h>
using namespace std;
int iledzielnikow(int n)
{
	int ile = 0;
	for (int i = 1; i*i <= n; i++)
	{
		if (n%i == 0)
			ile+=2;
	}
	return ile;
}

int main ()
{
	ifstream wej("liczby.txt");
	ofstream wyj("wyniki.txt");
	int liczby[200];
	for (int i = 0; i < 200; i++)
		wej >> liczby[i];

	wyj << "1)\n";
	int ilemniejszych = 0;
	for (int i = 199; i >=0 ; i--)
	{
		if (liczby[i] < 1000)
		{
			ilemniejszych++;
			if (ilemniejszych <= 2)
			{
				wyj << liczby[i] << endl;
			}
		}
	}
	wyj << endl << "2)\n";
	wyj << "ile liczb: "<< ilemniejszych << endl;
	for (int i = 0; i < 200; i++)
	{
		if (iledzielnikow(liczby[i]) == 18)
		{
			wyj << "liczba: "<< liczby[i] << endl;
			for (int j = 1; j <= liczby[i]; j++)
			{
				if (liczby[i]%j == 0)
				wyj << j << endl;
			}
		}
		
	}
	wyj << endl << "3)\n";
	sort(liczby, liczby+200);
	for (int i = 199; i >=0; i--)
	{
		bool czy = 1;
		for (int j = 199; j>=0; j--)
		{
			if (i != j)
				if(__gcd(liczby[i], liczby[j]) != 1)
				{
						czy = 0;break;
				}
		}
		if (czy)
		{
			wyj << liczby[i]<< endl;
			break;
		}
	}
}
