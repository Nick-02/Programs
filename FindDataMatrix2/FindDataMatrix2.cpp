#include <iostream>

// äîäàòêîâà á³áë³îòåêà 
#include <time.h>

using namespace std;

int main()
{
	// ãåíåðàòîð âèïàäêîâèõ ÷èñåë
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	// ðîçì³ðè ìàòðèöi
	int A[100][100];
	int n, k, i;
	char z;

	n = 5;
	int a = -99;
	int b = 99;

	do
	{
		system("cls");
		printf("\n\tÇàïîâíåííÿ ìàòðèöi A[%2i][%2i] öiëèìè äâîçíà÷íèìè ÷èñëàìè. \n\n", n, n);

		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				do
				{
					A[k][i] = a + rand() % (b - a + 1);
				} while (abs(A[k][i])<10 || abs(A[k][i])>99);
				printf("%5i", A[k][i]);
			}
			cout << "\n";
		}

		//âèâåäåííÿ íà åêðàí êîï³¿
		printf("\n\n\tâèâåäåííÿ íà åêðàí êîïi¿ ìàòðèöi:\n\n");

		int poz, neg, sum, max, min, B[100], p;

		poz = neg = sum = p = 0;
		for (int j = 0; j < n; j++) B[j] = 0;
		long dob = 1;

		for (k = 0; k < n; k++)
		{
			cout << "\t";
			for (i = 0; i < n; i++)
			{
				if (k != i) printf("%5i", A[k][i]);
				else
				{
					printf("    *");
					B[p] = A[k][i];

					if (B[p] > 0)
					{
						poz++;
						sum += B[p];
					}
					else
					{
						neg++;
						dob *= B[p];
					}

					p++;
				}
			}
			cout << "\n";
		}

		max = B[0]; min = B[0];
		for (int j = 0; j < n; j++)
		{
			if (B[j] > max) max = B[j];
			if (B[j] < min) min = B[j];
		}

		printf("\n\n\tÄîäàòíèõ: %i", poz);
		printf("\n\tÂiä'ºìíèõ: %i", neg);
		printf("\n\tÑóìà äîäàòíèõ: %i", sum);
		printf("\n\tÄîáóòîê âiä'ºìíèõ: %i", dob);
		printf("\n\tÍàéáiëüøèé åëåìåíò: %i", max);
		printf("\n\tÍàéìåíøèé åëåìåíò: %i", min);

		cout << "\n\n\tÏðîäîâæèòè (y/n)? ";
		cin >> z;
	} while (z != 'n');


	cout << endl << endl << "\t";
	//system("pause");
	return 0;
}
