#include <bits/stdc++.h>
using namespace std;
int main ()
{
	ifstream wej("dane.txt");
	ofstream wyj("wyniki6.txt");
	int piksele[202][322];
	int najciemniejszy = 256, najjasniejszy = 0;
	for (int i = 1; i < 201; i++)
	{
		for (int j = 1; j < 321; j++)
		{
			wej >> piksele[i][j];
			najciemniejszy = min(najciemniejszy, piksele[i][j]);
			najjasniejszy = max(najjasniejszy, piksele[i][j]);
		}
	}
	wyj << "1)\nnajjasniejszy: " << najjasniejszy << "\nnajciemniejszy: " << najciemniejszy << "\n\n";
	piksele[0][0] = 0; piksele[201][321] = 0; piksele[0][321] = 0; piksele[201][0] = 0;
	for (int i = 1; i < 321; i++)
		{
			piksele[0][i] = piksele[1][i];
			piksele[201][i] = piksele[200][i];
		}
	for (int i = 1; i < 201; i++)
		{
			piksele[i][0] = piksele[i][1];
			piksele[i][321] = piksele[i][320];
		}
	int ileusunac = 0;
	for (int i = 1; i <= 200; i++)
	{
		for (int j = 1; j <=160; j++)
		{
			if (piksele[i][j] != piksele[i][320-j+1])
			{
				ileusunac++;	
				break;
			}
		}
	}
	wyj << "2)\n" << ileusunac<< "\n\n";
	int ilekontrastujacych = 0;
	for (int i = 1; i <= 200; i++)
		for (int j = 1; j <= 320; j++)
		{
			int x = (piksele[i][j]);
			int a = abs(x - piksele[i-1][j]);
			int b = abs(x - piksele[i+1][j]);
			int c = abs(x - piksele[i][j-1]);
			int d = abs(x - piksele[i][j+1]);
			if (a > 128 || b > 128 || c > 128 || d > 128)
				ilekontrastujacych++;
		}
	wyj << "3)\n" << ilekontrastujacych << "\n\n";
	int longestpion = 0, loklong  = 1;
	for (int i = 1; i <= 320; i++)
	{
		for (int j = 2; j <= 200; j++)
		{
			if (piksele[j][i] == piksele[j-1][i])
			{
				loklong ++;
			}
			else
			{
				longestpion = max(longestpion, loklong);
				loklong  = 1;
			}
		}
	}
	wyj << "4)\n" << longestpion << "\n\n";
}
