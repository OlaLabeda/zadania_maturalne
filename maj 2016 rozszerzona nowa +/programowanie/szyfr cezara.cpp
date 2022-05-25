#include <bits/stdc++.h>
using namespace std;
int main ()
{
	ifstream wej("dane_6_1.txt");
	ofstream wyj("wyniki_6_1.txt");
	ifstream wej1("dane_6_2.txt");
	ofstream wyj1("wyniki_6_2.txt");	
	ifstream wej2("dane_6_3.txt");
	ofstream wyj2("wyniki_6_3.txt");
		
	//wczytanie, podpunkt pierwszy => classic caesar cipher
	for (int i = 0; i < 100; i ++)
	{
		string s;
		wej >> s;
		
		for (int j = 0; j < s.size(); j++)
		{
			wyj << char( 65 + (s[j] - 65 + 107) % 26);
		}
		
		wyj << endl;
	}
	
	//wczytanie, podpunkt drugi odszyfruj majac slowo zaszyfrowane oraz klucz
	for (int i = 0; i < 3000; i++)
	{	
		string s;
		int k;
		
		wej1 >> s;	
		wej1 >> k;
		
		k %= 26;
		
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] - k >= 65)
				wyj1 << char(s[j] - k);
			else
				wyj1 << char(90 - k + (s[j] - 65 + 1));
				
		}
		
		wyj1 << endl;
	}
	
	//wczytanie, podpunkt trzeci => czy mozliwe by slowa byly swoimi szyframi
	for (int i = 0; i < 3000; i++)
	{	
		string s1pom;
		string s1, s2;
		wej2 >> s1 >> s2;	s1pom=s1;	
		
		if (s1[0] > s2[0]) 
			swap(s1, s2);
			
		int k = s2[0] - s1[0];
		string s3; 
		
		for (int j = 0; j < s1.size(); j++)
		{
			s3 += char((s1[j] - 65 + k) % 26 + 65);
		}
		
		if (s3 != s2)
			wyj2 << s1pom << endl;
	}
}
