#include <bits/stdc++.h>
using namespace std;
int dl[2000];
int ile[2000];
int maksmal = 0;
int dlmalejacegociagu(string numer, int ind)
{
	int licz= 1;
	while (numer[licz] < numer[licz-1] && licz <= numer.size())
	{
		licz++;
	}
	dl[ind] = licz; 
	maksmal = max(maksmal, licz);
}
int main ()
{
	ifstream wej("telefony.txt");
	ofstream wyj("wyniki.txt");
	string telefon[2000], czy[2000];
	int tak = 0, nie = 0;
	int numery[4];
	int sumacyfr[2000];
	int makssuma = 0;
	for (int i = 0; i < 4; i++)
		numery[i] = 0;
	for (int i = 0; i < 2000; i++)
	{
		wej >> telefon[i] >> czy[i];
		if(czy[i] == "Tak")
			tak++;
		else 
			nie++;
		numery[telefon[i][0]-'0'-5]++;
		
		sumacyfr[i] = 0;
		for (int j = 0; j < telefon[i].size(); j++)
			sumacyfr[i] += telefon[i][j] - '0';	
			
		makssuma = max(sumacyfr[i], makssuma);
		dlmalejacegociagu(telefon[i], i);
	}
	wyj << "a)\n" << "tak: " <<  tak << " nie: " << nie << "\n\n";
	wyj << "b)\n";
	for (int i = 0; i < 4; i++)
		wyj << i + 5 << ": " << numery[i] << "\n";
	wyj << "\nc)\n";
	for (int i = 0; i < 2000; i++)
	{
			if (sumacyfr[i] == makssuma)
				wyj << "numer: " << telefon[i] << "\nsuma cyfr: " <<  sumacyfr[i]<< "\n";
	}
	wyj << "\nd)\n" << "dlugosc: " << maksmal << "\n";
	for (int i = 0; i < 2000; i++)
	{
		if (dl[i] == maksmal)
			wyj << telefon[i] << "\n";
	}
	sort(telefon, telefon + 2000);
	int maksile = 0;
	ile[0] = 1;
	for (int i = 1; i < 2000; i++)
	{
		if (telefon[i] == telefon[i-1])
			ile[i] = ile[i-1] + 1;
		else
			ile[i]=1;
		maksile = max(maksile, ile[i]);
	}
	wyj <<"\ne)\n" << maksile;			
	
}
