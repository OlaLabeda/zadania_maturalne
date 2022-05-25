#include <bits/stdc++.h>
using namespace std;

int main ()
{
	ifstream wej("dane.txt");
	ofstream wyj("wyniki6.txt");
	int obraz[200][320];
	int kopia[202][322];
	int zle = 0;
	int sasiednie = 0;
	int najjasniejszy = 0, najciemniejszy = 256;
	for (int i = 0; i <200; i++)
	{
		int x;
		for (int j = 0; j < 320; j++)
		{
			wej >> obraz[i][j];
			kopia[i+1][j+1] = obraz[i][j];
			najjasniejszy = max(obraz[i][j], najjasniejszy);
			najciemniejszy = min(najciemniejszy, obraz[i][j]);
		}
		int p = 319;
		for (int j = 0; j < 320/2; j++)
		{
			if (obraz[i][j] != obraz[i][p-j])
			{
				zle++;	
				break;
			}
		}
	}
	wyj << "1)\n" << najjasniejszy << " " << najciemniejszy << "\n\n";
	wyj << "2)\n" << zle << "\n\n";
	for (int i = 1; i <= 200; i++)
		for (int j = 1; j <= 320; j++)
			kopia[i][j] = obraz[i-1][j-1];
	for (int i = 0; i < 200; i++)
	{
		kopia[i+1][0] = obraz[i][0];
		kopia[i+1][321] = obraz[i][319];
	}
	for (int j = 0; j < 320; j++)
	{
		kopia[0][j+1] = obraz[0][j];
		kopia[201][j+1] = obraz[199][j];
	}
	int piksele = 0;
	for (int i =1; i <= 200; i++)
	{
		for (int j = 1; j <= 320; j++)
		{
			int a = abs(kopia[i][j] - kopia[i][j-1]);
			int b = abs(kopia[i][j] - kopia[i-1][j]);
			int c = abs(kopia[i][j] - kopia[i+1][j]);
			int d = abs(kopia[i][j] - kopia[i][j+1]);
			if (a >128 || b > 128 || c >128 || d > 128)
				piksele ++;
		}
	}
	wyj<< "\n3)\n" << piksele << "\n\n";
	int makslok = 1, maksglob = 0;
	for (int i = 0; i < 320; i++)
	{
		makslok = 1;
		for (int j = 1; j < 200; j++)
		{
			if (obraz[j][i] == obraz[j-1][i])
				makslok++;
			else
			{
				maksglob= max(maksglob, makslok);
				makslok = 1;
			}
		}
	}
	wyj << "\n4)\n" << maksglob;
}
