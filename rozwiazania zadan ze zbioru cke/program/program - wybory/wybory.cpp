#include <bits/stdc++.h>
using namespace std;	
int maksdlakomitetu[5];
int sumamandatowa[5];
int sumamandatowaregion[5];
void mandaty(int glosy[])
{
	double wspol[5];
	int mand[5];
	for (int i = 0; i < 5; i++)
		mand[i] = 0;
	double makswspol = 0;
	for (int k= 1; k<= 20; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			wspol[i] = glosy[i]*1.0 / (2.0*mand[i]+1.0);
			if (makswspol - wspol[i] < 0)
				makswspol = wspol[i];
		}	
		for (int i = 0; i < 5; i++)
		
				if (makswspol == wspol[i])
						{mand[i]++;	
				sumamandatowa[i]++;
			}
		makswspol = 0;
	}

	for (int i = 0; i < 5; i++)
		maksdlakomitetu[i] = max(mand[i], maksdlakomitetu[i]);

}
void mandatywokregach(int glosy[])
{
	double wspol[5];
	int mand[5];
	for (int i = 0; i < 5; i++)
		mand[i] = 0;
	double makswspol = 0;
	for (int k= 1; k<= 100; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			wspol[i] = glosy[i]*1.0 / (2.0*mand[i]+1.0);
			if (makswspol - wspol[i] < 0)
				makswspol = wspol[i];
		}	
		for (int i = 0; i < 5; i++)
		
				if (makswspol == wspol[i])
						{mand[i]++;	
				sumamandatowaregion[i]++;
			}
		makswspol = 0;
	}
}
int main ()
{
	ifstream wej("dane_wybory.txt");
	ofstream wyj("wyniki.txt");
	string okregi[20];
	int komitety[20][5];
	int suma[20];
	double procenty[20][5];
	wyj << "1)\n";
	for (int i = 0; i < 20; i++)
	{
		wej >> okregi[i];
		suma[i] = 0;
		for (int j = 0; j < 5; j++)
		{
			wej >> komitety[i][j];
			suma[i] += komitety[i][j];
		}
		wyj << okregi[i] << ": "<< suma[i] << "\n";
		for (int j = 0; j < 5; j++)
			procenty[i][j] = komitety[i][j]*1.0 / suma[i]*1.0 * 100;
	}
	double maksprocent[5];
	for (int i = 0; i < 5; i++)
		maksprocent[i] = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 5; j++)
			maksprocent[j] = max(maksprocent[j], procenty[i][j]);
	
	wyj << "\n2)\n";
	for (int j = 0; j < 5; j++)	
		for (int i = 0; i < 20; i++)
			if(procenty[i][j] == maksprocent[j])
				wyj <<  "K" <<j+1 << ": "<< okregi[i] << "\n";
				
	for (int i = 0; i < 20; i++)
		mandaty(komitety[i]);
	
	wyj << "\n3)\n";
	for (int i = 0; i < 5; i++)
		wyj << "K" << i + 1 << ": " << maksdlakomitetu[i] << " ";
	wyj << "\n\n4)\na)\n";
	for (int i = 0; i < 5; i++)
		wyj << "K" << i + 1 << ": " << sumamandatowa[i] << " ";
	wyj << "\n\nb)\n";
	int okrpol[4][5];
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 5; j++)
			okrpol[i][j] = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			char c = okregi[i][0];
			int ind = c-'A';
			okrpol[ind][j] += komitety[i][j];
		}
	}
	for (int i = 0; i < 4; i++) 
			mandatywokregach(okrpol[i]);	
	for (int i = 0; i < 5; i++)
		wyj << "K" << i + 1 << ": " << sumamandatowaregion[i] << " ";
	wyj << "\n\n5)\n";
}
