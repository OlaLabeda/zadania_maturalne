#include <bits/stdc++.h>
using namespace std;
bool czypodzprzez3(string s)
{
	//If the number of even bits minus the number of odd bits is a multiple of 3 
	//(e.g. -3,0,3,6, etc) then the number is divisible by three
	
	int parzystebity = 0, nieparzystebity = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
			parzystebity ++;
		else
			nieparzystebity++;
	}
	if ((abs(parzystebity) - abs(nieparzystebity))%3 == 0)
		return 1;
	return 0;
}
int main ()
{
	ifstream wej1("liczby1.txt");
	ifstream wej2("liczby2.txt");
	ifstream wej3("liczby3.txt");
	string mr12[1000], mr30[1000], mr200[1000];
	for (int i = 0; i < 1000; i++)
	{
		wej1 >> mr12[i];
		cout << mr12[i] << " ";
		wej2 >> mr30[i];
		wej3 >> mr200[i];
	}
}
