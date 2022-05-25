#include <bits/stdc++.h>
using namespace std;
bool czywyst0(long long x)
{
	while (x > 0)
	{
		if (x % 10 == 0)
			return 1;
		x/= 10;
	}
	return 0;
}
unsigned long long zamien(long long x)
{
	int  p = x%10;
	x/=10;
	int i = 0;
	unsigned long long liczba = 0;
	while (x > 0)
	{
		liczba += (x%10) * pow(p, i);
		i++;
		x/=10;
	}
	return liczba;
}
int main ()
{
	ifstream wej("liczby.txt");
	ofstream wyj1("wyniki_1.txt");
	ofstream wyj2("wyniki_2.txt");
	ofstream wyj3("wyniki_3.txt");
	ofstream wyj4("wyniki_4.txt");
	ofstream wyj5("wyniki_5.txt");
	long long kod[999];
	int ileosemkowy = 0;
	int ileczworkowy = 0;
	int iledwojkowy = 0;
	unsigned long long sumaosemkowych = 0;
	long long najmniejsza = 1515151515, najwieksza = 0;
	unsigned long long mini =  151515151155, maksi = 0;
	for (int i = 0; i < 999; i++)
	{
		wej >> kod[i];
		unsigned long long zmieniona = zamien(kod[i]);
		if (zmieniona < mini)
		{
			mini = zmieniona;
			najmniejsza = kod[i];
		}
		if (zmieniona > maksi)
		{
			maksi = zmieniona;
			najwieksza = kod[i];
		}
		if (kod[i] % 10 == 8)
		{
			ileosemkowy++;	
			sumaosemkowych +=	zmieniona;
		}
		if (kod[i] % 10 == 4)
		{
			if(czywyst0(kod[i]) == 0)
				ileczworkowy++;
		}
		if (kod[i] % 10 == 2)
		{
			int pom = kod[i] / 10;
			if (pom % 10 == 0)
				iledwojkowy++;
		}
	}
	wyj1 << ileosemkowy;
	wyj2 << ileczworkowy;
	wyj3 << iledwojkowy;
	wyj4 << sumaosemkowych;
	wyj5 << "najmniejsza: " << najmniejsza << " " << mini << "\n";
	wyj5 << "najwieksza: " << najwieksza <<" " << maksi;
}
