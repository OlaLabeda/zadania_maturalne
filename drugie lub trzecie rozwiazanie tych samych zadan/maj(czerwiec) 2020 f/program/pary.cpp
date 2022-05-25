#include <bits/stdc++.h>
using namespace std;
bool czypierwsza(int x)
{
	for (int i = 2; i*i<=x; i++)
	{
		if(x%i == 0)
			return 0;
	}
	return 1;
}
int main ()
{
	ifstream wej("pary.txt");
	ofstream wyj("wyniki4.txt");
	int liczba[100]; string slowo[100];
	for (int i = 0; i < 100; i++)
	{
		wej >> liczba[i] >>slowo[i];
		//cout << liczba[i] << " " << slowo[i] << endl;
	}
	wyj << "1)\n";
	for (int i = 0; i < 100; i++)
	{
		if (liczba[i] %2 == 0)
		{
			wyj << "liczba: " << liczba[i] << " ";
			for (int j = 3; j < liczba[i]; j++)
			{
				if (czypierwsza(j) && czypierwsza(liczba[i] - j))
				{
					wyj << j << " " << liczba[i] - j << endl;
					break;
				}
			}
		}
	}
	wyj << "\n\n2)\n";
	for (int i = 0; i < 100; i++)
	{
		int dlmaks = 0, dllok =1; 
		int ind = 0;
		string s = slowo[i];
		for (int j = 1; j < s.size(); j++)
		{
			if (s[j] == s[j-1])
			{
				dllok++;
			}
			else
			{
				if (dllok > dlmaks)
				{
					dlmaks = dllok;
					ind = j-1;
				}
				dllok = 1;
			}
		}
		
		for (int j = ind - dlmaks+1; j <= ind; j++)
			wyj << s[j];
			wyj << " ";
		wyj << dlmaks << endl;	
	}
	int minliczba = 1515;
	string minslowo;
	for (int i = 0; i < 100; i++)
	{
		if (liczba[i] == slowo[i].size())
		{
			if (liczba[i] < minliczba)
			{
				minliczba = liczba[i];
				minslowo = slowo[i];
			}
			else if (liczba[i] == minliczba)
			{
				int minsize = min(slowo[i].size(), minslowo.size());
				for (int j = 0; j < minsize; j ++)
				{
					if (slowo[i][j] < minslowo[j])
					{
						minslowo = slowo[i];
						break;
					}
				}
			}
		}
	}
	wyj << "\n\n3)\n" << minliczba << " " << minslowo;
}
