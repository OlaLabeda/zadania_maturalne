#include <bits/stdc++.h>
using namespace std;
string szyfruj (string s, int k)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i]+=k;
		if (s[i] > 'Z')
			s[i] -=26;
	}
	return s;
}
string deszyfruj (string s, int k)
{
	for (int i = 0; i < s.size(); i++)
	{
		s[i]-=k;
		if (s[i] < 'A')
			s[i]+=26;
	}
	return s;
}
string bledy (string s1, string s2)
{
	for (int i = 1; i <=27; i++)
	{
		if (szyfruj(s1, i%26) == s2)
		{
			return "0";
		}
	}
	return s1;
}
int main ()
{
	ifstream wej1("dane_6_1.txt");
	ifstream wej2("dane_6_2.txt");
	ifstream wej3("dane_6_3.txt");
	ofstream wyj1("wyniki_6_1.txt");
	ofstream wyj2("wyniki_6_2.txt");
	ofstream wyj3("wyniki_6_3.txt");
	int k = 107;
	k %= 26;
	for (int i = 0; i < 100; i++)
	{	
		string slowo;	
		wej1 >> slowo;
		wyj1 << szyfruj(slowo, k) << "\n";	
	}
	for (int i = 0; i < 3000; i++)
	{
		int k;
		string slowo;
		wej2 >> slowo >> k;
		k%=26;
		wyj2 << deszyfruj(slowo, k) << "\n";	
	}
	for (int i = 0; i < 3000; i++)
	{
		string s1, s2;
		wej3 >> s1 >>s2;
		string s = bledy(s1, s2);
		if (s!="0")
			wyj3 << s<< endl;
	}
	
}
