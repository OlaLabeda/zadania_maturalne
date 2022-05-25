#include <bits/stdc++.h>
using namespace std;
int main ()
{
	ifstream wej1("dane1.txt");
	ifstream wej2("dane2.txt");
	ofstream wyj1("wynik4_1.txt");
	ofstream wyj2("wynik4_2.txt");
	ofstream wyj3("wynik4_3.txt");
	ofstream wyj4("wyniki4_4.txt");
	
	int t1[1000][10], t2[1000][10];
	int wiluwierszach=0;
	int odp2=0;
	int odp3=0;
	
	wyj3 << "wiersze: \n";
	
	for (int  i = 0; i < 1000; i++)
	{
		int lp1 = 0, lp2 = 0, lnp1 = 0, lnp2 = 0;
		int pom1[101], pom2[101], t3[20];
		
		for (int i = 0 ; i <= 100; i++)
		{ 
			pom1[i]=0;
			pom2[i]=0;
		}
		
		for (int j = 0; j<10; j++)
		{
			wej1 >> t1[i][j];
			wej2 >> t2[i][j];
			
			pom1[ t1[i][j] ] = 1;
			pom2[ t2[i][j] ] = 1;
			
			t3[j] = t1[i][j];
			t3[10 + j] = t2[i][j]; 
			
			if (t1[i][j] % 2 == 0)
				lp1 ++;
			else 
				lnp1 ++;
				
			if (t2[i][j] % 2 == 0)
				lp2 ++;
			else 
				lnp2 ++;				
		}
		
		int czy = 1;
		for (int j = 0; j <= 100; j++)
		{
			if (pom1[j] != pom2[j])
			{
				czy = 0; 
				break;
			}
		}
		
		if (czy == 1) 
		{
			odp3 ++;
			wyj3 << i + 1 << endl;
		}
		
		if (lp1 == 5 && lp2 == 5 && lnp1 == 5 && lnp2 == 5)
			odp2++;
			
		if (t2[i][9] == t1[i][9])
			wiluwierszach ++;
		
		sort(t3, t3 + 20);
		for (int j = 0; j < 20; j++)
			wyj4 << t3[j] << " ";
		wyj4 << endl;
		
	}
	wyj1 << wiluwierszach << endl;
	wyj2 << odp2 << endl;
	wyj3 <<"liczba par: \n" << odp3 << endl;

	
}
