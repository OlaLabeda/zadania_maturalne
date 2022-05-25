#include <bits/stdc++.h>
using namespace std;
int maks = 0;
int dlugosci[503];
string czesckodujaca[1001], czesckodujacaodwrocona[1001];
int dlkod[1001];
int znajdzgen (string s, int p)
{	
	if (s[p] != 'A' || s[p+1] != 'A')
		return 0;
	for (int i = p+2 ; i < s.size()-1; i++)
		if (s[i] == 'B' && s[i+1] == 'B')
			return i+1;
	return 0;
}
bool czybcddc(string s)
{
	string wzorzec = "BCDDC";
	if (s.size() < 5) return 0;
	for (int i = 0; i <= s.size() - 5; i++)
	{
		int pom = znajdzgen(s, i);
		if (pom)
		{
			for (int k = i+2; k <=pom-6; k++)
			{
				bool czy = 1;
				for (int j = 0; j < wzorzec.size(); j++)
				{
					if (s[k+j] != wzorzec[j])
					czy = 0;
				}
				if (czy)
					return 1;
			}
		}
	}
	return 0;
}
string odwrotka(string s)
{
	string s2 = s;
	int pocz = 0;
	for (int j = s.size()-1; j>=0; j --)
	{
		s2[pocz] = s[j];
		pocz++;
	}
	return s2;
}
int ilegenow (string s, int i, string *czesckod)
{
	czesckod[i] = "";
	int ile = 0;
	int p = 0;
	while (p < s.size()-3)
	{
		if (s[p] == 'A')
		{
			int pom = znajdzgen(s, p);
			if (pom)
			{
				for (int j = p; j <=pom; j++)
					czesckod[i]+=s[j];
				maks = max(maks, pom-p+1);
				p = pom + 1;
				ile++; 
			}
			else p++;
		}
		else
		p++;
	}
	return ile;
}
bool czypalindrom (string s)
{
	int dl = s.size();
	int k = dl/2;
	for (int i =0; i < k; i++)
		if (s[i]!=s[dl-i-1])
			return 0;
	return 1;
}
int main ()
{
	ifstream wej("dane_geny.txt");
	ofstream wyj("wyniki.txt");
	string genotyp[1001];
	for (int i = 0; i <= 501; i++)
		dlugosci[i] = 0;
	for (int i = 1; i <= 1000; i++)
		{
			wej >> genotyp[i];
			dlugosci[genotyp[i].size()]++;
		}
	int maksgatunku = 0, liczbagatunkow = 0;
	for (int i = 1; i <= 500; i++)
	{
		if (dlugosci[i] > 0)
			liczbagatunkow++;
		maksgatunku = max(maksgatunku, dlugosci[i]);
	}	
	wyj <<"1)\n" <<maksgatunku << "\n" << liczbagatunkow << "\n\n";
	
	int ilemutacji = 0;
	for (int i = 1; i <=1000; i++)
	{
		if (czybcddc(genotyp[i]))
			ilemutacji++;
	}
	wyj << "2)\n" << ilemutacji << "\n";
	
	int maksliczbagenow = 0;
	int ileodpornych = 0, ilesilnieodpornych = 0;
	for (int i = 1; i <= 1000; i++)
	{
		maksliczbagenow = max(maksliczbagenow, ilegenow(genotyp[i], i, czesckodujaca));
		string s2 = odwrotka(genotyp[i]);
		ilegenow(s2, i, czesckodujacaodwrocona);	
		if (czesckodujaca[i] == czesckodujacaodwrocona[i])
			ileodpornych++;
		if (czypalindrom(genotyp[i]))
			ilesilnieodpornych++;
	}
	wyj << "\n3)\n"<<maksliczbagenow << "\n" << maks << "\n";
	
	wyj << "\n4)\n" << ileodpornych << "\n" << ilesilnieodpornych;
}
