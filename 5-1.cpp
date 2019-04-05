// Горизонтальный градиент

#include <iostream> 
#include <fstream> 
#include <cmath>
#include <clocale>

using namespace std;

struct color { public:
	unsigned char b; 
	unsigned char g; 
	unsigned char r; 
} c;

int main() {
	setlocale(LC_ALL, "ru");

	ifstream fff("e:\\1.bmp", ios::binary);
	ofstream ggg("e:\\rez.bmp", ios::binary);

	if (!fff) { cout << "No file e:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << " file e:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];
	unsigned char r, g, b;
	color c;
	int step; // количество шагов
	float r1, g1, b1; // первоначальные цвета (цвет 1)
	float rr, gg, bb; // конечные цвета (цвет 2 к которому движемся)
	float step_r, step_g, step_b;
	float  tmp_r1, tmp_g1, tmp_b1;
	unsigned int w, h;

	cout << "Введите пожалуйста шаг:";
	cin >> step;

	cout << "Введите первоначальные R G B цвета: ";
	cin >> r1 >> g1 >> b1; 

	cout << "Введите конечные R G B цвета: ";
	cin >> rr >> gg >> bb; 

	c.r = r1; c.g = g1; c.b = b1;
	tmp_r1 = r1, tmp_g1 = g1, tmp_b1 = b1;

	fff.read((char *)&buf, 18);
	ggg.write((char *)&buf, 18);
	fff.read((char *)&w, 4); cout << "w=" << w;
	fff.read((char *)&h, 4); cout << ", h=" << h;
	ggg.write((char *)&w, 4);
	ggg.write((char *)&h, 4);
	fff.read((char *)&buf, 28);
	ggg.write((char *)&buf, 28);

	step_r = abs((rr-r1) / step);
	step_g = abs((gg-g1) / step);
	step_b = abs((bb-b1) / step);

	float Tmp_r1 = ((rr - r1)*(step_r)) / w;
	float Tmp_b1 = ((gg - g1)*(step_g)) / w;
	float Tmp_g1 = ((bb - b1)*(step_b)) / w;

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
				tmp_r1 += Tmp_r1;
				tmp_g1 += Tmp_b1;
				tmp_b1 += Tmp_g1;
				c.r = (unsigned char) tmp_r1;
				c.g = (unsigned char) tmp_g1;
				c.b = (unsigned char) tmp_b1;
				ggg.write((char *)&c, 3);
		}
		tmp_r1 = r1;
		tmp_g1 = g1;
		tmp_b1 = b1;
	}
	fff.close();
	ggg.close();
	//system("pause"); 
	return 1;
}