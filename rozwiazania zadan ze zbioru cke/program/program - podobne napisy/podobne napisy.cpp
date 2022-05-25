#include <bits/stdc++.h>
using namespace std;	
ifstream wej("napisy.txt");
ofstream wyj("wyniki.txt");
int dlwspolne[201];
int czymoznadopisac(string s1, string s2)
{
	int dl = min(s1.size(), s2.size());
	for (int i = 0; i < dl; i++)
	{
		if (s1[i] != s2[i])
			return 0;
	}
	return dl;
}
void wypiszlitery (string s1, string s2, int p)
{
	if (s1.size() > s2.size())
	{
		for (int i = p; i <s1.size(); i++)
			wyj << s1[i];
	}
	else
	{
		for (int i = p; i <s2.size(); i++)
			wyj << s2[i];
	}
}
int dl_id_zak(string s1, string s2)
{
	int licz =  0;
	int ks1 = s1.size()-1, ks2 = s2.size()-1; 
	while (ks1 >=0 && ks2 >=0 && s1[ks1] == s2[ks2])
	{
		licz++;
		ks1--;
		ks2--;
	}
	return licz;
}
int main ()
{
	string napisy[201][2];
	bool czyjuz = 0;
	int ile3x = 0;
	string n1, n2;
	for (int i = 1; i <= 200; i++)
	{
		for (int j = 0; j <2; j++)
			wej >> napisy[i][j];
		if (napisy[i][0].size() >= 3*napisy[i][1].size() || napisy[i][1].size() >= 3*napisy[i][0].size())
		{
			if (!czyjuz)
			{
				n1 = napisy[i][0];
				n2 = napisy[i][1];
				czyjuz = 1;
			}
			ile3x++;
		}
	}
	int makszakwspolne = 0;
	wyj << "1)\n" << ile3x << "\n" << n1 << " " << n2 << "\n\n";
	wyj << "2)\n";
	for (int i = 1; i <= 200; i++)
	{
		if (czymoznadopisac(napisy[i][0], napisy[i][1]))
		{
			wyj << napisy[i][0] << " " << napisy[i][1] << " ";
			wypiszlitery(napisy[i][0], napisy[i][1], czymoznadopisac(napisy[i][0], napisy[i][1]));
			wyj << "\n";
		}
		dlwspolne[i] = dl_id_zak(napisy[i][0], napisy[i][1]);
		makszakwspolne = max(makszakwspolne, dlwspolne[i]);
	}
	wyj << "\n3)\n"; 
	wyj << makszakwspolne << "\n";
	for (int i = 1; i <= 200; i++)
	{
		if (dlwspolne[i] == makszakwspolne)
		{
			wyj << napisy[i][0] << " " << napisy[i][1] << "\n";
		}
	}
	
	
}
