#include <bits/stdc++.h>
using namespace std;
int ileroznychliter(string s)
{
	int alfabet[26];
	for (int i = 0; i < 26; i++)
		alfabet[i] = 0;
	for (int i = 0; i < s.size(); i++)
	{
		alfabet[s[i] - 'A']++;
	}
	int ile = 0;
	for (int i = 0; i < 26; i++)
		if (alfabet[i] > 0)
			ile++;
	return ile;
}
int main ()
{
	ifstream wej("sygnaly.txt");
	ofstream wyj("wyniki4.txt");
	string sygnaly[1000];
	string s2 ="";
	for (int i = 0; i < 1000; i++)
	{
		wej >> sygnaly[i];
	}
	for (int i = 39; i < 1000; i+=40)
		s2 += sygnaly[i][9];
	wyj << "1)\n" << s2 << "\n\n";
	int maksliter = 0, ind = 0;
	for (int i = 0; i < 1000; i++)
	{
		int x = ileroznychliter(sygnaly[i]);
		if (x > maksliter)
		{
			maksliter = x;
			ind = i;
		}
	}
	wyj << "2)\n" << sygnaly[ind] <<" " << ileroznychliter(sygnaly[ind]) << "\n\n";
	wyj << "3)\n";
	for (int i = 0; i < 1000; i++)
	{
		char minlitera = sygnaly[i][0], makslitera = sygnaly[i][0];
		for (int j = 1; j < sygnaly[i].size(); j++)
		{
			minlitera = min(sygnaly[i][j], minlitera);
			makslitera = max(makslitera, sygnaly[i][j]);
		}
		if (makslitera - minlitera <= 10)
			wyj << sygnaly[i] << "\n";
	}
}
