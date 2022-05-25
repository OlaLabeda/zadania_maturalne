#include <bits/stdc++.h>
using namespace std;
bool czypalindrom (string s)
{
	int p = s.size()-1;
	for (int i = 0; i <= s.size()/2; i++)
	{
		if (s[i] != s[p-i])
			return 0;
	}
	return 1;
}
char literka (string s)
{
	string s1 = s[s.size()-1] + s;
	string s2 = s + s[0];
	if (czypalindrom(s1))
		return s1[25];
	if (czypalindrom(s2))
		return s2[25];
	return '-';
}
int main ()
{
	ifstream wej("napisy.txt");
	ofstream wyj("wyniki4.txt");
	string napisy[1000];
	int ilecyfr = 0;
	for (int i = 0; i < 1000; i++)
	{
		wej >> napisy[i];
		for (int j = 0; j < napisy[i].size(); j++)
		{
			if (napisy[i][j] >= '0' && napisy[i][j] <= '9')
				ilecyfr++;
		}
	}
	wyj << "1)\n" << ilecyfr << "\n\n";
	int pozycja = 0;
	string haslo = "";
	for (int i = 19; i < 1000; i+=20)
	{
		haslo += napisy[i][pozycja];
		pozycja++;
	}
	wyj << "2)\n" << haslo << "\n\n3)\n";
	
	for (int i = 0; i < 1000; i++)
	{
		char c = literka(napisy[i]);
		if (c !='-')
		wyj << c ;
	}
	wyj << "\n\n4)\n";
	int ilex = 0;
	string osthaslo="";
	for (int i = 0; i < 1000; i++)
	{
		int pary = 2;
		int cyfra = 0;
		for(int j = 0; j < napisy[i]. size(); j++)
		{
			if (napisy[i][j] >= '0' && napisy[i][j] <='9')
			{
				pary --;
				cyfra += (napisy[i][j]-'0')*pow(10, pary);
			}
			if (pary == 0)
			{
				if (cyfra >= 65 && cyfra <= 90)
				{
					osthaslo+=char(cyfra);
					if (char(cyfra) == 'X')
						ilex++;
					if (ilex == 3)
					{
						wyj  << osthaslo;	
						break;	
					}
				}
				pary = 2;
				cyfra = 0;
			}
		}
		if (ilex == 3)
			break;
	}
}
