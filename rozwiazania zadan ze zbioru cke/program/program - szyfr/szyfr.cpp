#include <bits/stdc++.h>
using namespace std;
int main ()
{
	ifstream wej1("szyfr1.txt");
	ofstream wyj1("wyniki_szyfr1.txt");
	ifstream wej2("szyfr2.txt");
	ofstream wyj2("wyniki_szyfr2.txt");
	ifstream wej3("szyfr3.txt");
	ofstream wyj3("wyniki_szyfr3.txt");
	string szyfr1[6];
	int klucz1[50];
	for (int i = 0; i < 6; i++)
		wej1 >> szyfr1[i];
	for (int i = 0; i < 50; i++)
	{
		wej1 >> klucz1[i];
		for(int j = 0; j < 6; j++) 
			swap(szyfr1[j][i], szyfr1[j][klucz1[i]-1]);
	}
	for (int i = 0; i < 6; i++)
		wyj1 << szyfr1[i] << "\n";
	string s2;
	int klucz2[15];
	wej2 >> s2;
	for (int i = 0; i < 15; i++)
		wej2 >> klucz2[i];
	for (int i = 0; i < 50; i++)
		swap(s2[i], s2[klucz2[i%15]-1]);
	wyj2 << s2;
	string s3;
	wej3 >> s3;
	int klucz3[6] = {6,2,4,1,5,3};
	for (int i = 49; i >=0; i--)
	{
		swap(s3[i], s3[klucz3[i%6]-1]);
	}
	wyj3 << s3;
	
}
