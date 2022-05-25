#include <bits/stdc++.h>
using namespace std;
int czywiecejzer (string s)
{
	int jedynki = 0, zera = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')
			jedynki ++;
		else
			zera ++;
	if (zera > jedynki)
		return 1;
	return 0;
}
bool czypodz2(string s)
{
	if (s[s.size()-1] == '0')
		return 1;
	return 0;
}
bool czypodz8(string s)
{
	for (int j = s.size() -1; j >= s.size() - 3; j--)
		if (s[j] != '0')
			return 0;
	return 1;
	
}
int main ()
{
	ifstream wej("liczby.txt");
	ofstream wyj("wyniki4.txt");
	string liczby[1000];
	for (int i = 0; i < 1000; i++)
		wej >> liczby[i];
	int policz = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (czywiecejzer(liczby[i]))
			policz++;
	}
	wyj << "1)\n" << policz << "\n\n";
	int ile2 = 0, ile8=0;
	for (int i = 0; i < 1000; i++)
	{
		
		if (czypodz8(liczby[i]))
				ile8++;
		if (czypodz2(liczby[i]))
			ile2++;
	}
	wyj << "2)\npodzielne przez 2: "<< ile2 << "\npodzielne przez 8: " << ile8<< "\n\n";
	string mini = liczby[0], maksi = liczby[0];
	int indmini = 0, indmaksi = 0;
	for (int i = 1; i < 1000; i++)
	{
		if (liczby[i].size() <= mini.size())
			if (liczby[i] < mini)
			{
				mini = liczby[i];
				indmini = i;
			}
		if (liczby[i].size() >= maksi.size())
			if (liczby[i] > maksi)
			{
				maksi = liczby[i];
				indmaksi = i;
			}
	}
	wyj << "3)\n" << "mini: " << indmini +1<< " maksi: " << indmaksi +1;
}
