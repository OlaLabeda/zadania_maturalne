#include <bits/stdc++.h>
using namespace std;
int A[100], B[100];
void czy_k_podobne(int n, int k)
{
	int p = 0;
	for (int i = 0; i< n; i++)
	{
		if (A[(i+k)%n+1] != B[i+1])
			{
				cout << "FALSZ";
				p = 1;	
			}
	}
	if (p == 0)
	cout << "PRAWDA";
}
int main ()
{
	int n1;
	cin>>n1;
	int k; cin>>k;
	for (int i = 1; i<= n1; i++)
		cin>>A[i];
	for (int i = 1; i<= n1; i++)
		cin>>B[i];
	
	czy_k_podobne(n1, k);
}
