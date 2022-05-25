#include <bits/stdc++.h>
using namespace std;
bool czypotega3(int x)
{
	for (int i  = 0; pow(3, i) <= x; i++)
	{
		if (pow(3, i) == x)
			return 1;
	}
	return 0;
}
long long silnia (int x)
{
	long long sil = 1;
	for (int i = 1; i <= x; i++)
		sil *= i;
	return sil;
}
long long sumasilni(int x)
{
	long long suma = 0;
	while (x != 0)
	{
		suma += silnia(x % 10);
		x /= 10;
	}
	return suma;
}
int main ()
{
	ifstream wej("liczby.txt");
	ofstream wyj("wyniki4.txt");
	int liczby[500];
	int ile = 0;
	for (int i = 0; i < 500; i++)
	{
		wej >> liczby[i]; 
		//cout << liczby[i] <<" ";
		if (czypotega3(liczby[i]))
			ile ++;
	}
	wyj << "1)\n" << ile << "\n\n";
	wyj << "2)\n";
	for (int i = 0; i <  500; i++)
	{
		if ((liczby[i]) == sumasilni(liczby[i]))
			wyj << liczby[i] << endl;
	}
	//najdluzszy ciag liczb ktorych nwd > 1
	int nwd = 0, nwdlok = liczby[0], indpierw = 0, indpierwlok = 0, dl = 1, dllok = 1;
	for (int j = 1; j < 500; j++) // dla kazdego mozliwego poczatkowego wyrazu !!!!!! uwazaj!!!!!!!!
	for (int i = j; i < 500; i++)
	{
		if (__gcd(nwdlok, liczby[i]) > 1)
		{
			dllok ++;
			nwdlok = __gcd(nwdlok, liczby[i]);
		}
		else
		{
			if (dllok > dl)
			{
				dl = dllok;
				indpierw = indpierwlok;
				nwd = nwdlok;
				dllok = 1;
				nwdlok = liczby[i];
				indpierwlok = i;
			}
			else
			{
				nwdlok = liczby[i];
				dllok = 1;
				nwdlok = liczby[i];
				indpierwlok = i;
			}
		}
	}
	wyj << "\n3)\n"<<liczby[indpierw] << " " << dl << " " << nwd;
	
	
}
