#include <bits/stdc++.h>
using namespace std;
bool czypalindrom(int p, int q, string s)
{
	while (p <= q)
	{
		if (s[p] == s[q])
		{
			p++;
			q--;
		}
		else
			return 0;
	}
	return 1;
}
int main ()
{
	ifstream wej("identyfikator.txt");
	ofstream wyj("wyniki_4.txt");
	string id[200];
	long long suma[200];
	int kontrolna[200];
	int spr[200];
	for (int i = 0; i < 200; i++)
	{
		suma[i] = 0;
		wej >> id[i];
		kontrolna[i] = id[i][3] - 48;
		for (int j = 3; j <= 8; j++)
		{
			suma[i] += id[i][j] - 48;
		}
	}
	
	long long maks = 0;
	
	for (int i = 0; i<200; i++)
		maks = max(maks, suma[i]);
		
	wyj << "4.1\n";
	for (int i = 0; i< 200; i++)
	{
		if (suma[i] == maks)
			wyj << id[i]<< "\n";
	}
	
	wyj << "\n4.2\n";
	for (int i = 0; i < 200; i++)
	{
		if (czypalindrom(0, 2, id[i]) == 1 || czypalindrom(3, 8, id[i]) == 1 )
			wyj << id[i] << "\n";
	}
	
	///NIEPOPRAWNE identyfikatory
	wyj << "\n4.3\n";
	for (int i = 0; i < 200; i++)
	{
		spr[i] = 7*(int(id[i][0])-55)+7*(int(id[i][4])-48)+7*(int(id[i][7])-48)+3*((id[i][1])-55)+3*((id[i][5])-48)+3*((id[i][8])-48)+int(id[i][2])-55+int(id[i][6])-48;
		spr[i] %= 10;
		if (spr[i] != kontrolna[i])
			wyj << id[i] << "\n";
		
	}
}
