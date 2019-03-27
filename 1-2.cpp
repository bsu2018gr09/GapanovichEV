//	Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. 
//	Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.

#include <iostream>
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
void initArrRandom(int* Arr, int n){
	int a, b;
	cout << "Введите два положительных числа для заполнения массива случайными числами:\n";
	cout << "1-е число: "; 
	cin >> a;
	cout << "2-е число: ";
	cin >> b;
	if (a <=0 || b <= 0) {
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
void sort(int* Arr, int n) {
	int cnt1{ 0 };
	for (int i = n - 1; i >= 0; --i) {
		if (*(Arr + i) > 0) {
			swap(*(Arr + i), *(Arr + n - 1 - cnt1));
			++cnt1;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (*(Arr + j) < *(Arr + j + 1)) {
				if (*(Arr + j + 1) <= 0) {
					swap(*(Arr + j), *(Arr + j + 1));
				}
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
	cout << "Исходный массив: " << "\n";
	printArr(Arr, n);
	sort(Arr, n);
	cout << "\n";
	cout << "Сортированный массив: " << "\n";
	printArr(Arr, n);
	cout << "\n";
	freeMemory(Arr);
	system("pause");
	return 0;
}
