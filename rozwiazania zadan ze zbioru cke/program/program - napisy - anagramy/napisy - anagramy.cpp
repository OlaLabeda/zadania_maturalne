#include <bits/stdc++.h>
using namespace std;
int anagramyilosc[1005][3];
bool czyjednolity (string s)
{
	char porownaj = s[0];
	for (int i =1; i < s.size(); i++)
	{
		if (porownaj != s[i])
			return 0;
	}
	return 1;
}
bool czyanagramy(string s1, string s2)
{
	//2 napisy a i b sa swoimi anagramami jezeli napis a (napis b) mozna zapisac za pomoca
	//liter wystepujacych w napisie b (napisie a), wykorzystujac WSZYSTKIE jego litery
	//a jest permutacja b i na odwrot!
	int	a1[40], a2[40];
	for (int i = 0; i <= 40; i++)
		{
			a1[i]=0;
			a2[i]=0;
		}
	for (int i =0; i < s1.size(); i++)
		a1[s1[i] - 65]++;
	for (int i =0; i < s2.size(); i++)
		a2[s2[i] - 65]++;	
		
	for (int i =0; i <40; i++)
	{
		if (a1[i] != a2[i])
			return false;
	}
	return true;
}
int main ()
{
	ifstream wej("dane_napisy.txt");
	ofstream wyj("wyniki.txt");
	int jednoanag = 0;
	int ileanag = 0;
	string s[1004][3];
	for (int i = 1; i <= 1000; i++)
	{
		anagramyilosc[i][1] = 0;
		anagramyilosc[i][2] = 0;
		string s1, s2;
		wej >> s1 >> s2;
		s[i][1]=s1;
		s[i][2]=s2;
		if (czyanagramy(s1, s2))
		{
			if (czyjednolity(s1))
				jednoanag++;
			ileanag++;
		}
	}
	wyj << "1)\n" << jednoanag << "\n";
	wyj << "\n2)\n" << ileanag << "\n";
	for (int i = 1; i <= 1000; i++)
	{		
		int p1 = 1, p2=1;	
		if (czyanagramy(s[i][1], s[i][2]))
			{
				p1++;					
				p2++;					
			}
		for (int j = i+1; j <=1000; j++)
		{
			if (czyanagramy(s[i][1], s[j][1]))
				p1++;
			if (czyanagramy(s[i][2], s[j][1]))
				p2++;
			if (czyanagramy(s[i][1], s[j][2]))
				p1++;
		}
		anagramyilosc[i][1] = max(anagramyilosc[i][1], p1);
		anagramyilosc[i][2] = max(anagramyilosc[i][2], p2);
	}
	int maksk = 0;
	for (int i =1; i <= 1000; i++)
	{
		maksk=max(maksk, anagramyilosc[i][1]);
		maksk=max(maksk, anagramyilosc[i][2]);
	}
	wyj << "\n3)\n" << maksk << "\n";
}
