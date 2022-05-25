//prime number => has only two divisors, 1 and itself
//1 is not prime
//find numbers, that are square roots of primes!
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool ifprime (long long int n)
{
	long long x = sqrt(n);
	if (x * x != n) return 0;
	int howmanydivisors = 0;
	for (int i = 1; i < sqrt(x); i++)
	{
		if (x % i == 0)
			howmanydivisors += 2;
	}
	if (howmanydivisors == 2)
		return 1;
	return 0;
}
int main ()
{	
	long long liczba;
	ifstream wej("liczby.txt");
	ofstream wyj("zad_5.txt");

	for (int i = 1; i <=500; i++)
	{
		wej >> liczba;
		if (ifprime(liczba) == 1)
			wyj << liczba << "\n";
	}

}
