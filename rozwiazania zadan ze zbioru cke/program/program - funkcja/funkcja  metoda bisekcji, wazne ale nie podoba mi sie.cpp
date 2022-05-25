#include <bits/stdc++.h>
using namespace std;
double fx = 0, wx;
double wartoscfunkcji (double a, double b, double c, double d, double x)
{
	return a+ b*x + c*x*x + d*x*x*x; 
}
void obliczp (double a, double b, double c, double d)
{
	double p;
	for (double i = 4; i < 5; i+=0.000001)
	{
		p = wartoscfunkcji(a, b, c, d, i);
		if (fx < p)
		{
			fx = p;
			wx = i;
		}
	}
}
double mzerowe(double a, double b, double c, double d, double l, double p)
{
	double s = (l+p)/2;
	double pom;
	while (p - l > 0.00000001)
	{
		s =  (l+p)/2.0;
		pom = wartoscfunkcji(a, b, c, d, s);
		//jezeli iloczyn wartosci lewej i srodkowej jest mniejzy niz zero, oznacza to ze lewa lezy przed miejscem zerowym a prawa za
		//dlatego moge przesunac prawa na srodek
		//w przeciwnym przypadku zakaldam ze miejsce zerowe jest bardziej na prawo niz srodek bo zarowno srodek jak i lewa znajduja sie pod OX
		if (wartoscfunkcji(a, b, c, d, l)* pom< 0.0)
			p = s;
		else
			l = s;
	}
	return (l+p)/2.0;
}


int main ()
{
	ifstream wej("funkcja.txt");
	ofstream wyj("wyniki_funkcja.txt");
	double funkcja[6][5];
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 4; j++)
			wej >> funkcja[i][j];
	}
	wyj << "1)\n" <<wartoscfunkcji(funkcja[2][1], funkcja[2][2], funkcja[2][3], funkcja[2][4], 1.5) << "\n\n";
	obliczp(funkcja[5][1], funkcja[5][2], funkcja[5][3], funkcja[5][4]);
	wyj <<"2)\n" << fixed << setprecision(3) << "x: " << wx << "  y: " <<  setprecision(5) << fx << "\n\n";
	//miejsca zerowe
	//funkcja z rysunku ma 4 miejsca zerowe w przedzialach: 01 23 34 45 => trzeba wyznaczyc miejsca zerowe dla f1 f3 f4 f5
	// => metoda bisekcji dla kazdej z nich
	wyj <<	"3)\n";
	for (int i = 1; i <= 5; i++)
	{
		if ( i != 2)
			wyj << mzerowe(funkcja[i][1], funkcja[i][2], funkcja[i][3], funkcja[i][4], i-1,i) << "\n";
	}
	
}
