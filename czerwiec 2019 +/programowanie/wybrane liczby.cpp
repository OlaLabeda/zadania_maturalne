#include <bits/stdc++.h>
using namespace std;
bool czypierwsze (int x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}
int utwwage (int x)
{
	int waga = 0;
	while (x != 0)
	{
		waga += x % 10;
		x /= 10;
	}
	return waga;
}
int main ()
{
	long long int liczby[300];
	long long int pierwsze[200];
	
	ifstream wejl("liczby.txt");
	ifstream wejp("pierwsze.txt"); //to ze pierwsze nie oznacza ze wszystkie pierwsze xd
	ofstream wyj1("wyniki4_1.txt");
	ofstream wyj2("wyniki4_2.txt");
	ofstream wyj3("wyniki4_3.txt");
	
	for (int i = 0; i < 300; i++)
			wejl >> liczby[i];
		
	for (int i = 0; i < 200; i++)
			wejp >> pierwsze[i];	
	
	for (int i = 0; i < 300; i++)
	{
		if (liczby[i] >= 100 && liczby[i] <= 5000)
			if( czypierwsze( liczby[i] ) ) wyj1 << liczby[i] << endl;
	}
	//4.2 => odwroc ze tak od konca liczbe z pliku pierwsze i sprawdz czy pierwsza
	for (int i = 0; i < 200; i++)
	{
		int pom = pierwsze[i] / 10, num = pierwsze[i] % 10;
		while (pom != 0)
		{	
			num *= 10;
			num += (pom % 10);
			pom /= 10;
		}
		if ( czypierwsze( num ) == 1)
			wyj2 << pierwsze[i] << endl;
	}
	
	//waga 1
	int licznik = 0;
	for (int i = 0; i < 200; i++)
	{
		int x = utwwage( pierwsze[i] );
		while (x / 10 != 0)
			x = utwwage( x );
		if ( x == 1 )
		licznik++;
	}
	wyj3 << licznik << endl;
	
}
