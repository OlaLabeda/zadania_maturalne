#include <bits/stdc++.h>
using namespace std;
int main ()
{
	ifstream wej("sygnaly.txt");
	ofstream wyj("wyniki4.txt");
	string sygnaly[1000];
	string przeslanie = "";
	for (int i = 0; i <  1000; i++)
	{
		wej >> sygnaly[i];
		//cout << sygnaly[i] << endl;
	}
	for (int i = 39; i < 1000; i+=40)
	{
		przeslanie += sygnaly[i][9];
	}
	wyj << "1)\n" << przeslanie << "\n\n";
	int maksliter = 0; string maksslowo;
	for (int i = 0; i < 1000; i++)
	{
		int alfabet[27];
		for (int j = 0; j < 27; j++)
		{
			alfabet[j] = 0;
		}
		for (int j = 0; j < sygnaly[i].size(); j++)
		{
			alfabet[sygnaly[i][j]-'A']++;
		}
		int ileroznych = 0;
		for (int i = 0; i < 27; i++)
		{
			if (alfabet[i] > 0)
				ileroznych ++;
		}
		
		if (ileroznych > maksliter)
		{
			maksliter  = ileroznych;
			maksslowo = sygnaly[i];
		}
	}
	wyj << "2)\n" << maksslowo << " " << maksliter << "\n\n";
	wyj << "3)\n";
	for (int i = 0; i < 1000; i++)
	{
		char minlitera = sygnaly[i][0], makslitera = sygnaly[i][0];
		for (int j = 1; j < sygnaly[i].size(); j++)
		{
			if (minlitera > sygnaly[i][j])
				minlitera = sygnaly[i][j];
			if (makslitera < sygnaly[i][j])
				makslitera = sygnaly[i][j];
		}
		if (makslitera - minlitera <= 10)
			wyj << sygnaly[i] << endl;
		
	}
	
}
