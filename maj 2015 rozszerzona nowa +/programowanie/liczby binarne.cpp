#include <bits/stdc++.h>
using namespace std;
int main ()
{
	ifstream wej("liczby.txt");
	ofstream wyj("wyniki4.txt");
	string liczby[1000];
	for (int i = 0; i < 1000; i++)
	{
		wej >> liczby[i];
	//	cout << liczby[i]<< endl;
	}
	
	//4.1)
	int ilezer[1000], ilejedynek[1000];
	int ilemawiecej = 0;
	for (int i = 0; i < 1000; i++)
	{
		ilezer[i]=0;
		ilejedynek[i]=0;
		for (int j =0; j < liczby[i].size(); j++)
		{
			if (liczby[i][j]=='0')
				ilezer[i]++;
			else
				ilejedynek[i]++;
		}
		if (ilezer[i] > ilejedynek[i])
		{
			ilemawiecej++;
		}
	}
	wyj << "4.1\n" << ilemawiecej << endl<< endl;
	
	
	//4.2)
	//podzielne przez 8 => ostatnie 3 cyfry liczby w zapisie binarnym sa zerami i dlugosc liczby jest wieksza niz 3
	//cala reszta to potencjalne wielokrotnosci 8
	//podzielne przez dwa jesli dlugosc >= 2 i ostatnia cyfra jest zerem
	int ilepodz8 = 0, ilepodz2 = 0;
	for (int i = 0; i <1000; i++)
	{
		int dl = liczby[i].size();
		if (dl >= 2)
		{
			if (liczby[i][dl-1] == '0')
				ilepodz2 ++;
		}
		if (dl > 3)
		{
			if (liczby[i][dl-1] == '0' && liczby[i][dl-2]=='0' && liczby[i][dl-3] == '0')
				ilepodz8++;
		}
	}
	wyj << "4.3\n" <<"podzielne przez 2: " <<  ilepodz2 << endl <<"podzielne przez 8: "<< ilepodz8<< endl;
	
	//4.3)
	int dlmaks = liczby[0].size();
	int dlmin = dlmaks;
	string najdluzsza = "0";
	string najkrotsza = liczby[0];
	for (int i = 1; i <1000; i++)
	{
		dlmaks = max( dlmaks, int(liczby[i].size()) );	
		dlmin = min( dlmin, int(liczby[i].size()) );
	}
	int wierszdl = 0;
	int wierszkr = 0;
	for (int i = 0; i < 1000; i++)
	{
		if ( liczby[i].size() == dlmaks)
		{
			int j = 0;
			while (liczby[i][j] == najdluzsza[j])
				j++;
			if (liczby[i][j] == '1')
			{
				wierszdl = i + 1;
				najdluzsza = liczby[i];
			}
		}
		if (dlmin == liczby[i].size())
		{
			int j = dlmin-1;
			while (liczby[i][j] == najkrotsza[j])
				j--;
			if (liczby[i][j] == '0')
			{
				wierszkr = i + 1;
				najkrotsza = liczby[i];
			}
		}
	}
	wyj << "\n4.3\n";
	wyj << "najkrotsza w wierszu: " << wierszkr << endl;
	wyj << "najdluzsza w wierszu: " << wierszdl << endl;
}
