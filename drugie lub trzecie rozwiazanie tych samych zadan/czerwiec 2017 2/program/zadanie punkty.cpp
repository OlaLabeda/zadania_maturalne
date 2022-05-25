#include <bits/stdc++.h>
using namespace std;
bool czypierwsza(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}
bool czycyfropodobne(int x, int y)
{
	bool t1[11], t2[11];
	for (int i =0; i < 10; i++)
	{
		t1[i] = 0;
		t2[i] = 0;
	}
	while (x != 0)
	{
		t1[x%10] = 1;
		x/=10;
	}
	while (y != 0)
	{
		t2[y%10] = 1;
		y/=10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (t1[i] != t2[i])
			return 0;
	}
	return 1;
}
int main ()
{
	ifstream wej("punkty.txt");
	ofstream wyj("wyniki4.txt");
	int x[1000], y[1000];
	int ile = 0, ilecyfropodobnych = 0;
	for (int i = 0; i < 1000; i++)
	{
		wej >> x[i] >> y[i];
	//	cout << x[i] << " " << y[i] << endl;
		if (czypierwsza(x[i]) && czypierwsza(y[i]))
			ile++;
		if (czycyfropodobne(x[i], y[i]))
		{
			ilecyfropodobnych++;
		}
	}
	wyj << "1)\n" << ile << "\n\n";
	wyj << "2)\n" << ilecyfropodobnych << "\n\n";
	double odlmaks = 0;
	int ind1, ind2;
	for (int i = 0; i < 1000; i++)
	{
		for (int j = i+1; j < 1000; j++)
		{
			double odllok;
			odllok = abs(sqrt(pow(x[j]-x[i], 2) + pow(y[j]-y[i], 2)));
			if (odllok > odlmaks)
			{
				odlmaks = odllok;
				ind1 = j;
				ind2 = i;
			}
		}
	}
	wyj << "3)\n" << x[ind1] << " " << y[ind1] << "\n" << x[ind2] << " " << y[ind2] << "\n"<< round(odlmaks)<< "\n\n";
	wyj << "4)\n";
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (x[i] > - 5000 && x[i] < 5000 && y[i] < 5000 && y[i] > -5000)
		{
			a++;
		}
		if (x[i] == 5000 || y[i] == 5000 || x[i] == -5000 || y[i] == -5000)
		{
			b++;
		}
		if (x[i] < - 5000 || x[i] > 5000|| y[i] > 5000 || y[i] < -5000)
		{
			c++;
		}
	}
	wyj << "a: " << a << "\nb: " << b<< "\nc: " << c;
}
