#include <bits/stdc++.h>
using namespace std;
int main ()
{
	// DOPISZ litera => na koncu slowa s dopisz litera
	// ZMIEN litera => ostatnia litere slowa s zamien na litera (slowo nie jest puste)
	// USUN 1 => usun ostatnia litere slowa s
	// PRZESUN litera => zamien pierwsze wystapienie litera (jesli jest) na char(litera+1);
	int zlicz[27];
	for (int i = 0; i <= 26; i++)
		zlicz[i] = 0;
	string polecenie[2000]; char znak[2000];
	string slowo;
	ifstream wej("instrukcje.txt");
	ofstream wyj("wyniki4.txt");
	for (int i = 0; i < 2000; i++)
	{
		wej >> polecenie[i] >> znak[i];

//biore pod uwage znak oznaczajacy ze cos zostalo usuniete z konca
		int p = slowo.size() - 1;
			while (slowo[p] == '0')
				p--;

		if (polecenie[i] == "DOPISZ")
		{
			if (slowo[slowo.size()-1]=='0')
					slowo[p + 1] = znak[i];
			else
				slowo += znak[i];
		}
		else if (polecenie[i] == "ZMIEN")
			slowo[p] = znak[i];
			
		else if (polecenie[i] == "USUN")
			slowo[p] = '0';

		else if (polecenie[i] == "PRZESUN")
		{
			for (int j = 0; j < slowo.size(); j++)
			{
				if (slowo[j] == znak[i])
				{
					if (slowo[j] == 'Z')
						slowo[j] = char('A');
					else
						slowo[j] = char(slowo[j] + 1);
					break;
				}
			}
		}
	}
	
	wyj<< "4.1\n" << slowo.size() << "\n\n";
	
	//2
	int licznik = 1, llok = 1, ind = 0; 
	for (int i = 1; i < 2000; i++)
	{
		if (polecenie[i] == "DOPISZ")
		{
			zlicz[znak[i]-64]++;
		}
		if (polecenie[i] == polecenie [i-1])
				llok++;
		else
		{
			if (llok > licznik)
			{
				licznik = llok;
				ind = i - 1;
			}	
			llok = 1;
		}
	}
	
	wyj << "\n4.2\n" << polecenie[ind] << " " << licznik << "\n\n";
	
	int maks = zlicz[1]; 
	char makslitera = 'A';
	for (int i = 2; i <= 26; i++)
	{
		if (zlicz[i] > maks)
		{
			maks = zlicz[i];
			makslitera = char(i + 64);
		}
	}
	
	wyj << "\n4.3\n" << maks << " " << makslitera << "\n\n";
	 
	wyj << "\n4.4\n" << slowo << "\n\n";
}
