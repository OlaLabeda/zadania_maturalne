#include <bits/stdc++.h>
using namespace std;
int main ()
{
	string s;
	cin >> s;
	double w = 0;
	int i = 0;
	while (s[i] != ',')
	{
		w*=2;
		w+=(int(s[i]-48)*2.0);
		i++;
	}
	cout << w << endl;
	w/=2;
	if (s[i+1] !='0' ) w+= 0.5;
	if (s[i+2] !='0' ) w+= 0.25;
	cout << " "<< w << endl;
}
