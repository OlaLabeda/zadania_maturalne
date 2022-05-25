#include <bits/stdc++.h>
using namespace std;
int liczbaliter, sumaliter[27], makspodslowo[1877];
string samogloski="AEOUYI";
bool czy2kolejneidentyczne (string s)
{
	for (int i = 1; i < s.size(); i++)
		if (s[i] == s[i-1])
			return 1;
	return 0;
}
void dodaj(string s)
{
	for (int i =0; i < s.size(); i++)
	{
		if (s[i]!=' ')
			liczbaliter++;
		sumaliter[int(s[i])-64]++;
	}
}
bool czysamogloska (char s)
{
	for (int j = 0; j < 6; j++)
		if (s == samogloski[j])
			return 1;
	return 0;
}
void makspod (int k, string s)
{
	makspodslowo[k] = 0;
	int makslok = 0, maksglob = 0;
	for (int i =0; i < s.size(); i++)
	{
		if (!czysamogloska(s[i]))
			makslok++;
		else
		{
			maksglob=max(makslok, maksglob);
			makslok=0;
		}
	}
	maksglob = max(maksglob, makslok);
	makspodslowo[k] = maksglob;
}
int main ()
{
	ifstream wej("tekst.txt");
	ofstream wyj("wyniki.txt");
	string slowa[1877];
	int ilezdwojka = 0;
	for (int i =0; i <= 26; i++)
		sumaliter[i] = 0;
	for (int i = 1; i <= 1876; i++)
	{
		wej >> slowa[i];
		if (czy2kolejneidentyczne(slowa[i]))
			ilezdwojka++;
		dodaj(slowa[i]);
		makspod(i, slowa[i]);
	}
	wyj << "1)\n" << ilezdwojka << "\n\n";
	wyj << "2)\n";
	for (int i = 1; i <= 26; i++)
		wyj << char(i+64) << ": " <<sumaliter[i] << " "<< setprecision(3) << 100*sumaliter[i]*1.0/liczbaliter*1.0<< "%\n";
	wyj << "\n\n";
	int makspodslowoever = 0;
	for (int i = 1; i <= 1876; i++)
		makspodslowoever = max(makspodslowoever, makspodslowo[i]);
		
	wyj << "3)\n" << makspodslowoever<< "\n";
	int zlicz  = 0;
	string s;
	for (int i =1; i <= 1876; i++)
	{
		if (makspodslowo[i]==makspodslowoever)
		{
			if (zlicz==0)
				s = slowa[i];
			zlicz++;
		}	
	}
	wyj << zlicz << "\n" << s ;
}
