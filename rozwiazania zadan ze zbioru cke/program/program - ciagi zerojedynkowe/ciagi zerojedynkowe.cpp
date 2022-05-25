#include <bits/stdc++.h>
using namespace std;
bool czydwucykliczny(string s)
{
	if (s.size()%2!=0)
		return 0;
	int pom = s.size()/2;
	for (int i =0; i < s.size()/2; i++)
	{
		if (s[i] != s[pom])
			return 0;
		pom++;
	}
	return 1;
}
bool czydwiejedynkinieobok (string s)
{
	for (int i =1; i < s.size(); i++)
	{
		if (s[i] =='1' && (s[i] == s[i-1])) //nie zapominaj ze to znaki!
			return 0;
	}
	return 1;
}
int nadziesietne (string s)
{
	int p = 1, n= 0;
	for (int i =s.size()-1; i >=0; i--)
	{
		n+=(s[i]-'0')*p;
		p*=2;	
	}
	return n;
}
bool czypierwsza (int n)
{
	for (int i =2; i<=sqrt(n); i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}
bool czypolpierwsza(int n)
{
	for (int i = 2; i <=sqrt(n); i++)
	{
		if (n%i==0)
		{
			if (czypierwsza(i) && czypierwsza(n/i))
				return 1;
		}
	}
	return 0;
}
int main ()
{
	ifstream wej("ciagi.txt");
	ofstream wyj("wyniki_ciagi.txt");
	string ciagi[1000];
	for (int i =0; i < 1000; i++)
		wej >> ciagi[i];
	wyj << "1)\n";
	for (int i = 0; i < 1000; i++)
		if(czydwucykliczny(ciagi[i]))
			wyj << ciagi[i] << "\n";
			
	wyj << "\n2)\n";
	int ile = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (czydwiejedynkinieobok(ciagi[i]))
			ile++;
	}
	wyj << ile << "\n";
	wyj << "\n3)\n";
	int zlicz =0;
	int mini = 0, maksi = 0;
	for (int i = 0; i < 1000; i++)
	{
		int n = nadziesietne(ciagi[i]);
		if (czypolpierwsza(n))
			{
				if (mini == 0)
					mini = n;
				mini = min(mini, n);
				maksi = max(maksi, n); 
				zlicz++;
			}
	}
	wyj << zlicz <<"\n";
	wyj << "minimalna: "<< mini << "\nmaksymalna: " << maksi << "\n";
}
