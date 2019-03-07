// В массиве А(N,М) расположить строки в порядке возрастания их максимальных элементов.

#include <iostream>
#include <clocale>
#include <iomanip>
#include <ctime>

using namespace std;

void give_memory(int**&arr, int n, int m);
void free_arr(int** arr, int n, int);
void init_arr(int** arr, int n, int m);
void print_arr(int** arr, int n, int m);
int findMax(int* arr, int n);
void sort(int** arr, int n, int m);


void give_memory(int**&arr, int n, int m) {
	arr = new (nothrow) int*[n];
	if (!arr) {
		cout << "Error!" << "\n";
		system("pause");
		exit(0);
	}
	for (int i = 0; i < n; ++i) {
		arr[i] = new (nothrow) int[m];
		if (!arr[i]) {
			cout << "Error" << "\n";
			system("pause");
			exit(0);
		}
	}
	return;
}
void free_arr(int** arr, int n, int) {
	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
	return;
}
void init_arr(int** arr, int n, int m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr[i][j] = rand() % 30 - rand() % 50;
	return;
}
void print_arr(int** arr, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << setw(5) << arr[i][j];
		cout << "\n";
	}
	return;
}
int findMax(int* arr, int m) {
	int max = *arr;
	for (int i = 0; i < m; ++i) {
		if (arr[i] >= max)
			max = arr[i];
	}
	return max;
}
void sort(int** arr, int n, int m) {
	for (int i = 0; i < n; ++i)
		cout << "максимальный элемент в " << i << "-й строке: " << findMax(*(arr + i), m) << "\n";
	cout << "\n";
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j)
			if (findMax(*(arr + j), m) > findMax(*(arr + j + 1), m))
				swap(*(arr + j), *(arr + j + 1));
	return;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int n, m;
	cout << "Введите размер массива n на m:" << "\n";
	cout << "Количество строк:";
	cin >> n;
	if (n<=0) {
		cout << "Пожалуйста, выберите положительное число для количества строк!" << "\n";
		system("pause");
		exit(0);
	}
	cout << "Количество столбцов:";
	cin >> m;
	if (m<=0) {
		cout << "Пожалуйста, выберите положительное число для количества столбцов!" << "\n";
		system("pause");
		exit(0);
	}
	int **arr = nullptr;
	give_memory(arr, n, m);
	init_arr(arr, n, m);
	print_arr(arr, n, m);
	sort(arr, n, m);
	cout << "Отсортированный массив, строки расположены в порядке возрастания их максимальных элементов" << "\n";
	print_arr(arr, n, m);
	free_arr(arr, n, m);
	system("pause");
	return 0;
}