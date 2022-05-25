#include <bits/stdc++.h>
using namespace std;
int alfabet[26];
int zlicz[2000];
int main ()
{
	ifstream wej("instrukcje.txt");
	ofstream wyj("wyniki4.txt");
	string instrukcje[2000];
	string s ="";
	int ind = 0;
	int maksalfabet = 0;
	for (int i = 0; i < 2000; i++)
	{
		string polecenie;
		char znak;
		wej >> polecenie >> znak;
		instrukcje[i] = polecenie;
		if (polecenie == "DOPISZ")
		{
			alfabet[znak -'A'] ++;
			maksalfabet = max(alfabet[znak-int('A')], maksalfabet);
			if (ind  == s.size())
			{
				s+=znak;
				ind ++;
			}
			else
			{
				s[ind] = znak;
				ind++;
			}
		}
		else if (polecenie == "ZMIEN")
		{
			s[ind - 1] = znak;	
		}
		else if (polecenie == "USUN")
		{
			s[ind] = '0';
				ind --;
		}
		else if (polecenie == "PRZESUN")
		{
			for (int i = 0; i < ind; i++)
			{
				if (s[i] == znak)
				{
					if (s[i] == 'Z')
						s[i] = 'A';
					else
						s[i] = char(s[i] + 1);
					break;
				}
			}
		}
	}
	wyj << "1)\n" << ind << "\n";
	zlicz[0] = 1;
	int makszlicz = 0;
	for (int i = 1; i < 2000; i++)
	{
		if (instrukcje[i] == instrukcje[i-1])
			zlicz[i] = zlicz[i-1] + 1;
		else 
			zlicz[i] = 1;
			makszlicz = max(makszlicz, zlicz[i]);
	}
	for (int i = 0; i < 2000; i++)
	{
		if (zlicz[i] == makszlicz)
		{
			wyj << "\n2)\n" << instrukcje[i] << " " << zlicz[i] << "\n";
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (alfabet[i] == maksalfabet)
		{
			wyj << "\n3)\n" << char( 'A' + i)<< " " << alfabet[i] << "\n";
		}
	}
	wyj << "\n4)\n" << s;
}
