// Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.

#include <iostream>
#include <clocale>
#include <ctime>

using namespace std;

void initArrRandom(int* Arr, int n) {
	for (int i = 0; i < n; ++i) {
		*(Arr + i) = rand() % 100;
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
void sortStartWithValueK(int* Arr, int n,int k) {
	int tmp;
	k--;
	for (int i = k; i < n - 1; i++) {
		for (int j = k; j < n - i - 1 + k; j++) {
			if (*(Arr+j) > *(Arr + j + 1)) {
				tmp = *(Arr + j);
				*(Arr + j) = *(Arr + j + 1);
				*(Arr + j + 1) = tmp;
			}
		}
	}
	return;
}
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int n, k;
	cout << "Введите размер массива: ";
	cin >> n;
	cout << "Введите с какого элемента сортировать по возрастанию: ";
	cin >> k;
	int* Arr = new (nothrow) int[n];
	if (!Arr) {
		cout << "error!" << "\n";
		system("pause");
		return 0;
	}

	initArrRandom(Arr, n);
	cout << "Изначальный массив: ";
	printArr(Arr,n);
	cout << "Отсортированный массив: ";
	sortStartWithValueK(Arr, n, k);
	printArr(Arr, n);
	delete[]Arr;
	Arr = nullptr;
	system("pause");
	return 0;
}