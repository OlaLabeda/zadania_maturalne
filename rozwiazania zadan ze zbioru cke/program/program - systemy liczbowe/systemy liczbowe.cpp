//systemy liczbowe
#include <bits/stdc++.h>
using namespace std;
//zamieniam wprowadzone w postaci stringow liczby w roznych systemach
//i potrzbuje zmienic je na system dzieietny 
int nadziesietne (string s, int podstawa)
{
	int suma = 0, mnoz = 1;
	//oteracja od konca, kazdy element liczby w dany systemie pozycyjnym mnoze przez odpowiednia poetege podstawy
	for (int i = s.size()-1; i >=0; i--)
	{
		if (s[i] !='-')
			suma += (s[i]-'0')*mnoz;
		else
			suma*=-1;
		mnoz*=podstawa;
	}
	return suma;
}
//zamiana liczb na system dwojkowy
string nadwojkowy (int n)
{
	//inicjacja pustego stringa ktory bede wypelniac
	string s = "";
	int maks = 1;
	int  pom = n;
	if (pom < 0)
		pom*=-1;
	while (maks < pom)
		maks*=2;
	if (maks != 1)
		maks/=2;
	if (n < 0)
		s+='-';
	while (maks >= 1)
	{
		if (pom -maks >= 0)
		{
			s+='1';
			pom-=maks;
		}
		else
			s+='0';
		maks/=2;
	}
	return s;
}
int main ()
{
	//trzy stacje pogodowe S1 S2 i S3
	//zegary odliczaja liczbe godzin ktore uplynely od uruchomienia stacji
	//S1 - binarny
	//S2 - czworkowy
	//S3 - osemkowy
	//temperatury ujemne poprzedzone znakiem "-"
	
	//1095 kolejnych pomiarow na kazdej ze stacji
	//kazdy wiersz - stan, temperatura
	string stan1[1095], stan2[1095], stan3[1095], temp1[1095], temp2[1095], temp3[1095];
	int tdzies1[1095], tdzies2[1095], tdzies3[1095];
	ifstream wej1("dane_systemy1.txt");
	ifstream wej2("dane_systemy2.txt");
	ifstream wej3("dane_systemy3.txt"); 
	ofstream wyj("wyniki.txt");
	for (int i = 0; i < 1095; i++)
	{
		wej1 >> stan1[i] >> temp1[i];
		wej2 >> stan2[i] >> temp2[i];
		wej3 >> stan3[i] >> temp3[i];
		tdzies1[i] = nadziesietne(temp1[i], 2);
		tdzies2[i] = nadziesietne(temp2[i], 4);
		tdzies3[i] = nadziesietne(temp3[i], 8);
	}
	//najmniejsza temperatura zmierzona na kazdej ze stacji?
	int mini1 = tdzies1[0], mini2 = tdzies2[0], mini3 = tdzies3[0];
	for (int i = 1; i < 1095; i++)
	{
		mini1 = min (tdzies1[i], mini1);
		mini2 = min (tdzies2[i], mini2);
		mini3 = min (tdzies3[i], mini3);
	}
	wyj << "1) minimalna temperatura w poszczegolnych stacjach: \n";
	wyj << "Stacja 1: "<< nadwojkowy(mini1) << endl << "Stacja 2: "<< nadwojkowy(mini2) << endl << "Stacja 3: " << nadwojkowy(mini3)<< endl << endl; 
	int n1 = nadziesietne(stan1[0], 2) + 24, n2 = nadziesietne(stan2[0], 4) + 24, n3 = nadziesietne(stan3[0], 8) + 24;
	int ilenp = 0;
	for (int i =1; i < 1095; i++)
	{
		if (n1 != nadziesietne(stan1[i], 2) && n2 != nadziesietne(stan2[i], 4) && nadziesietne(stan3[i], 8) != n3)
			ilenp++;
		n1 += 24;
		n2+=24;
		n3+=24;
	}
	wyj << "2)\n";
	wyj << ilenp << endl;
	
	int maks1 = tdzies1[0], maks2 = tdzies2[0], maks3 = tdzies3[0];
	int dnirekordowe = 1; // dni w ktorych w co najmniej JEDNEJ stacji byl wynik rekordowy
	for (int i =1; i < 1095; i++)
	{
		if (maks1 < tdzies1[i]  ||  maks3 < tdzies3[i] || maks2 < tdzies2[i] ) 
				dnirekordowe++;
		maks1=max(maks1, tdzies1[i]);
		maks2=max(maks2, tdzies2[i]);
		maks3=max(maks3, tdzies3[i]);
	}
	wyj << "\n3)\n";
	wyj << dnirekordowe << endl;
	
	//maks skok pogodowy na stacji 1
	int maks = 0;
	for (int i =0; i < 1094; i++)
	{
		for (int j = i+1; j <1095; j++)
		{
			double skok = pow(tdzies1[i] - tdzies1[j], 2);
			skok/=abs(i-j);
			int pom = skok;
			if (skok > pom)
				pom++;
			maks = max(maks, pom);		
		}
	}
	wyj <<"\n3)\n" << maks << endl;
}
