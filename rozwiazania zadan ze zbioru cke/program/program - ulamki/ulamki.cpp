#include <bits/stdc++.h>
using namespace std;
bool czyskracalny (int a, int b)
{
	if (a>b) swap(a,b);
	for (int i =2; i <= a; i++)
		if (b%i == 0 && a%i == 0)
			return 1;
	return 0;
}
int skroc(int a, int b)
{
	while (__gcd(a, b) !=1)
	{
		int x = __gcd(a, b);
		a/=x;
		b/=x;
	}
	return a;
}
long long int podnies (int b)
{
	long long p = 2*2*3*3*5*5*7*7*13;
	int pom = b;
		p /= pom;
	return p;
}
int main ()
{
	ifstream wej("dane_ulamki.txt");
	ofstream wyj("wyniki.txt");
	int ulamki[1000][2];
	long double mini = 15.1;
	int ilenieskracalnych = 0;
	int sumalicznikow = 0;
	long double wart[1000];
	for (int i = 0; i < 1000; i++)
	{
		wart[i] = 0.1;
		for (int j = 0; j < 2; j++)
			wej >> ulamki[i][j];
		
		wart[i] = ulamki[i][0]*1.0 / ulamki[i][1]*1.0;
		if (wart[i] < mini)
			mini = wart[i];
		if (!czyskracalny(ulamki[i][0], ulamki[i][1]))
			ilenieskracalnych++;
		sumalicznikow += skroc(ulamki[i][0], ulamki[i][1]);
	}
	int minmian = 1515515;
	int indmin = -1;
	for (int i = 0; i < 1000; i++)
	{
		if (wart[i] == mini)
			if (minmian > ulamki[i][1])
			{
				minmian = ulamki[i][1];
				indmin = i;
			}
	}	
	wyj << "1)\n" << ulamki[indmin][0] << " " << ulamki[indmin][1] << "\n\n";
	wyj << "2)\n" << ilenieskracalnych << "\n\n";
	wyj << "3)\n" << sumalicznikow << "\n\n";
	long long ls = 0, lm = 0;
	for (int i = 0; i < 1000; i++)
	{
		long long int x = podnies(ulamki[i][1]);
		ls += x*ulamki[i][0];
		lm += x*ulamki[i][1];
	}
	wyj << "4)\n" << ls << "\n";
}
