#include <bits/stdc++.h>
using namespace std;
double f (double x)
{
	return (x*x*x*x/500 - x*x/200 -3.0/250);
}
double g (double x)
{
	return (-x*x*x/30	+ x/20 + 1.0/6);
}
double pole (double a, double b, double blad)
{
	//zadaniesprowadza sie do policzenia sumy dwoch pol: pola powierzchni pomiedzy wykresem funkcji f(x) i osia X oraz pola powierzchni miedzy wykresem
	//funkcji g(x) i osia OX. Uwzgldniajac fakt, ze f(x) jest rosnaca w przedziale [2,10], pole obszaru ograniczonego osia OX oraz wykresem funkcji f(x)
	// w zadanym przedziale moznemy szacowac z gory oraz z dolu przy pomocy pol obszarow zlozonych z prostokatow
	//przedzial [2,10] dzielimy na n rownych czesci, ktorych konce oznaczamy jako xi(i=1, ...., n), przyjmijmy tez ze x0 = 2
	double pfgora = 0, pggora = 0, pfdol = 0, pgdol = 0, pf, pg;
	double h, x;
	int n = 10;	//przyjmuje sobie rozne wartosci n az do uzyskania oczekiwanego rezultatu
	//pole f  //f jest funkcja rosnaca w przedziale 2 10
	do 
	{
		h = (b - a) / n; 
		x = a;
		pfdol = pfgora = 0;
		for (int i = 0; i < n; i ++)
		{
			pfdol += f(x);
			x += h;
			pfgora += f(x);
		}
		pfgora *= h;
		pfdol *= h;
		n *= 2;
	}
	while (pfgora - pfdol > blad / 2);
	pf = (pfgora + pfdol)/2;
	//pole g
	x = a; n = 10;
	do 
	{
		h = (b - a) / n; x = a;
		pgdol = pggora = 0;
		for (int i = 0; i < n; i++)
		{
			pgdol -= g(x);
			x += h;
			pggora -= g(x);
		}
		pggora *= h;
		pgdol*=h;
		n *= 2;
	}
	while (pggora -pgdol > blad / 2);
	pg = (pggora + pgdol)/2;
	return (pf + pg);
} 
double dlugosc (double a, double b, double n)
{
	double d  = 0;
	d +=16 + f(10) - g(10);
	double h = 1.0*(b-a)/n;
	double x = a;
	double tmp;
	//dlugosc luku f
	for (int i = 0; i < n; i++)
	{
		tmp = sqrt(h*h + (f(x+h) - f(x))*(f(x+h) - f(x)));
		d += tmp; //nowa dlugosc
		x += h; //zmiana x_i
	}
	//dlugosc luku g
	x = a;
	for (int i = 0; i < n; i++)
	{
		tmp = sqrt(h*h + (g(x+h) - g(x)) * (g(x+h) - g(x)));
		d += tmp; //nowa dlugosc
		x += h;	// zmiana x_i
	}
	return d;	
} 
double zadanie3()
{
	double d  = 0;
	for (double x = 2; x <= 9.75; x += 0.25)
		d += floor(f(x) - g(x));
	return d;
}
int main ()
{
	ofstream wyj("zadanie_zaslona.txt");
	//1) z dokladnoscia do 1/1000
	cout << "1)\n" << pole(2, 10, 0.001) << "\n\n"; // ograniczenie z lewej i z gory/dolu dla podanych argumentow
	cout << "2)\n" << ceil(dlugosc(2, 10, 1000)) << "\n\n";
	cout << "3)\n" << zadanie3();
	
}
