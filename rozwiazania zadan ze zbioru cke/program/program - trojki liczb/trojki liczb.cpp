#include <bits/stdc++.h>
using namespace std;	
ofstream wyj("wyniki.txt");
void czysuma (int a, int b, int c)
{
	//jezeli suma cyfr a i b jest rowna c
	//wypisz a i b i c
	int pom1 = a, pom2 = b;
	int a1 = 0, b1 = 0;
	while (pom1!=0)
	{
		a1 += pom1 % 10;
		pom1 /= 10;
	}
	while (pom2 != 0)
	{
		b1 += pom2 % 10;
		pom2 /= 10;
	}
	if(a1 + b1 == c)
		wyj << a << " " << b << " " << c<< "\n";
}
bool czypierwsza (int x)
{
	for (int i = 2; i <=sqrt(x); i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}
void pierwszeizlozona (int wiersz, int a, int b, int c)
{
	if (czypierwsza(a) && czypierwsza(b) && a*b==c)
		wyj << a << " " << b<< " " << c << "\n";
}
bool czytrojkatny (int a, int b, int c)
{
	if (a + b > c && a + c > b && b + c > a)
		return 1;
	return 0;
}
int main ()
{
	ifstream wej("trojki.txt");

	long int trojki[1000][3];
	
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 3; j++)
			wej >> trojki[i][j];
			
	wyj << "1)\n";
	for (int i = 0; i < 1000; i++)
		czysuma(trojki[i][0], trojki[i][1], trojki[i][2]);
		
	wyj << "\n\n2)\n";
	for (int i = 0; i < 1000; i++)
		pierwszeizlozona(i, trojki[i][0], trojki[i][1], trojki[i][2]);
		
	wyj << "\n3)\n";
	bool czypoprzedni = 0; int p1 =0, p2=0, p3 =0;
	for (int i = 0; i < 1000; i++)
	{
		int tpom[3]; 
		for (int j = 0; j < 3; j++)
			tpom[j] = trojki[i][j];
		sort(tpom, tpom+3);
		if (pow(tpom[0], 2) + pow(tpom[1], 2) == pow(tpom[2], 2))
			{
				if (czypoprzedni == 1)
				{
						wyj <<p1 << " " << p2<<" " << p3<<"\n" <<trojki[i][0] << " " << trojki[i][1] << " " << trojki[i][2] << endl;
				}
				else if (czypoprzedni>1)
				{
						wyj <<tpom[0] << " " << tpom[1] << " " << tpom[2] << endl;
				}
				else
				{	
					p1 = trojki[i][0]; 
					p2 = trojki[i][1]; 
					p3 = trojki[i][2];
				}
				czypoprzedni++;
			}
		else
			czypoprzedni = 0;	
	}	
	int iletrojkatnych = 0, dlciagu = 0, dllok = 0;
	if (czytrojkatny(trojki[0][0], trojki[0][1], trojki[0][2]))
	{
		dllok = 1; 
		iletrojkatnych++;	
	}
	for (int i = 1; i < 1000; i++)
	{
		if (czytrojkatny(trojki[i][0], trojki[i][1], trojki[i][2]))
		{
			iletrojkatnych++;
			dllok++;
		}
		else
		{
			dlciagu = max(dlciagu, dllok);
			dllok = 0;
		}
	}
	wyj << "\n4)\n";
	wyj <<iletrojkatnych<< "\n"<< dlciagu << "\n";
}
