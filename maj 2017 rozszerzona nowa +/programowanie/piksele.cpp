#include <bits/stdc++.h>
using namespace std;
int piksele[330][330];
int main ()
{
	int najjasniejszy = -1, najciemniejszy = 330, ileusunac = 0, ilekontrastujacych = 0;
	
	ifstream in("dane.txt");
	ofstream out("wyniki6.txt");
	
	for (int i =  1; i <= 200; i++)
	{
		for (int j = 1; j <= 320; j++)
		{
			in >> piksele[i][j];
			najjasniejszy = max(najjasniejszy, piksele[i][j]);
			najciemniejszy = min(najciemniejszy, piksele[i][j]);
		}

		for (int j = 1; j <= 160; j++)
		{
			if (piksele[i][j] != piksele[i][320 - j + 1])
				{
					ileusunac++;
					break;
				}
		}	
	}
	out << "1)\nnajciemniejszy: " << najciemniejszy << ", najjasniejszy: " << najjasniejszy << "\n";
	out << "\n2)\n" << ileusunac << "\n";
	
	//ustawienie wstepne wartosci w tabeli dla wolnych komorek tak, aby latwiej bylo okreslic warunki brzegowe
	piksele[0][0]=piksele[1][1];
	for (int i =1; i<=201; i++)
	{
		piksele[i][0]=piksele[i][1];
		piksele[i][321] = piksele[i][320];
	}
	for (int i = 1; i<=320; i++)
	{
		piksele[0][i] = piksele[1][i];
		piksele[201][i] = piksele[200][i];
	}
	
	//odszukanie ilosci pikseli spelniajacych warunek kontrastu
	for (int i = 1; i <= 200; i++)
	{
		for (int j = 1; j <= 320; j++)
		{
			int a, b, c, d;
			a = abs(piksele[i][j] - piksele[i+1][j]);
			b = abs(piksele[i][j] - piksele[i-1][j]);
			c = abs(piksele[i][j] - piksele[i][j+1]);
			d = abs(piksele[i][j] - piksele[i][j-1]);
			if (a > 128 || b > 128 || c > 128 || d > 128)
				ilekontrastujacych++;
		}
	}
	out << "\n3)\n"<< ilekontrastujacych<<"\n";
	int najdluzsza = 1;
	for (int j = 1; j <= 320; j++)
	{
		int lokalnemaks = 1;
		for (int i = 2; i<= 200; i++)
		{
			if (piksele[i][j] == piksele[i-1][j])
				lokalnemaks++;
			else 
			{
				najdluzsza = max(lokalnemaks, najdluzsza);
				lokalnemaks = 1;
			}
		}
	}
	out <<"\n3)\n"<<najdluzsza;
}
