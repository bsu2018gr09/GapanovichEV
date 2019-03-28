// В массиве А(N,М) расположить строки в порядке возрастания их максимальных элементов.

#include <iostream>
#include <clocale>
#include <iomanip>
#include <ctime>

using namespace std;

void give_memory(int**&arr, int n, int m);
void give_memoryArrMaxElements(int* &ArrOfMaxElements, int n);
void free_arr(int** &arr, int n, int);
void freeArrayMaxElements(int* &ArrOfMaxElements);
void init_arr(int** arr, int n, int m);
void print_arr(int** arr, int n, int m);
void findMax(int** arr, int* ArrOfMaxElements, int n, int m);
void sort(int** arr, int* ArrOfMaxElements, int n, int m);


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

void give_memoryArrMaxElements(int* &ArrOfMaxElements, int n) {
	ArrOfMaxElements = new (nothrow) int[n];
	if (!ArrOfMaxElements) {
		cout << "Error" << "\n";
		system("pause");
		exit(0);
	}
	return;
}

void free_arr(int** &arr, int n, int) {
	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
	return;
}
void freeArrayMaxElements(int* &ArrOfMaxElements) {
	delete[]ArrOfMaxElements;
	ArrOfMaxElements = nullptr;
	return;
}
void init_arr(int** arr, int n, int m) {
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
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				arr[i][j] = rand() % a - rand() % b;
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
void findMax(int** arr, int* ArrOfMaxElements, int n, int m) {
	int max;
	for (int i = 0; i < n; ++i) {
		max = arr[i][0];
		for (int j = 0; j < m; ++j)
			if (arr[i][j] > max)
				max = arr[i][j];
		ArrOfMaxElements[i] = max;
	}
	return;
}
void sort(int** arr, int* ArrOfMaxElements, int n, int m) {
	char flag{ 0 };
	for (int i = 0; i < n - 1; ++i) {
		flag = 0;
		for (int j = 0; j < n - i - 1; ++j) {
			if (ArrOfMaxElements[j] > ArrOfMaxElements[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swap(ArrOfMaxElements[j], ArrOfMaxElements[j + 1]);
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
	return;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int n, m;
	cout << "Введите размер массива n на m:" << "\n";
	cout << "Количество строк:";
	cin >> n;
	if (n <= 0) {
		cout << "Пожалуйста, выберите положительное число для количества строк!" << "\n";
		system("pause");
		exit(0);
	}
	cout << "Количество столбцов:";
	cin >> m;
	if (m <= 0) {
		cout << "Пожалуйста, выберите положительное число для количества столбцов!" << "\n";
		system("pause");
		exit(0);
	}

	int* ArrOfMaxElements = nullptr;
	give_memoryArrMaxElements(ArrOfMaxElements,n);

	int **arr = nullptr;
	give_memory(arr, n, m);

	init_arr(arr, n, m);
	cout << "Исходный массив:" << "\n";
	print_arr(arr, n, m);

	findMax(arr, ArrOfMaxElements, n, m);
	sort(arr, ArrOfMaxElements, n, m);

	cout << "Отсортированный массив, строки расположены в порядке возрастания их максимальных элементов" << "\n";
	print_arr(arr, n, m);

	cout << "\n";

	free_arr(arr, n, m);
	freeArrayMaxElements(ArrOfMaxElements);

	system("pause");
	return 0;
}
