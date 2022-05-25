#include <bits/stdc++.h>
using namespace std;
bool czypierwsza(int n)
{
	if (n == 0 || n == 1) return 0;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}
long int odwroc(long int n)
{
	long int x = n%10;
	n/=10;
	while (n > 0)
	{
		x *= 10;
		x += (n%10);
		n /= 10;
	}
	return x;
}
int sumacyfr(long int n)
{
	int x = 0;
	while (n > 0)
	{
		x += n % 10;
		n /= 10;
	}
	return x;
}
int wagaliczby(long int n)
{
	while (sumacyfr(n) / 10 != 0)
	{
		n = sumacyfr(n);
	}
	n = sumacyfr(n);
	return n;
}
int main ()
{
	ifstream wej1("liczby.txt");
	ifstream wej2("pierwsze.txt");
	ofstream wyj1("wyniki4_1.txt");
	ofstream wyj2("wyniki4_2.txt");
	ofstream wyj3("wyniki4_3.txt");
	int liczby[300];
	long int pierwsze[200];
	for (int i = 0; i < 300; i++)
		wej1 >> liczby[i];
	for (int i = 0; i < 200; i++)
		wej2 >> pierwsze[i]; 
	for (int i = 0; i < 300; i++)
	{
		if (liczby[i] >= 100 && liczby[i] <= 5000)
		{
			if (czypierwsza(liczby[i]))
				wyj1 << liczby[i] << endl;
		}
	}
	int ilewagi1 = 0;
	for (int i = 0; i < 200; i++)
	{
		if (czypierwsza(odwroc(pierwsze[i])))
			wyj2 << pierwsze[i] << endl;
		if (wagaliczby(pierwsze[i]) == 1)
			ilewagi1++;
	}
	wyj3 << ilewagi1 << endl;
	
	
}
