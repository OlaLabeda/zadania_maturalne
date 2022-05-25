#include <bits/stdc++.h>
using namespace std; 
long long silnia(long long int x)
{
	int k = 1;
	
	for (int i = 2; i <= x; i++)
		k *= i;
		
	return k;
}

long long sumasilni (long long x)
{
	long long suma = 0;
	long long dz = x;
	while (dz != 0)
	{
		suma += silnia( dz % 10 );
		dz /= 10;
	}
	
	return suma;
}

int main ()
{
	long long int liczby[500];
	
	ifstream wej("liczby.txt");
	ofstream wyj("wyniki4.txt");
	
	for (int i = 0; i < 500; i++)
		wej >> liczby[i];

	int pom = 1;
	int zlicz = 0;
	
	for (int i = 0; i < 500; i++)
	{
		pom = 1;
		while (liczby[i] > pom)
			pom *= 3;

		if (pom == liczby[i])
			zlicz ++;
	 }
	  
	 wyj<< "4.1\n";
	 wyj << zlicz << "\n\n";
	 
	 wyj << "4.2\n";
	 for (int i = 0; i < 500; i++)
	 	if ( sumasilni( liczby[i] ) == liczby[i] )
	 		wyj << liczby[i] << "\n";
	 wyj << "\n";
	 
	 long long int gcd[500];
	 gcd[1] = __gcd( liczby[0], liczby[1] ); 
	 int dlmaks = 2, dlok = 2, wart = 0, ind  = 0;
	 
	 for (int i = 2; i< 500; i++)
	 {
	 	gcd[i] = 1; // potencjalnie najwiekszy wspolny dzielnik to 1
	 	if (gcd[i - 1] == 1) //jezeli nwd poprzednich dwoch liczb to 1
	 	{
	 		//szukam gcd obecnej liczby i jej poprzenika
	 		gcd[i] = __gcd(liczby[i - 1], liczby[i]);
	 		//jezeli to gcd jest wieksze niz 1, to zwiekszam lokalnymaks o 1
	 		//bo wstepnie jest ustawiony na 2 (bierze pod uwage obecny i poprzedni element)
	 		//ale tylko gdy poprzedni element i obecny mialy na stowke gcd >1
	 		if (gcd[i] != 1)
	 			dlok++;
		}
		else //czyli kiedy dwa poprzednie mialy wspolne gcd
		{
			gcd[i] = __gcd( gcd[i - 1], liczby[i] );
			if (gcd[i] == 1)  //jesli gcd obecnego i ciagu poprzednich to 1
			{
				if (dlmaks < dlok)
				{
					dlmaks = dlok;
					wart = gcd[i - 1];
					ind  = i - 1;
				}
				dlok = 2; 
			}
			else
				dlok++;
		}
	}
	wyj << "4.3\n";
	wyj << "pierwsza liczba: " << liczby[ind - dlmaks + 1] << "\n";
	wyj << "dlugosc ciagu: " << dlmaks << "\n";
	wyj << "wspolny dzielnik: " << wart << "\n";
	 
}
