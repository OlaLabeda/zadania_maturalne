#include <bits/stdc++.h>
using namespace std;
int czyarytmetyczny (int tab[], int n)
{
	int r = tab[1] - tab[0];
	for (int i = 2; i < n; i++)
	{
		if (tab[i] - tab[i-1] != r)
			return 0;
	}
	return r;
}
bool czypotega3 (int n)
{
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (pow(i, 3) == n)
			return 1;
	}
	return 0;
}
int main ()
{
	ifstream wej("ciagi.txt");
	ifstream wej2("bledne.txt");
	ofstream wyj("wyniki1.txt");
	ofstream wyj2("wyniki2.txt");
	ofstream wyj3("wyniki3.txt");
	int ile = 0;
	wyj << "1)\n";
	wyj2 << "2)\n";
	wyj3 << "3)\n";
	int maksroznica=0;
	for (int i = 1; i <=100; i++)
	{
		int n;
		wej >> n;
		int ciag[n];
		for(int j = 0; j < n; j++)
			wej >> ciag[j];
			
		int roznica = czyarytmetyczny(ciag, n);
		if (roznica)
		{
			ile++;
			maksroznica = max(maksroznica, roznica);
		}
		
		//2
		sort(ciag, ciag+n);
		for (int j = n-1; j >=0; j--)
		{
			if (czypotega3(ciag[j]))
				{
					wyj2 << ciag[j] << endl;
					break;
				}
		}
	}
	wyj<<"maks roznica: " << maksroznica << endl << "ile ciagow arytmetycznych: "<<ile << endl;
	for (int i = 1; i <=20; i++)
	{
		int n;
		wej2 >>n;
		int ciagi[n];
		for (int j = 0; j < n; j++)
			wej2 >> ciagi[j];
		int r1 = ciagi[1] - ciagi[0];
		int r2 = ciagi[2] - ciagi[1];
		int r3 = ciagi[3] - ciagi[2];
		int r;
		if (r1 == r2 || r1 == r3)
			r=r1;
		else if (r2 == r3)
			r = r2;
		for (int j = 2;  j < n; j++)
		{
			if (ciagi[j] - ciagi[j-2] != 2*r)
			{
				wyj3 << ciagi[j]<< endl;
				break;
			}
		}
	}
}
