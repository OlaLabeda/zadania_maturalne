#include <iostream>
#include <fstream>
using namespace std;

int s[7][21]; //liczba mandatow przydzielonych komitetowi do tej pory
int v[7]; //liczba glosow zdobytych przez dany komitet w danym okregu -> lokalnie
int sumakomitetow[6]; //ile glosow lacznie zebral kazdy z komitetow
int mandaty[21];
int mini, indmini, indmaksi, maksi=0;

int main ()
{
	ifstream odczyt("dane.txt");
	for (int i = 1; i <= 20; i++)
	{ 
		int sumatemp=0;
		for (int j = 1; j<=6; j++)
		{
			odczyt >> v[j]; 
			
			sumakomitetow[j-1]+=v[j];
			sumatemp += v[j];
		
		}
		
		if (i == 1)
		mini = sumatemp, maksi = sumatemp, indmini = 1, indmaksi = 1;
		
		else
		{
			if (mini > sumatemp)
			{
				mini = sumatemp;
				indmini = i;
			}
			if (maksi < sumatemp)
			{
				maksi = sumatemp;
				indmaksi = i;
			}
		}
		
		odczyt >> mandaty[i];
		for (int j = 1; j <= mandaty[i]; j++)  
		{
			int lokalind=1; 
			double lokalmaksw = v[1]/(s[1][i]+1);
			for (int m =2; m <=6; m++)
			{
				if (lokalmaksw < v[m]/(s[m][i]+1))
					{
						lokalmaksw=v[m]/(s[m][i]+1);
						lokalind =m;
					}
			}
			s[lokalind][i]++;
		}
	}
	cout << "1. \n";
	for (int n = 0; n < 6; n++)
	{
		cout << char('A' + n) << " " << sumakomitetow[n] << "\n";
	}
	
	cout << "\n2.\nminimum: okreg " << indmini << "\nmaksimum: okreg " << indmaksi;	
	
	cout << "\n3.\n";
	for (int n =1; n<=6; n++)
	{
		cout << char('A'+n-1)<<" "<< s[n][6]<< "\n";
	}
	
	for (int o = 2; o <=20; o++)
	{
		for (int u = 1; u <=6; u++)
		{
			s[u][1]+=s[u][o];
		}
	}
	
	cout << "\n4.\n";
	for (int n =1; n<=6; n++)
	{
		cout << char('A'+n-1)<<" "<< s[n][1]<< "\n";
	}
}
