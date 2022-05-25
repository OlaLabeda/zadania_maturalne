#include <bits/stdc++.h>
using namespace std;
int main ()
{
	long long int liczby[1001], lukamin, lukamaks, luki[1001], m=0;
	ifstream wej("dane4.txt");
	ofstream wyj("zadanie4.txt");
	wyj<<"1)\n";
	for (int i =1; i<= 1000; i++)
	{
		wej>>liczby[i];
		m=max(m, liczby[i]);
		if (i == 2)
		{
			lukamin = abs(liczby[i] - liczby[i-1]);
			lukamaks = abs(liczby[i] - liczby[i-1]);
			luki[i]=lukamin;
		}
		else if (i > 2)
		{
			lukamin = min(lukamin, abs(liczby[i] - liczby[i-1]));
			lukamaks = max(lukamaks, abs(liczby[i] - liczby[i-1]));
			luki[i] = abs(liczby[i] - liczby[i-1]);
		}
	
		
	}
	wyj << "najmniejsza: "<< lukamin<< endl<<"najwieksza: "<< lukamaks<< endl;
	
	long long najdluzszy=1, najdluzszylok=1, indp=0, indk = 0; 
	//najdluzszy - najdluzszy pdciag sposrod wynikow odejmowania, wiec
	//do ostatecznego wyniku musze dodac jeden - uwzglednic pierwszy pominiety element  (wypisuje najdluzszy fragment ciagu, a nie
	//najdluzszy podciag roznic lol
	
	///JAK UWAZASZ TO PAMIETAJ BY UWAZAC NA WSZYSTKO A NIE WYBIORCZO XD
	wyj<<endl<<endl;
	for (int i = 3; i<=1000; i++)
	{
		if (luki[i] == luki[i-1])
		najdluzszylok++;
		else
		{
			if (najdluzszylok> najdluzszy)
			{
				najdluzszy = najdluzszylok + 1;
				indp = i - najdluzszylok -1;
				indk = i-1;
			}
			else
			najdluzszylok=1;
		}
	}
	wyj << "2)\nNajwieksza dlugosc fragmentu regularnego: "<< najdluzszy<< endl<<"poczatek: "<< liczby[indp]<< endl<< "koniec: "<<liczby[indk];
//znajduje najwieksza dlugosc metoda zliczania
	long long lmakslok = 0, lmaks = 0;
	for (int i = 2; i<=1000; i++)
	{
		lmakslok = 1;
	    for (int j = i+1; j<= 1000; j++)
		{
			if (luki[j]==luki[i])
				lmakslok++;
		}
		lmaks= max(lmakslok, lmaks);
	}
	wyj<< "\n\n3)\n";
	wyj << "krotnosc najczestszej luki: "<< lmaks<< endl<< "wartosci najczestszych luk: \n";
	int pom = lmaks;
	//powtarzam zliczanie, gdy jakas wartosc osiagnie wczesniej policzone maksimum, wypisuje ja
	for (int i = 2; i<=1000; i++)
	{
		lmakslok = 1;
	    for (int j = i+1; j<= 1000; j++)
		{
			if (luki[j]==luki[i])
				lmakslok++;
		}
		lmaks= max(lmakslok, lmaks);
		if (lmakslok == pom)
		wyj <<luki[i]<< endl;
	}
	
}
