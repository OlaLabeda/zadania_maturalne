#include <bits/stdc++.h>
using namespace std;
int main ()
{
	//plansza n x m
	//numeracja od 1
	//kazda komorka zywa - x lub martwa - .
	//zakladamy ze komorki z prawej krawedzi siatki
	//sasiaduja z komorkami z lewej krawedzi siatki
	//a komorki z gornego wiersza siatki z komorkami z dolnego wiersza siatki
	//kazda komorka ma 8 sasiadow polaczonych z nia bokiem lub wierzcholkiem
	//zywe w nastepnym - komorki ktore w nbiezacym pokoleniu spelniaja jeden z dwoch warunkow
	//-zywa i ma 2/3 sasiadow zywych  - inaczej umiera z samotnosci lub ze zbyt duzego zageszczenia
	//komorka  jest martwa, ale ma 3 zywych sasiadow
	//UWAGA Plansze z nowym pokoleniem mozna wyznaczac dopiero gdy ma sie wszytskie informacje o starym pokoleniu
	ifstream wej("gra.txt");
	//12x20 - rozmieszczenie zywych i martych
	char gra[12][20], pomocnicza[12][20];
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			wej >> gra[i][j];
			pomocnicza[i][j] = gra[i][j];
		}
	}
	for (int i = 1; i <= 37; i++)
	{
		char pom[3][3];
		for (int j = 0; j < 3; j++)
		{
			for (int l = 17; l <= 19; l++)
			{
				cout << gra[j][l]<< " ";
			}
			cout << endl;
		}
	}
	
	
}
