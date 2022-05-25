#include <bits/stdc++.h>
using namespace std;
bool czypierwsza (int n)
{
	for (int i = 2; i <=sqrt(n); i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}
int sumakwadratow (int n)
{
	int suma=0;
	while (n!=0)
	{
		suma += pow(n%10, 2);
		n/=10;
	}
	return suma;
}
int proces (int n)
{	
	int cykl=1;
	int sumy[10000]; 
	for (int i = 0; i < 10000; i++)
		sumy[i]=0;
	int ind =0;
	int liczba = sumakwadratow(n); //liczba bedaca suma kwadratow cyfr n
	cykl++;
	while (liczba != 1)
	{
		sumy[ind] = liczba;
		for (int i =0; i < ind; i++)
			if (sumy[i] == sumy[ind])
				return 0;
		ind++;
		liczba = sumakwadratow(liczba);
		cykl++;
	}
	return cykl;
}
int main ()
{
	ifstream wej("liczby.txt");
	ofstream wyj("wyniki4.txt");
	int maks = 0;
	int ile = 0;
	for (int i = 1;  i <= 1000; i++)
		maks = max(proces(i), maks);
	wyj << "1) \n";
	wyj << maks << "\n";
	for (int i =1; i <=1000; i++)
		if (proces(i) == maks)
			wyj << i << " ";
	wyj << "\n\n2)\n";
	int dane[2001];
	int zlicz = 0;
	int wesole[2001];
	for (int i=0; i < 2001; i++)
	{
		wej >> dane[i];
		wesole[i]=0;
		if (proces(dane[i])) 
		{
			zlicz++;
			wesole[i] = dane[i];
		}
	}
	wyj << zlicz << endl;
	//najdluzszy podciag liczb wesolych w pliku
	int najdluzszyglob = 1, najdluzszylok = 1;
	int indeks = 0;
	for (int i = 1; i < 2001; i++)
	{
		if (wesole[i] && wesole[i-1] && wesole[i-1] < wesole[i])
			najdluzszylok++;
		else
		{
			if (najdluzszyglob < najdluzszylok)
			{
				indeks = i-najdluzszylok;
				najdluzszyglob = najdluzszylok;
			}
			najdluzszylok=1;
		}
	}
	wyj << "\n3)\n";
	wyj << najdluzszyglob << endl;
	wyj << wesole[indeks]<<" "<< wesole[indeks + najdluzszyglob - 1] <<endl;
	wyj << "\n4)\n";
	int policz=0;
	for (int i = 0; i < 2001; i++)
	{
		if (wesole[i] && czypierwsza(wesole[i]))
			policz++;
	}
	wyj << policz << endl;	
}
