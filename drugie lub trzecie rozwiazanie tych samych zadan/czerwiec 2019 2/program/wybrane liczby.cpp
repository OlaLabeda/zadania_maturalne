#include <bits/stdc++.h>
using namespace std;
bool czypierwsza (long long int x)
{
	for (int i = 2; i *i <= x; i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}
bool czytezpierwsza(long long int x)
{
	//odwracam liczbe
	long long p = x;
	long long odwrocona = p%10;
	p/=10;
	while (p!=0)
	{
		odwrocona*=10;
		odwrocona += p%10;
		p/=10;
	}
	if (czypierwsza(odwrocona))
		return 1;
	return 0;
}
int sumacyfr (long long x)
{
	int suma = 0;
	while (x!=0)
	{
		suma += x%10;
		x/=10;
	}
	return suma;
}
int main ()
{
	ifstream wej("liczby.txt");
	ifstream wej2("pierwsze.txt");
	ofstream wyj1("wyniki_4_1.txt");
	ofstream wyj2("wyniki_4_2.txt");
	ofstream wyj3("wyniki_4_3.txt");
	long long int liczby[300]; long long  pierwsze[200];
	for (int i = 0; i < 300; i++)
	{
		wej >> liczby[i];
	}
	wej.close();
	for (int i = 0; i < 200; i++)
	{
		wej2 >> pierwsze[i];
	}
	for (int i = 0; i < 300; i++)
	{
		if (liczby[i] >= 100 && liczby[i] <= 5000)
		{
			if (czypierwsza(liczby[i]))
				wyj1 << liczby[i] << endl;
		}
	}
	for (int i = 0; i < 200; i++)
	{
		if (czytezpierwsza(pierwsze[i]))
		wyj2 << pierwsze[i] << endl;
	}
	int ile = 0;
	for (int i = 0; i < 200; i++)
	{
		long long x = pierwsze[i];
		while (x /10 !=0)
		{
			x = sumacyfr(x);
		}
		if (x == 1)
			ile++;
	}
	wyj3 << ile;
}
