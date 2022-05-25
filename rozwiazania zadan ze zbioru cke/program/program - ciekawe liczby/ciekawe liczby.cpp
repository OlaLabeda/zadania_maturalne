#include <bits/stdc++.h>
using namespace std;
bool czynniki(int liczba)
{
	int p = 3, ile = 0;
	//szukam liczb z wylacznie nieparzystymi dzielnikami
	//wiec odrzucam gdy liczba jest parzysta
	if (liczba % 2 == 0)
		return 0;
	//dopoki liczba moze miec dzielniki wieksze od 1
	while (liczba > 1)
	{
		//jesli dana liczba p dzieli bez reszty liczbe
		//to oznacza to ze jest ona dzielnikiem pierwszym
		//wszystkie liczby zlozone zostaja odrzucone
		//bo sa wielokrotnosciami poprzednio sprawdzonych liczb pierwszych
		if (liczba % p == 0)
		{
			//jezeli liczba ma dzielnik pierwszy p to zwiekszam licznik dzielnikow
			//i dziele liczbe dopoki dzieli sie bez reszty przez p
			ile ++;
			if (ile > 3) return 0;
			while (liczba % p == 0)
				liczba/=p;
		}
		//zwiekszam p w poszukiwaniu kolejnych dzielnikow
		p+=2;
	}
	if (ile == 3) return 1;
	return 0;
}
int odwrocliczbe (int liczba)
{
	int odwrotna=0;
	while ( liczba > 0)
	{
		odwrotna = odwrotna * 10 + liczba%10;
		liczba/=10;
	}
	return odwrotna;
}
//iloczyn kolejnych cyfr danej liczby
int iloczynliczby (int liczba)
{
	int iloczyn = 1;
	//dopoki mam jeszcze niepoliczone cyfry
	while (liczba > 0)
	{
		//mnoze dotychczasowy iloczyn przez ostatnia cyfre liczby i
		//dziele calkowicie liczbe przez 10
		iloczyn*= (liczba%10);
		liczba/=10;
	}
	return iloczyn;
}
//MOC LICZBY - ILE razy trzeba policzyc iloczyn cyfr danej liczby tak
//aby byla ona ostatecznie jednocyfrowa
//wedlug polecenia liczby sa minimum dwucyfrowe, wiec minimalna moc liczby to bedzie 1
int mocliczby (int liczba)
{
	//inicjuje moc jako 1 i licze wstepnie iloczyn
	int moc = 1;
	liczba = iloczynliczby(liczba);
	//dopoki iloczyn liczby nie jest jednocyfrowy to go modyfikuje
	//jednoczesnie zwiekszajac licznik mocy
	while (liczba / 10 != 0 )
	{
		liczba = iloczynliczby(liczba);
		moc++;
	}
	return moc;
}
int main ()
{
	ifstream wej("liczby.txt");
	ofstream wyj("wyniki_liczby.txt");
	long long int liczby[1000];	int policz = 0;
	for (int i =0; i < 1000; i++)
		{
			wej >> liczby[i];
			if (czynniki(liczby[i]))
				policz++;
		}
	//1
	wyj<< "1)\n" << policz << "\n\n";
	//liczba liczb dla ktorych suma liczby i liczby odwroconej jest liczba palindromiczna
	int ilepalindromicznych = 0;
	for (int i = 0; i < 1000; i++)
	{
		int x = odwrocliczbe(liczby[i]);
		//BARDZO WAZNE
		//liczba/slowo sa palindromiczne, gdy po odwroceniu sa takie same jak na wejsciu
		if (liczby[i] + x == odwrocliczbe(liczby[i]+x))
			ilepalindromicznych++;
	}
	wyj << "2)\n" << ilepalindromicznych << "\n\n";
	int ileliczb[9];
	for (int i = 0; i < 9; i++)
		ileliczb[i]=0;
	long long int minimalna = 0, maksymalna = 0;
	for (int i = 0; i < 1000; i++)
	{
		ileliczb[mocliczby(liczby[i])]++;
		if (mocliczby(liczby[i] == 1))
		{
			if (minimalna == 0) minimalna = liczby[i];
			if (maksymalna ==0) maksymalna = liczby[i];
			minimalna = min(minimalna, liczby[i]);
			maksymalna = max(maksymalna, liczby[i]);
		}
	}
	wyj << "3)\n";
	for (int i =1; i < 9; i++)
		wyj <<"i "<<i << ": "<<  ileliczb[i]<< "\n";
	wyj<<"\n" << "minimalna: " <<minimalna<< "\nmaksymalna: " << maksymalna<< "\n";
}
