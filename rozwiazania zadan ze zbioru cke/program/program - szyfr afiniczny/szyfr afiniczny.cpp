#include <bits/stdc++.h>
using namespace std;
string szyfruj(string s, int a, int b)
{
	for (int i = 0; i < s.size(); i++)
	{
		int l = s[i] - 'a';
		l *= a;
		l += b;
		l%=26;
		s[i] = char(l+97);
		
	}
	return s;
}
int main ()
{
	ifstream wej1("tekst.txt");
	ifstream wej2("probka.txt");
	ofstream wyj("wyniki.txt");
	string slowa[805];

	wyj << "1)\n";
	for (int i = 0; i < 805; i++)
	{
		wej1 >> slowa[i];
		if (slowa[i][0] == 'd' && slowa[i][slowa[i].size()-1] == 'd')
			wyj << slowa[i] << "\n";
	}
	wyj << "\n2)\n";
	for (int i = 0; i < 805; i++)
	{
		if (slowa[i].size() >= 10)
			wyj << szyfruj(slowa[i], 5, 2) << "\n";
	}
	wyj << "\n3)\n";
	string proba[5][2];
	for (int i = 0; i < 5; i++)
	{
		for (int j =0; j < 2; j++)
		{
			wej2 >> proba[i][j];
		}
		for (int l = 0; l < 26; l++)
		{
			for (int k = 0; k < 26; k++)
			{
				if (szyfruj(proba[i][0],l, k) == proba[i][1])
				{
					wyj << l << " " << k << "\n";
					break;
				}
			}
		}
	}
}
