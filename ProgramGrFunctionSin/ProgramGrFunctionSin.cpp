#define pi 3.1415926535897932384626433832795

#include <iostream>

using namespace std;


int main()
{
	system("color 1f");
	setlocale(LC_ALL, ".1251");

	double a, b;
	a = 0; b = pi/2;
	unsigned n, n_cos, n_sin;
	double xn, xk, x, dx, yt, ycos, ysin, e, sum, ds, sh;

	xn = a; xk = b;
	dx = fabs(xn - xk) / 11;
	
	cout << "\n\n\tÒàáëèöÿ çíà÷åíü ñèíóñà äëÿ êóòiâ ç âiäðiçêó [a;b] : ";
	printf("a=%4.2f; b=%4.2f\n\n", a, b);

	printf("\t×èñëî x\t\tÒî÷íå Yt = Íàáëèæåíå Ysin\t\tIòåðàöié n_sin\tÏîõèáêà E\n\n");
	for (x = xn+0.0001; x <= xk+0.0001; x += dx)
	{
		yt = sin(x);
		sum = 0;
		n = 1;
		n_sin = 1;
		sh = x;
		do
		{
			ds = sum;
			sum += sh;
			sh = (-sh)*x*x / ((n+1)*(n + 2));
			n += 2;
			n_sin++;
		} while (ds != sum);
		ysin = sum;
		e = fabs(yt - ysin) / fabs(yt) * 100;
		printf("\t%lf   %18.16lf = %18.16lf\t\t%d\t%18.16lf\n", x, yt, ysin, n_sin, e);
	}

	cout << "\n\n\tÒàáëèöÿ çíà÷åíü êîñèíóñà äëÿ êóòiâ ç âiäðiçêó [a;b] : ";
	printf("a=%4.2f; b=%4.2f\n\n", a, b);

	printf("\t×èñëî x\t\tÒî÷íå Yt = Íàáëèæåíå Ycos\t\tIòåðàöié n_cos\tÏîõèáêà E\n\n");
	for (x = xn; x <= xk; x += dx)
	{
		yt = cos(x);
		sum = 0;
		n = 1;
		n_cos = 1;
		sh = 1;
		do
		{
			ds = sum;
			sum += sh;
			sh = (-sh)*x*x / (n*(n + 1));
			n += 2;
			n_cos++;
		} while (ds != sum);
		ycos = sum;
		e = fabs(yt - ycos) / fabs(yt) * 100;
		printf("\t%lf   %18.16lf = %18.16lf\t\t%d\t%18.16lf\n", x, yt, ycos, n_cos, e);
	}


	cout << "\n\n\t";
	system("pause");
	return 0;
}
