#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

void input(double* a, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	cout << endl;
}

void Print(double* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int indexMax(double* a, const int size)
{
	double max = a[0];
	int imax = 0;
	for (int i = 0; i < size; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			imax = i;
		}
	}
	return imax;
}

int indexMin(double* a, const int size)
{
	double min = a[0];
	int imin = 0;
	for (int i = 0; i < size; i++)
	{
		if (min > a[i])
		{
			min = a[i];
			imin = i;
		}
	}
	return imin;
}


int indexMaxAbs(double* a, const int size)
{
	double max = abs(a[0]);
	int imax = 0;
	for (int i = 0; i < size; i++)
	{
		if (max < abs(a[i]))
		{
			max = abs(a[i]);
			imax = i;
		}
	}
	return imax;
}

int indexMinAbs(double* a, const int size)
{
	double min = abs(a[0]);
	int imin = 0;
	for (int i = 0; i < size; i++)
	{
		if (min > abs(a[i]))
		{
			min = abs(a[i]);
			imin = i;
		}
	}
	return imin;
}

double suma(double* a, int index1, int index2)
{
	int start = min(index1, index2);
	int finish = max(index1, index2);
	double suma = 0;
	for (int i = start + 1; i < finish; i++)
	{
		suma += a[i];
	}
	return suma;
}

double dob(double* a, int index1, int index2)
{
	int start = min(index1, index2);
	int finish = max(index1, index2);
	double dob = 1;
	for (int i = start + 1; i < finish; i++)
	{
		dob *= a[i];
	}
	return dob;
}

void Sort(double* a, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		double max = a[i];
		int imax = i;
		for (int j = i + 1; j < size; j++)
			if (max < a[j])
			{
				max = a[j];
				imax = j;
			}
		a[imax] = a[i];
		a[i] = max;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	int n = 0;
	cout << "Введіть розмір масиву: "; cin >> n;
	double* a = new double[n];

	input(a, n);
	Print(a, n);

	cout << "Сума елементів між мінімальним і максимальним: " << suma(a, indexMin(a, n), indexMax(a, n)) << endl;
	cout << "Добуток елементів між мінімальним і максимальним за модулем: " << dob(a, indexMin(a, n), indexMax(a, n)) << endl;

	cout << "Відсортований масив за спаданням: " << endl;
	Sort(a, n);
	Print(a, n);

	delete[] a;

	return 0;
}