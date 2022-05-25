#include <bits/stdc++.h>
using namespace std;	
int suma[200];
bool czypalindrom(string s)
{
	int x = s.size() -1;
	for (int i = 0; i <= s.size()/2; i++)
	{
		if (s[i] != s[x-i])
			return 0;
	}
	return 1;
}
int czypoprawny(string s)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		if (i % 3 == 0)
			sum += (s[i] - 'A' + 10)*7;
		else
		{
			if(i%3 == 1)
				sum += (s[i] - 'A' + 10)*3;
			else
				sum += (s[i] - 'A' + 10)*1;
		}
	}
	for (int i = 4; i < s.size(); i++)
	{
		if (i % 3 == 1)
			sum += (s[i] - '0')*7;
		else
		{
			if(i%3 == 2)
				sum += (s[i] - '0')*3;
			else
				sum += (s[i] - '0')*1;
		}
	}	
	sum= sum%10;
	return sum;
}
int main ()
{
	ifstream wej("identyfikator.txt");
	ofstream wyj1("wyniki4_1.txt");
	ofstream wyj2("wyniki4_2.txt");
	ofstream wyj3("wyniki4_3.txt");
	string id[200];
	int maks = 0;
	string seria[200], numer[200];
	for (int i = 0; i < 200; i++)
	{
		wej >> id[i];
		seria[i]="";
		numer[i]="";
		for (int j= 0; j < 3; j++)
		{
			seria[i]+=id[i][j];
		
		}
		for (int j = 3; j < id[i].size(); j++)
		{
			numer[i] +=id[i][j];	
			suma[i]+=id[i][j]-'0';
		}
		maks = max(maks, suma[i]);
	}
	for (int i = 0; i < 200; i++)
	{
		if (suma[i] == maks)
		{
			wyj1 << id[i] << "\n";
		}
	}
	for (int i = 0; i < 200; i++)
	{
		if (czypalindrom(seria[i]) == 1|| czypalindrom(numer[i]) == 1)
		{
			wyj2 << id[i] << endl;
		}
	}
	for (int i = 0; i < 200; i++)
	{
		if (czypoprawny(id[i]) != int(id[i][3]-'0'))
			wyj3 << id[i] << endl;
	}
	
}
