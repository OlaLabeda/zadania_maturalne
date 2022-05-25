#include <bits/stdc++.h>
using namespace std;
unsigned long long nadziesietny(unsigned long long x, int podstawa)
{
	unsigned long long wynik = 0;
	int wykladnik = 0;
	while (x!=0)
	{
		wynik += pow(podstawa, wykladnik)*(x%10);
		x/=10;
		wykladnik ++;
	}
	return wynik;
}
int main ()
{
	ifstream wej("liczby.txt");
	ofstream wyj1("wyniki_6_1.txt");
	ofstream wyj2("wyniki_6_2.txt");
	ofstream wyj3("wyniki_6_3.txt");
	ofstream wyj4("wyniki_6_4.txt");
	ofstream wyj5("wyniki_6_5.txt");
	unsigned long long liczby[999];
	int ileosemkowy = 0;
	for (int i = 0; i < 999; i++)
	{
		wej >> liczby[i];
		//cout << liczby[i] << endl;
		if (liczby[i] % 10 == 8)
			ileosemkowy++;
	}
	wyj1 << ileosemkowy;
	int ileczworkowy = 0;
	for (int i = 0; i < 999; i++)
	{
		if (liczby[i] % 10 == 4)
		{
			unsigned long long p = liczby[i]/10;
			bool czy = 1;
			while (p != 0)
			{
				if (p%10 == 0)
				{
					czy = 0;
					break;
				}
				p/=10;
			}
			if (czy)
				ileczworkowy ++;
		}
	}
	wyj2 << ileczworkowy;
	int iledwojkowy = 0;
	for (int i = 0; i < 999; i++)
	{
		if (liczby[i] % 10 == 2)
		{
			unsigned long long p = liczby[i] / 10;
			if (p%10 == 0)
				iledwojkowy++;
		}
	}
	wyj3 << iledwojkowy;
	unsigned long long sumaliczb = 0;
	for (int i = 0; i < 999; i++)
	{
		if (liczby[i] % 10 == 8)
		{
			unsigned long long p = liczby[i]/10;
			sumaliczb += nadziesietny(p, 8);
		}
	}
	wyj4 << sumaliczb;
	unsigned long long mini = nadziesietny(liczby[0]/10, liczby[0]%10);
	unsigned long long maksi = mini;
	int indmini = 0, indmaksi = 0;
	for (int i = 1; i < 999; i++)
	{
		unsigned long long l = nadziesietny(liczby[i]/10, liczby[i]%10);
		if (l < mini)
		{
			mini = l;
			indmini = i;
		}
		if (l > maksi)
		{
			maksi = l;
			indmaksi = i;
		}
	}
	wyj5 << "najwieksza: " << liczby[indmaksi] << " " << maksi << "\n";
	wyj5 << "najmniejsza: " << liczby[indmini] << " " << mini;
}
