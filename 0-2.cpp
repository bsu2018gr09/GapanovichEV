// ¬ массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.

#include <iostream>
#include <clocale>
#include <ctime>

using namespace std;

void initArrRandom(int* Arr, int n, int a, int b) {
	for (int i = 0; i < n; ++i) {
		*(Arr + i) = rand() % ((b - a + 1) + a);
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
void countMaxLength(int* Arr, int n) {
	int cnt1{ 1 }, cnt2{ 1 };
	for (int i = 1; i < n;++i) {
		if (*(Arr + i) == *(Arr + (i - 1))) {
			while (*(Arr + i) == *(Arr + (i - 1))) {
				++cnt1;
				++i;
			}
		}
		if (cnt1 > cnt2) {
			cnt2 = cnt1;
		}
		cnt1 = 1;
	}
	cout << "ћаксимальна€ длина=" << cnt2 << "\n";
	return;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int n;
	cout << "¬ведите размер массива: ";
	cin >> n;
	int* Arr = new (nothrow) int[n];
	if (!Arr) {
		cout << "error!" << "\n";
		system("pause");
		return 0;
	}
	initArrRandom(Arr, n, 0, 10);
	printArr(Arr, n);
	countMaxLength(Arr, n);
	delete[]Arr;
	Arr = nullptr;
	system("pause");
	return 0;
}