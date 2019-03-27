// В строке после каждого слова с нечётной длиной, начинающегося с заданного символа, вставить заданную подстроку, например (”**”.. 

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <clocale> 
#include <cstring> 

using namespace std;

const int MAX = 255;

void init_string(char* &str);
void init_subString(char* &str);
void init_dvymerniy_array(char**& arr, int k);
void enter_letter(char &letter);
int findNumberOfWords(char* str, int cnt);
void arrayFill(char* str, char** arr);
void addSubStr(char** arr, char letter, char* subStr, int k);
void free_memory(char* &str);
void free_memory_dvymerniy_array(char**&arr, int k);

void init_string(char* &str) {
	char buf1[MAX];
	cout << "Введите пожалуйста строку:\n";
	cin.getline(buf1, MAX);
	str = new (nothrow) char[strlen(buf1) + 1];
	if (!str) {
		cout << "No memory \n";
		system("pause");
		exit(1);
	}
	strcpy(str, buf1);
	return;
}
void init_subString(char* &str) {
	char buf2[MAX];
	cout << "Введите пожалуйста подстроку:\n";
	cin.getline(buf2, MAX);
	str = new (nothrow) char[strlen(buf2) + 1];
	if (!str) {
		cout << "No memory \n";
		system("pause");
		exit(1);
	}
	strcpy(str, buf2);
	return;
}

void init_dvymerniy_array(char**& arr, int k) {
	arr = new (nothrow) char*[k];
	if (!arr) {
		cout << "No memory \n";
		system("pause");
		exit(1);
	}
	for (int i{ 0 }; i < k; ++i)
	{
		arr[i] = new (nothrow) char[MAX];
		if (!arr[i]) {
			cout << "No memory \n";
			system("pause");
			exit(1);
		}
	}
	return;
}

void enter_letter(char &letter) {
	cout << "Введите пожалуйста символ начала слова, по которому будет проходить отбор:\n";
	cin >> letter;
	return;
}

int findNumberOfWords(char* str, int cnt)
{
	char* tmp = new (nothrow) char[strlen(str) + 1];
	if (!tmp) {
		cout << "No memory \n";
		system("pause");
		exit(1);
	}
	strcpy(tmp, str);
	char * p = strtok(tmp, " ,.-;");
	while (p != nullptr)
	{
		p = strtok(NULL, " ,.-");
		++cnt;
	}
	delete[] tmp;
	tmp = nullptr;
	return cnt;
}

void arrayFill(char* str, char** arr)
{
	int i{ 0 };
	char *h = str;
	char str1[] = ",.; \t";
	while (*h)
	{
		h += strspn(h, str1);
		int length = strcspn(h, str1);
		if (length == 0)
			break;
		strncpy(arr[i], h, length);
		arr[i][length] = '\0';
		h += length;
		++i;
	}
	return;
}

void addSubStr(char** arr, char letter, char* subStr, int k)
{
	for (int i = 0; i < k; ++i)
	{
		if (strlen(arr[i]) % 2)
			if (arr[i][0] == letter)
				cout << arr[i] << subStr << "\n";
	}
	return;
}

void free_memory(char* &str) {
	delete[]str;
	str = nullptr;
	return;
}

void free_memory_dvymerniy_array(char**&arr, int k) {
	for (int i = 0; i < k; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
	return;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int cnt{ 0 }, k;
	char letter;
	char* str = nullptr;
	char* subStr = nullptr;
	char** arr = nullptr;

	init_string(str);
	init_subString(subStr);
	enter_letter(letter);

	k = findNumberOfWords(str, cnt);

	init_dvymerniy_array(arr, k);
	arrayFill(str, arr);
	addSubStr(arr, letter, subStr, k);

	free_memory(str);
	free_memory(subStr);
	free_memory_dvymerniy_array(arr, k);

	system("pause");
	return 0;
}
