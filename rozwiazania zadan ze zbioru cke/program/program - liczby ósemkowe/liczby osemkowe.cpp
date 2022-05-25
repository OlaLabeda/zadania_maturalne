#include <bits/stdc++.h>
using namespace std;
int zamiana (int n, int s)
{
	int p = 1;
	int liczba = 0;
	while (n!=0)
	{
		liczba += (n%10)*p;
		p*=s;
		n/=10;
	}
	return liczba;
}
int ileszostek (int n, int s)
{
	int ile =0;
	while (n!=0)
	{
		if (n%s == 6)
			ile++;
		n/=s;
	}
	return ile;
}
int main ()
{
	ifstream wej1("liczby1.txt");
	ifstream wej2("liczby2.txt");
	ofstream wyj("wyniki.txt");
	int osemkowo[1000], pom[1000];
	int dziesietnie[1000];
	for (int i =0; i < 1000; i++)
	{
		wej1 >> osemkowo[i];
		pom[i]= osemkowo[i];
		wej2>>dziesietnie[i];
	}
	sort(pom, pom + 1000);
	wyj << "1)\n";
	wyj << pom[0] << endl << pom[999] << endl << endl;
	int maksdl = 1, dllok=1, pierwszy = dziesietnie[0];
	for (int i =1; i < 1000; i++)
	{
		if (dziesietnie[i] >= dziesietnie[i-1])
			dllok++;
		else
		{
			if (maksdl < dllok)
			{
				maksdl = dllok;
				pierwszy = dziesietnie[i-dllok];
			}
			dllok = 1;
		}
	}
	wyj << "2)\ndlugosc ciagu: " << maksdl << endl << "element: " << pierwszy<< endl<< endl;
	int tasamawart = 0;
	int osemkowewiekszenizdziesietne = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (zamiana(osemkowo[i], 8) == dziesietnie[i])
			tasamawart++;
		else if (zamiana(osemkowo[i], 8) > dziesietnie[i])
			osemkowewiekszenizdziesietne ++;
	}
	wyj << "3)\n" <<"ta sama: "<< tasamawart << endl <<"osemkowe wieksze: "<< osemkowewiekszenizdziesietne<< endl<< endl;
	int ilewdz = 0, ilewos = 0;
	for (int i =0; i < 1000; i++)
	{
		ilewdz += ileszostek(dziesietnie[i], 10);
		ilewos += ileszostek (dziesietnie[i], 8);
	}
	wyj << "3)\n" << "w dziesietnym: " <<ilewdz << endl << "w osemkowym: " << ilewos << endl;
	
}
