#include <bits/stdc++.h>
using namespace std;
int main ()
{
	ifstream wej1("dane1.txt");	
	ifstream wej2("dane2.txt");
	ofstream wyj1("wyniki4_1.txt");
	ofstream wyj2("wyniki4_2.txt");
	ofstream wyj3("wyniki4_3.txt");
	ofstream wyj4("wyniki4_4.txt");
	int t1[1000][10], t2[1000][10];
	int ileost = 0, ilepar = 0;
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 10; j++)
		{
			wej1 >> t1[i][j];	
			wej2 >> t2[i][j];
		}

	for (int i = 0; i < 1000; i++)	
		if (t1[i][9] == t2[i][9])
			ileost++;
			
	wyj1<< ileost;
	int ilewierszy = 0;
	wyj3 << "numery wierszy: \n";
	for (int i = 0; i < 1000; i++)
	{
		int tabpom[20];
		
		int p1 = 0, p2 = 0, np1 =0, np2 = 0;
		bool czywystapila1[101], czywystapila2[101];
		for (int j= 0; j <= 100; j++)
		{
			czywystapila1[j] = 0;
			czywystapila2[j] = 0;
		}
		for (int j = 0; j < 10; j++)
		{
			tabpom[j] = t1[i][j];
			if (t1[i][j] % 2 == 0)
				p1++;
			else
				np1++;
			if (t2[i][j] % 2 == 0)
				p2++;
			else
				np2++;
			czywystapila1[t1[i][j]] = 1; 
			czywystapila2[t2[i][j]] = 1; 
		}
		for (int j = 10; j < 20; j++)
		{
			tabpom[j] = t2[i][j-10]; 
		}
		sort(tabpom, tabpom+20);
		for (int j = 0; j < 20; j++)
		wyj4 << tabpom[j] << " ";
		wyj4 << endl;
		bool czytesame = 1;
		for (int j = 0; j <= 100; j++)
		{
			if (czywystapila1[j] != czywystapila2[j])
			{
				czytesame = 0;
				break;
			}
		}
		if (czytesame)
		{
			ilepar ++;
			wyj3 << i+1 << endl;
		}
		if (p1 == 5 && p2 == 5)
			ilewierszy++;
	}
	wyj2 << ilewierszy << endl;
	wyj3 << "liczba par: " << ilepar;
}
