#include <bits/stdc++.h>
using namespace std;
ofstream wyj("wyniki.txt");
int czyrewers (string s[])
{
	int cz = 0, b = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (s[i][j] == '1')
				cz++;
			else
				b++;
	if (cz>b)
		return cz;
	return 0;
}
bool czyrekurencyjny (string s[])
{
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			if (s[i][j] != s[i + 10][j] || s[i][j] != s[i][j + 10] || s[i][j] != s[i + 10][j + 10])
				return 0;
	return 1;
}
int ileniepoprawnychpoz (string s[])
{
	int jedynkipoz = 0;
	for (int i = 0; i < 20; i++)
	{ 
		int ilejedynek = 0;
		for (int j = 0; j < 20; j++)
			if (s[i][j] == '1')
				ilejedynek++;
		if ((ilejedynek % 2 == 0 && s[i][20] != '0') || ilejedynek % 2 == 1 && s[i][20] !='1')
			jedynkipoz++;
	}
	return jedynkipoz;
}
int ileniepoprawnychpion (string s[])
{
	int jedynkipion = 0;
	for (int i = 0; i < 20; i++)
	{ 
		int ilejedynek = 0;
		for (int j = 0; j < 20; j++)
			if (s[j][i] == '1')
				ilejedynek++;
		if ((ilejedynek % 2 == 0 && s[20][i] != '0') || ilejedynek % 2 == 1 && s[20][i] !='1')
			jedynkipion++;
	}
	return jedynkipion;
}
void wiersz(string s[])
{
	int wiersz = 0;
	int jedynkipoz = 0;
	for (int i = 0; i < 20; i++)
	{ 
		int ilejedynek = 0;
		for (int j = 0; j < 20; j++)
			if (s[i][j] == '1')
				ilejedynek++;
		if ((ilejedynek % 2 == 0 && s[i][20] != '0') || ilejedynek % 2 == 1 && s[i][20] !='1')
			{
				wiersz = i;
				break;
			}
	}
	wyj << "wiersz: " << wiersz +1<< " ";
}
void kolumna(string s[])
{
	int kolumna = 0;
	for (int i = 0; i < 20; i++)
	{ 
		int ilejedynek = 0;
		for (int j = 0; j < 20; j++)
			if (s[j][i] == '1')
				ilejedynek++;
		if ((ilejedynek % 2 == 0 && s[20][i] != '0') || ilejedynek % 2 == 1 && s[20][i] !='1')
			{
				kolumna = i;
				break;
			}
	}
	wyj <<" kolumna " << kolumna +1 << endl;
}
void pip (string s[])
{
	wiersz(s);
	kolumna(s);
}
void tylkouno(string s[])
{
	if(ileniepoprawnychpoz(s) == 1)
	{
		wiersz(s);
		wyj << "kolumna: " << 21 << endl;
	}
	else
	{
		wyj << "wiersz: " << 21 << " " ; 
		kolumna(s);
	}
}
void wypiszblad (string s[])
{
	//ofstream wyj;
	//pion i poziom niepoprawne
	if (ileniepoprawnychpoz(s) == 1 && ileniepoprawnychpion(s) == 1)
		pip(s);
	//tylko pion lub tylko poziom niepoprawne
	else
		tylkouno(s);
}
int main ()
{
	ifstream wej("dane_obrazki.txt");
	int zlicz1 = 0;
	int zlicz2 = 0;
	int poprawne = 0, naprawialne = 0, nienaprawialne = 0, najwiecejbledow  = 0;
	int maks = 0;
	bool czybyl=0;
	string obrazek[20][20];
	int ind = 0;
	for (int l = 1; l <= 200; l++)
	{
		string s[21];
		bool czy = 1;
		
		for (int i = 0; i <=20; i++)
				wej >> s[i];
			
		if (czyrewers(s))
		{
			maks = max(czyrewers(s), maks);
			zlicz1++;	
		}
		
		if (czyrekurencyjny(s))
		{
			zlicz2++;
			if (!czybyl)
			{
				czybyl = 1;
				for (int i = 0; i < 20; i++)
					for (int j = 0; j < 20; j++)
						obrazek[i][j] = s[i][j];
			}	
		}
		
		int ppoz = ileniepoprawnychpoz(s), ppion = ileniepoprawnychpion(s);
		if (ppoz == 0 && ppion == 0)
			poprawne++;
		else if (ppoz <=1 && ppion <=1)
				naprawialne++;	
		else
			nienaprawialne++;
		najwiecejbledow = max(najwiecejbledow, ppoz+ppion);
	}
	wyj << "1)\n" <<"liczba obrazkow - rewersow: " << zlicz1 << "\n";
	wyj << "maks liczba czarnych pikseli: " << maks << "\n\n";
	
	wyj <<"2)\n"<< "liczba obrazkow rekurencyjnych: " << zlicz2 << "\n";
	wyj << "pierwszy obrazek rekurencyjny: \n";
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			wyj << obrazek[i][j];
		wyj << "\n";
	}
	wyj << "\n3)";
	wyj << "poprawne: " << poprawne << "\n";
	wyj << "naprawialne: " << naprawialne << "\n";
	wyj << "nienaprawialne: " << nienaprawialne << "\n";
	wyj << "najwiecej blednych bitow: " << najwiecejbledow << "\n\n";
	ifstream close();
	
	ifstream wej2("dane_obrazki.txt");
	wyj << "4)\n";
	for (int l = 1; l <= 200; l++)
	{
		string s[21];
		for (int i = 0; i <=20; i++)
				wej2 >> s[i];
				
		int ppoz = ileniepoprawnychpoz(s), ppion = ileniepoprawnychpion(s);
		if (ppoz <=1 && ppion <=1 && (ppoz == 1 || ppion == 1))
			{	
				wyj << l <<"\n";  
				wypiszblad(s);	
			}
	}
}
