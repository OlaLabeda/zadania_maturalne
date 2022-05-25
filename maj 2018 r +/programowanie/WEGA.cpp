#include <bits/stdc++.h>
using namespace std;
int main ()
{
	string s[1000];
	
	ifstream wej("sygnaly.txt");
	ofstream wyj("wyniki4.txt");
	
	string slowo(25, '\0'); 
	int ind = 0;
	
	int maxdlroznych = 0;
	string najslowo;
	
	wyj << "4.3\n";
	
	for (int i = 0; i < 1000; i++)
	{
		wej >> s[i];
		
		int zlicz[26];
		for (int j = 0; j < 26; j++)
			zlicz[j] = 0;
			
		for (int j = 0; j < s[i].size(); j++)
			zlicz[s[i][j]-65]++;
		
		int ileroznych = 0;
		for (int j = 0; j < 26; j++)
			if (zlicz[j] > 0)
				ileroznych ++;
				
		if (ileroznych > maxdlroznych)
		{
			maxdlroznych = ileroznych;
			najslowo = s[i];
		}
		
		if ( (i + 1) % 40 == 0)
		{
			slowo[ind] = s[i][9];
			ind++;
		}
		
		int minlitera = int( s[i][0] ); 
		int makslitera = 0;
		for (int j = 0; j < s[i].size(); j++)
		{
			minlitera = min(int(s[i][j]), minlitera);
			makslitera = max(int(s[i][j]), makslitera);
		}
		
		if (makslitera - minlitera + 1 <= 10)
			wyj << s[i] << endl;
	}
	wyj << "4.1)\n" << slowo<< "\n";
	wyj << "4.2)\n" << maxdlroznych<< "\n" << najslowo;
	
}



