#include <bits/stdc++.h>
using namespace std;
string szyfruj(string s, int k)
{
	k %= 26;
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = s[i] + k;
		if (s[i] > 90)
			s[i] -=26;
	}
	return s;
}
string deszyfruj(string s, int k)
{
	k %= 26;
	for (int i = 0; i < s.size(); i++)
	{
		s[i] -= k;
		if (s[i] < 65)
			s[i]+=26;
	}
	return s;
}
int main ()
{
	ifstream wej1("dane_6_1.txt");
	ifstream wej2("dane_6_2.txt");
	ifstream wej3("dane_6_3.txt");
	ofstream wyj1("wyniki_6_1.txt");
	ofstream wyj2("wyniki_6_2.txt");
	ofstream wyj3("wyniki_6_3.txt");
	string slowa[100];
	for (int i = 0; i <  100; i++)
	{
		wej1 >> slowa[i];
		wyj1 << szyfruj(slowa[i], 107)<< endl;
	}
	for (int i = 0; i < 3000; i++)
	{
		string s;
		int k;
		wej2 >> s >> k;
		wyj2 << deszyfruj(s, k) << endl;
	}
	for (int i = 0; i < 3000; i++)
	{
		string s1, s2;
		wej3 >> s1 >> s2;
		int k = (s2[0] - s1[0] +26 )%26;
		if (szyfruj(s1, k) != s2)
			wyj3 << s1 << endl;
	}
} 
