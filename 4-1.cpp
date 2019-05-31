// В каждой строке удалить все слова чётной длины, заканчивающиеся на заданную букву.
// Отсортировать строки по количеству удалённых слов.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <clocale>

using namespace std;
const int MAX = 255;

void init_dvymerniy_array(char**& arr, int k);
void init_array_of_deleted_words(int* &arrdel, int n);
void enter_letter(char &letter);
int find_number_of_lines();
void fill_array_with_text(char**& arr, int k);
void delete_words(char**& arr, int k, char &letter, int* arrdel);
void sort(char**& arr, int k, int* arrdel);
void write_to_file(char**&arr, int k);
void free_memory(int* &arrdel);
void free_memory_dvymerniy_array(char**&arr, int k);

void init_dvymerniy_array(char**& arr, int k) {
	arr = new (nothrow) char*[k];
	if (!arr) {
		cout << "No memory \n";
		system("pause");
		exit(1);
	}
	for (int i{ 0 }; i < k; ++i){
		arr[i] = new (nothrow) char[MAX];
		if (!arr[i]) {
			cout << "No memory \n";
			system("pause");
			exit(1);
		}
	}
	return;
}

void init_array_of_deleted_words(int* &arrdel, int n) { // массив для количества удаленных слов
	arrdel = new (nothrow) int[n];
	if (!arrdel) {
		cout << "Error" << "\n";
		system("pause");
		exit(1);
	}
	return;
}

void enter_letter(char &letter) {
	cout << "Введите пожалуйста символ начала слова, по которому будет проходить отбор:\n";
	cin >> letter;
	return;
}

void  fill_array_with_text(char**& arr, int k) {
	ifstream fff("e:\\date.txt"); // отсюда читаем (поток типа ifstream= input file stream)
	char *buff = new(nothrow) char[MAX];
	for (int i = 0; i < k; i++) {
		fff.getline(buff, MAX);
		arr[i] = new(nothrow) char[strlen(buff) + 1];
		strcpy(arr[i], buff);
		if (!arr[i]) { cout << "no memory\n"; exit(1); }
	}
	delete[]buff;
	buff = nullptr;
	fff.close();
}

int find_number_of_lines() {
	int kol = 0; // переменная для подсчета кол-ва срок
	char *tmp = new (nothrow)char[MAX];
	if (!tmp) { cout << "No memory\n"; system("pause"); exit(1); }
	ifstream fff("e:\\date.txt");
	while (!fff.eof()) { fff.getline(tmp, MAX); kol++; } // считаем сколько в файле строк
	fff.clear(); fff.seekg(0); // перешли в начало файла
	delete[]tmp;
	tmp = nullptr;
	fff.close();
	return kol;
}

void delete_words(char**& arr, int k, char &letter, int* arrdel ) // функция, которая удаляет слова
{
	int len;
	char Delim[] = " –.,!?;:-\n\t"; // строка символов-разделителей слов в тексте
	for (int i{ 0 }; i < k; ++i){
		int quantity = 0;
		char* tmp = new (nothrow) char[strlen(arr[i]) + 1];
		if (!tmp){
			cout << "No memory \n";
			system("pause");
			exit(1);
		}
		char * p = arr[i] + strspn(arr[i], Delim);
		while (strlen(p)) {
			len = strcspn(p, Delim); 
			strncpy(tmp, p, len); 
			tmp[len] = '\0';
			if (len % 2 == 0 && tmp[len - 1] == letter){
				strcpy(tmp, p + len);
				strcpy(p, tmp);
				++quantity;
			}
			else
				p += len;
			p += strspn(p, Delim);
		}
		arrdel[i] = quantity;
		delete[] tmp;
		tmp = nullptr;
	}
	return;
}

void sort(char**& arr, int k, int* arrdel) { // функция, которая сортирует строки по возрастанию
	char flag{ 0 };
	for (int i{ 0 }; i < k-1; ++i) {
		flag = 0;
		for (int j = 0; j < k - i - 1; ++j) {
			if (arrdel[j] > arrdel[j + 1]) {
				swap(arr[j], arr[j + 1]);//очень странно сортирует пустые строки
				swap(arrdel[j],arrdel[j + 1]);
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
	return;
}

void write_to_file(char**&arr, int  k) { // запись результата в файл
	ifstream fff("e:\\date.txt");
	ofstream ggg("e:\\result.txt");
	for (int i{ 0 }; i < k; ++i) {
		ggg << arr[i] << "\n";
	}
	fff.close();
	ggg.close();
	return;
}
void free_memory(int* &arrdel) {
	delete[]arrdel;
	arrdel = nullptr;
	return;
}

void free_memory_dvymerniy_array(char**&arr, int k) {
	for (int i = 0; i < k; ++i){
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
	return;
}

int main() {
	setlocale(LC_ALL, "ru");
	ifstream fff("e:\\date.txt"); // отсюда читаем (поток типа ifstream= input file stream)
	ofstream ggg("e:\\result.txt");//сюда пишем (поток типа ofstream= output file stream)
	if (!fff) { cout << "No file e:\\date.txt. Can't open\n"; exit(1); }
	if (!ggg) { cout << "   file e:\\result.txt. Can't create\n"; exit(1); }
	int k{ 0 };
	k = find_number_of_lines();

	char** arr = nullptr; // arr - массив строк
	init_dvymerniy_array(arr, k);

	fill_array_with_text(arr, k);

	int* arrdel = nullptr;
	init_array_of_deleted_words(arrdel, k);

	char letter;
	enter_letter(letter);


	delete_words(arr, k, letter, arrdel);
	sort(arr,k, arrdel);
	write_to_file(arr,k);
	free_memory(arrdel);
	free_memory_dvymerniy_array(arr, k);

	fff.close();
	ggg.close();
	return 0;
}
