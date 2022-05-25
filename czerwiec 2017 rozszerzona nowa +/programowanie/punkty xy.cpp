#include <bits/stdc++.h>
using namespace std;
bool czypierwsza (int x)
{
	for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
				return 0;
		}
	return 1;
}
int main ()
{
	long int x[1000], y[1000];
	ifstream wej("punkty.txt");
	ofstream wyj("wyniki4.txt");
	
	int inda = 0, indb = 0;
	int ilepierwszych = 0, ilecyfropodobnych = 0;
	long long int odlegl = 0;
	int wewn = 0, nazewn = 0, na = 0;
	
	for (int i = 0; i < 1000; i++)
	{
		bool czycyfra1[10], czycyfra2[10];
		
		for (int i = 0; i < 10; i++)
		{
			czycyfra1[i] = 0; 
			czycyfra2[i] = 0;
		}
		
		wej >> x[i] >> y[i];
		
		if (czypierwsza(x[i]) && czypierwsza(y[i]))	
			ilepierwszych++;
			
		long int p1 = x[i], p2 = y[i];
		while (p1 > 0)
		{
			czycyfra1[p1 % 10] ++;
			p1 /= 10;
		}
		while (p2 > 0)
		{
			czycyfra2[p2 % 10] ++;
			p2 /= 10;
		}
		bool czy = 1;
		for (int j = 0; j <10; j++)
		{
			if (czycyfra1[j] != czycyfra2[j])
			 czy = 0;
		}
		
		if (czy)
			ilecyfropodobnych++;
	}
	
	for (int i = 0; i < 1000; i++)
	{
		long long int pom = 0;
		for (int j = i + 1; j < 1000; j++)
		{
			pom = pow((x[j] - x[i]), 2) + pow(y[j] - y[i], 2);
			if (odlegl < pom)
			{
				odlegl = pom; 
				inda = i;
				indb = j;
			}
		}
		if ((abs(x[i]) == 5000) || (abs(y[i]) == 5000))
			na ++;
		else if (abs(x[i]) < 5000 && abs(y[i]) < 5000)
			wewn ++;
		else
			nazewn ++;
		
	}
	wyj<< "1)\n" << ilepierwszych<< "\n\n";
	wyj<< "2)\n" << ilecyfropodobnych << "\n\n";
	wyj << "3)\n" <<  round(sqrt(odlegl))<< "\n";
	wyj << x[inda] << " "<< y[inda] << "\n"<< x[indb]<<  " " << y[indb]<< "\n\n";
	wyj << "4)\n"<< "na:\n"<<na <<  "\nwewnatrz:\n"<< wewn<< "\nna zewnatrz:\n"<< nazewn;
}
