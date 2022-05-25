#include <bits/stdc++.h>
using namespace std;
int policz[26];
int ileliter = 0;
string szyfruj (string s, string k)
{
	string w = s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			w[i] = s[i] + k[i] - 'A';
			if (w[i] > 'Z')
				w[i] -= 26;
		}
	}
	return w;
}
string deszyfruj (string s, string k)
{
	string w = s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			w[i] = s[i] - k[i] + 'A';
			if (w[i] < 'A')
				w[i] += 26;
		}
	}
	return w;
}
void policzlitery (string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			policz[s[i] - 'A']++;
			ileliter ++;
		}
	}
}
int main ()
{
	ifstream wej("dokad.txt");
	ifstream wej2("szyfr.txt");
	ofstream wyj("Vigenere_wyniki.txt");
	string s1, t1, k1 = "LUBIMYCZYTAC", s2, t2, k2;
	int ind = 0;
	getline(wej, s1);
	getline(wej2, s2); 
	getline(wej2, k2);
	t1 = s1;
	t2 = s2;
	int czydodac = 0;
	
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			t1[i] = k1[ind % k1.size()];
			ind++;
		}
	}	
	if (ind%k1.size()!=0) czydodac++;
	wyj << "1)\n" << czydodac + ind / k1.size() <<" \n";
	wyj << szyfruj(s1, t1) << "\n\n";
	
	ind  = 0;
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i] >= 'A' && s2[i] <= 'Z')
		{
			t2[i] = k2[ind % k2.size()];
			ind++;
		}
	}
	wyj << "2)\n" << deszyfruj(s2, t2) << "\n\n";
	policzlitery(s2);
	long int lsum = 0, nil = ileliter*(ileliter-1);
	wyj << "3)\n";
	for (int i = 0; i < 26; i ++)
	{
		wyj << char('A'+i) << " "<< policz[i] << "\n";
		lsum += policz[i] * (policz[i] - 1);
	}
	wyj << "szacowany klucz: " << fixed << (setprecision(2)) << 0.0285/(lsum*1.0/nil*1.0 - 0.0385) << "\n" << "wlasciwy klucz: " << k2.size();
	
}
