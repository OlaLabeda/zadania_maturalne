#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int main ()
{
	ifstream wej1("dane1.txt");
	ifstream wej2("dane2.txt");
	ofstream wyj1("wynik4_1.txt");
	ofstream wyj2("wyniki4_2.txt");
	ofstream wyj3("wyniki4_3.txt");
	ofstream wyj4("wyniki4_4.txt");
	int t1[1000][10], t2[1000][10];
	int ile = 0;
	int ilep1 =0, ilep2 =0, ileodp = 0;
	int policz3 = 0;
	int t3[1000][20];
	for (int i = 0; i < 1000; i++)
	{
		bool liczby1[101], liczby2[101];
		bool czyzgodne = 1;
		for (int j = 0; j < 101; j++)
			{
				liczby1[j] = 0;
				liczby2[j] = 0;
			}
		for (int j = 0; j < 10; j++)
		{
			wej1 >> t1[i][j];
			liczby1[t1[i][j]] = 1;
			t3[i][j] = t1[i][j];
			wej2 >> t2[i][j];
			liczby2[t2[i][j]] = 1;
			t3[i][j+10] = t2[i][j];
			if (t1[i][j] %2 == 0)
				ilep1++;
			if (t2[i][j] %2 == 0)
				ilep2++;
		}
		if (t1[i][9] == t2[i][9])
			ile++;
		if (ilep1 == 5 && ilep2 == 5)
			ileodp++;
		ilep1 =0;
		ilep2 =0;
		for (int j = 0; j < 101; j++)
		{
			if (liczby1[j] != liczby2[j])
			{
				czyzgodne = 0;
				break;
			}
		}
		if (czyzgodne)
		{
			policz3++;
			v.push_back(i+1);
		}
		sort(t3[i], t3[i] + 20);
		for (int j = 0; j < 20; j++)
		{
			wyj4 << t3[i][j] << " ";
		}
		wyj4 << endl;
	}
	wyj1 << ile;
	wyj2 << ileodp;
	wyj3 << policz3 << endl;
	for (int i =0; i < v.size(); i++)
	wyj3 << v[i] << " ";
	
}
