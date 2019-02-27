//	Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. 
//	Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.

#include<iostream>
#include<ctime>

using namespace std;

int* createMemory(int n) {
	int* Arr = new(nothrow) int[n];
	if (!Arr) {
		cout << "error!" << "\n";
		system("pause");
		return 0;
	}
	return Arr;
}
void freeMemory(int*& Arr) {
	delete[]Arr;
	Arr = nullptr;
	return;
}
void initArrRandom(int* Arr, int n) {
	for (int i = 0; i < n; ++i) {
		*(Arr + i) = (rand() % 100) - (rand() % 100);
	}
	return;
}
void printArr(int* Arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << *(Arr + i) << ",";
	}
	cout << "\n";
	return;
}
void sort(int* Arr, int n) {
	int cnt1{ 0 }, tmp;
	for (int i = n - 1; i >= 0;--i) {
		if (*(Arr + i) > 0) {
			swap(*(Arr + i), *(Arr + n - 1 - cnt1));
			++cnt1;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (*(Arr + j) < *(Arr + j + 1)) {
				if (*(Arr + j + 1) <= 0) {
					swap(*(Arr + i), *(Arr + i + 1));
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
	int*Arr=createMemory(n);
	initArrRandom(Arr, n);
	cout << "Исходный массив: " << "\n";
	printArr(Arr, n);
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
	cout << "Сортированный массив: " << "\n";
	printArr(Arr, n);
	freeMemory(Arr);
	system("pause");
	return 0;
}