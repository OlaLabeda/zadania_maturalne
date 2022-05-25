#include <bits/stdc++.h>
using namespace std;
bool czypalindrom(string s)
{
	if (s[0] == s[2]) return 1;
	if (s[3] == s[8] && s[4] == s[7] && s[5] == s[6])
		return 1;
		return 0;
}
bool czypoprawny(string s)
{
	string s2 = "";
	for (int i = 4; i < s.size(); i++)
		s2+=s[i];
	int suma = 0;
	suma += (s[0] -'A' +10)*7;
	suma += (s[1] -'A' +10)*3;
	suma += s[2] -'A' +10;
	for (int i = 0; i < s2.size(); i++)
	{
		if (i%3 == 0)
		suma += (s2[i]-'0')* 7;
		if (i%3 == 1)
		suma += (s2[i]-'0')* 3;
		if (i%3 == 2)
		suma += (s2[i]-'0')* 1;
		
	}
	if (suma%10 == s[3] -'0')
		return 1;
		return 0;
}
int main ()
{
	ifstream wej("identyfikator.txt");
	ofstream wyj("wyniki4_1.txt");
	ofstream wyj2("wyniki4_2.txt");
	ofstream wyj3("wyniki4_3.txt");
	string id[200];
	int sumacyfr[200];
	int makssuma = 0;
	for (int i = 0; i < 200; i++)
	{
		wej >> id[i];
		sumacyfr[i]=0;
		for (int j = 3; j < 9; j++)
		{
			sumacyfr[i] += id[i][j] - '0';
		}
		makssuma = max(makssuma, sumacyfr[i]);
		//cout << id[i] <<" " << sumacyfr[i] << endl;
	}
	for (int i = 0; i < 200; i++)
	{
		if (sumacyfr[i] == makssuma)
			wyj << id[i] << endl;	
	}
	for (int i = 0; i < 200; i++)
	{
		if (czypalindrom(id[i]))
			wyj2 << id[i] << endl;
	}
	for (int i = 0; i < 200; i++)
	{
		if (czypoprawny(id[i]) == 0)
			wyj3 << id[i] << endl;
	}
}
