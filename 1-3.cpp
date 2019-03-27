// Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, не нарушая порядка следования других элементов.

#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip>

using namespace std;

int* createMemory(int n) {
	int* Arr = new(nothrow) int[n];
	if (!Arr) {
		cout << "Error!" << "\n";
		system("pause");
		exit(0);
	}
	return Arr;
}
void freeMemory(int*& Arr) {
	delete[]Arr;
	Arr = nullptr;
	return;
}
void initArrRandom(int* Arr, int n) {
	int a, b;
	cout << "Введите два положительных числа для заполнения массива случайными числами:\n";
	cout << "1-е число: ";
	cin >> a;
	cout << "2-е число: ";
	cin >> b;
	if (a <= 0 || b <= 0) {
		cout << "Нужно ввести положительные числа!\n";
		system("pause");
		exit(0);
	}
	else
		for (int i = 0; i < n; ++i) {
			*(Arr + i) = rand() % a - rand() % b;
		}
	return;
}
void printArr(int* Arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << setw(4) << *(Arr + i);
	}
	return;
}

bool primeNumber(int n)
{
	if (n <= 1)
	{
		return false;
	}
	bool isPrime = true;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}

void sort(int *Arr, int n) {
	char flag{ 0 };
	for (int i = 0; i < n; ++i) {
		if (primeNumber(*(Arr + i))) {
			flag = 0;
			for (int j = 0; j < n; ++j) {
				if (primeNumber(*(Arr + j)) && *(Arr + i) < *(Arr + j)) {
					swap(*(Arr + i), *(Arr + j));
					flag = 1;
				}
			}
			if (!flag)
				break;
		}
	}
	return;
}
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	if (n <= 0) {
		cout << "Пожалуйста, введите положительное число для размера массива" << "\n";
		system("pause");
		exit(0);
	}
	int*Arr = createMemory(n);
	initArrRandom(Arr, n);
	cout << "Исходный массив:\n";
	printArr(Arr, n);
	sort(Arr, n);
	cout << "\n";
	cout << "Сортированный массив:\n";
	printArr(Arr, n);
	cout << "\n";
	freeMemory(Arr);
	system("pause");
	return 0;
}
