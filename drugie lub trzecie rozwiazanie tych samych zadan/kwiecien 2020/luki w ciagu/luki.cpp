#include <bits/stdc++.h>
using namespace std;
int main ()
{
	ifstream wej("dane4.txt");
	ofstream wyj("zadanie4.txt");
	 long long liczby[1000];
	for (int i = 0; i < 1000; i++)
		wej >> liczby[i];
	long long int maksluka = 0, minluka = abs(liczby[1] - liczby[0]);
	for (int i = 1; i < 1000; i++)
	{
		maksluka = max(abs(liczby[i] - liczby[i-1]), maksluka);
		minluka = min(abs(liczby[i] - liczby[i-1]), minluka);
	}
	wyj << "1)\nmin: " << minluka  <<  " maks: " << maksluka << endl << endl;
	int ilelok = 2, ile = 0, ind = 0, indlok = 0, lukalok = abs(liczby[1] - liczby[0]);
	for (int i = 2; i < 1000; i++)
	{
		if (abs(liczby[i] - liczby[i-1]) == lukalok)
		{
				ilelok++;
		}
		else
		{
			if (ile < ilelok)
			{
				ind = indlok;
				ile = ilelok;
			}
			lukalok = abs(liczby[i] - liczby[i-1]);
			indlok = i-1;
			ilelok = 2;
		}
	}
	wyj <<"2)\n" << ile << " " << "pocz: " << liczby[ind] << " kon: " << liczby[ind+ile-1] << "\n\n" ;
	int tab[999];
	for (int i = 1; i < 1000; i++)
	{
		tab[i-1] = abs(liczby[i] - liczby[i-1]);
	}
	sort(tab, tab + 999);
	int tlicz[999];
	tlicz[0] = 1;
	int maksik = 0;
	for (int i = 1; i < 999; i++)
	{
		tlicz[i]=1;
		if (tab[i] == tab[i-1])
		{
			tlicz[i] = tlicz[i-1] + 1;
			maksik = max(tlicz[i], maksik);
		}
	}
	wyj << "3) " << maksik << endl;
	for (int i = 0; i < 999; i ++ )
	{
		if (tlicz[i] == maksik)
		wyj << tab[i] << endl;
	}
}
