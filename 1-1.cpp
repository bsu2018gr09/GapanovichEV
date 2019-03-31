// Даны точки плоскости своими координатами в виде двух одномерных массивов(случайные числа).
// Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.

#include <iostream>
#include <clocale>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

void give_memory(int* &Arr, int n);
void initArrRandomCoords(int* Arr, int n, int k);
void distance(int* X, int* Y, int* D, int a, int b, int c, int n);
void sort(int* X, int* Y, int* D, int n);
void printArr(int* Arr, int n);
void freeMemory(int*& Arr);

void give_memory(int* &Arr,int n) {
	Arr = new (nothrow) int[n];
	if (!Arr) {
		cout << "error!" << "\n";
		system("pause");
		exit(1);
	}
	return;
}
void freeMemory(int*& Arr) {
	delete[]Arr;
	Arr = nullptr;
	return;
}
void initArrRandomCoords(int* Arr, int n, int k) {
		for (int i = 0; i < n; ++i) {
			Arr[i] = rand() % k;
		}
	return;
}
void printArr(int* Arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << *(Arr + i) << ",";
	}
	return;
}

void distance(int* X, int* Y,int* D, int a, int b,int c, int n) {
	for (int i = 0; i < n; ++i) {
		D[i] = abs(a* (*(X + i)) + b * (*(Y + i)) + c) / sqrt(a * a + b * b);
	}
	return;
}
void sort(int* X, int* Y, int* D, int n) {
	char flag{ 0 };
	for (int i = 0; i < n-1; ++i) {
		flag = 0;
		for(int j=0;j<n-i-1;++j){
			if (*(D + j) > *(D + j + 1)) {
				swap(*(X + j), *(X + j + 1));
				swap(*(Y + j), *(Y + j + 1));
				swap(*(D + j), *(D + j + 1));
				flag = 1;
			}
		}
		if (!flag) {
			break;
		}
	}
	return;
}
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int n, a, b, c;
	int* X = nullptr;
	int* Y = nullptr;
	int* D = nullptr;

	cout << "Введите размер массива: ";
	cin >> n;
	if (n <= 0) {
		cout << "Пожалуйста, выберите положительное число для размера массива!" << "\n";
		system("pause");
		exit(1);
	}
	cout << "(ax+by+c=0), введите коэффициенты a,b,c: \n";
	cin >> a >> b >> c;

	give_memory(X, n);
	give_memory(Y, n);
	give_memory(D, n);

	int k;
	cout << "Введите положительное число для заполнения массива случайными числами:\n";
	cin >> k;
	if (k<=0) {
		cout << "Нужно ввести положительное число!\n";
		system("pause");
		exit(1);
	}
	initArrRandomCoords(X, n, k);
	initArrRandomCoords(Y, n, k);

	cout << "Координаты Х: ";
	printArr(X, n);
	cout << "\n";
	cout << "Координаты Y: ";
	printArr(Y, n);
	cout << "\n";

	distance(X, Y, D, a, b, c, n);
	cout << "Расстояния от точек до прямой: ";
	printArr(D, n);
	cout << "\n";

	sort(X, Y, D, n);
	cout << "Координаты точек отсортированны по расстоянию до прямой\n";
	cout << "Координаты Х: ";
	printArr(X, n);
	cout << "\n";
	cout << "Координаты Y: ";
	printArr(Y, n);
	cout << "\n";
	cout << "Расстояния от точек до прямой: ";
	printArr(D, n);
	cout << "\n";

	freeMemory(X);
	freeMemory(Y);
	freeMemory(D);

	system("pause");
	return 0;
}