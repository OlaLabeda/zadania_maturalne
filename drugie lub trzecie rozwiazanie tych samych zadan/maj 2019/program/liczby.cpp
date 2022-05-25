#include <bits/stdc++.h>
using namespace std;
bool czypotega3(int x)
{
	while (x%3 == 0)
		x/=3;
	if (x == 1)
		return 1;
	return 0;
}
long long silnia(int x)
{
	long long wynik = 1;
	for (int i = 1; i <= x; i++)
		wynik*=i;
	return wynik;
}
bool czysilniarownacyfrze (int x)
{
	int xpom = x;
	long long sumasilni = 0;
	while(x > 0)
	{
		sumasilni += silnia(x%10);
		x/=10;
	}
	if (sumasilni == xpom)
		return 1;
	return 0;
}
int main ()
{
	ifstream wej("liczby.txt");
	ofstream wyj("wyniki4.txt");
	int liczby[500];
	int polpot3 = 0;
	for (int i = 0; i < 500; i++)
	{
		wej >> liczby[i];
		if (czypotega3(liczby[i]))
			polpot3++;
	}
	wyj <<"1)\n" <<  polpot3 << endl;
	wyj << "\n2)\n";
	for (int i = 0; i < 500; i++)
	{
		if (czysilniarownacyfrze(liczby[i]))
			wyj << liczby[i] << endl;
	}
	int makslok = 1, maksglob = 0, indp=0, indk = 0, gcdlok, gcdglob = 0;;
	for (int i = 0; i < 499; i++)
	{
		gcdlok = liczby[i];
		for (int j = i+1; j < 500; j++)
		{
			if (__gcd(gcdlok, liczby[j]) > 1)
			{
				makslok++;
				gcdlok = __gcd(gcdlok, liczby[j]);
				if (makslok> maksglob)
				{
					gcdglob = gcdlok;
					maksglob = makslok;
					indp = i;
					indk = j;
				}
			}
			else
			{
				makslok = 1;
				break;
			}
		}
	}
	wyj <<"\n3)\n" << liczby[indp] << " " << maksglob<< " "<< gcdglob;
}
