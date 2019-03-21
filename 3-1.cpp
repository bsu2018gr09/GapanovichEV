// В строке после каждого слова с нечётной длиной, начинающегося с заданного символа, вставить заданную подстроку, например (”**”.. 

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <clocale> 
#include <cstring> 

using namespace std;

const int MAX = 255;

int findNumberOfWords(char* str, int cnt);
void arrayFill(char* str, char** arr);
void addSubStr(char** arr, char letter, char* subStr, int k);

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

int main()
{
	setlocale(LC_ALL, "ru");
	int cnt{ 0 }, k;
	char buf1[MAX], buf2[MAX], letter;

	cout << "Введите пожалуйста строку:\n";
	cin.getline(buf1, MAX);
	char* str = new (nothrow) char[strlen(buf1) + 1];
	if (!str) {
		cout << "No memory \n";
		system("pause");
		exit(1);
	}
	strcpy(str, buf1);

	cout << "Введите пожалуйста подстроку:\n";
	cin.getline(buf2, MAX);
	char* subStr = new (nothrow) char[strlen(buf2) + 1];
	if (!subStr) {
		cout << "No memory \n";
		system("pause");
		exit(1);
	}
	strcpy(subStr, buf2);

	cout << "Введите пожалуйста символ начала слова, по которому будет проходить отбор:\n";
	cin >> letter;

	k = findNumberOfWords(str, cnt);

	char** arr = new (nothrow) char*[k];
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

	arrayFill(str, arr);
	addSubStr(arr, letter, subStr, k);

	delete[]str;
	delete[]subStr;
	for (int i = 0; i < k; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
	str = nullptr;
	subStr = nullptr;

	system("pause");
	return 0;
}