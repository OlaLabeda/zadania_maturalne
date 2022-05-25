#include <bits/stdc++.h>
using namespace std;
long long fibonacci[50];
string fraktal[500];
void fib (int n)
{
	fibonacci[1] = 1; fibonacci[2] = 1;
	for (int i =3; i <= n; i++)
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
}
bool czypierwsza (int n)
{
	if (n == 1) return 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
void tobinary(int i)
{
	int liczba = fibonacci[i];
	fraktal[i] = "";
	while (liczba != 0)
	{
		if (liczba % 2 == 0)
			fraktal[i] += "0";
		else	
			fraktal[i] += "1";
		liczba /= 2;
	}
}
void wyrownaj (int dl, int n)
{
	while (fraktal[n].size() < dl)
		fraktal[n] += "0";
}
bool czyszescjedynek (int n, int dl)
{
	int ile = 0;
	for (int i = 0; i < dl; i++)
	{
		if (fraktal[n][i] == '1')
			ile++;
	}
	if (ile == 6)
		return 1;
	return 0;
}
int main ()
{
	ofstream wyj("wyniki.txt");
	fib(40);
	wyj << "1)\n";
	for (int i =10; i <= 40; i+= 10)
		wyj << i << ". " << fibonacci[i] << endl;
	wyj << "\n2)\n";
	for (int i =1; i <= 40; i++)
	{
		if (czypierwsza(fibonacci[i]))
			wyj << i << ". " << fibonacci[i] << "\n";
	}
	for (int i = 1; i <= 40; i++)
		tobinary(i);
	wyj << "\n3)\n";
	int dl = fraktal[40].size();
	for (int i = 1; i <= 40; i++)
	{
		wyrownaj(dl, i);
			for (int j = dl - 1; j >= 0; j--)
				wyj << fraktal[i][j];
			wyj << "\n";
	}
	wyj << "\n4)\n";
	for (int i = 1; i <= 40; i++)
	{
		if (czyszescjedynek(i, dl))
		{
			for (int j = dl - 1; j >= 0; j--)
				wyj << fraktal[i][j];
			wyj << "\n";		
		}
}
}
