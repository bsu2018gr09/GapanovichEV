// Горизонтальный градиент 
// За введенное число step мы переходим от начального цвета к конечному.
// Если в файле осталось место, то заполняем его конечным цветом. Этого в условии нет. Такого я не хочу. 

#include <iostream>
#include <fstream> 
#include <cmath>
#include <clocale>

using namespace std;

struct color {
public:
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
	int newstep;
	float tmp_r, tmp_g, tmp_b;
	unsigned int w, h;
	/*	int step=100; // количество шагов
		float r1=0, g1=0, b1=0; // первоначальные цвета (цвет 1)
		float rr=255, gg=255, bb=255; // конечные цвета (цвет 2 к которому движемся) не работает при w=1024 */
	cout << "Введите пожалуйста шаг:";
	cin >> step;

	cout << "Введите первоначальные R G B цвета: ";
	cin >> r1 >> g1 >> b1;

	cout << "Введите конечные R G B цвета: ";
	cin >> rr >> gg >> bb;

	fff.read((char *)&buf, 18);
	ggg.write((char *)&buf, 18);
	fff.read((char *)&w, 4); cout << "w=" << w;
	fff.read((char *)&h, 4); cout << ", h=" << h;
	w = 400;
	h = 130;
	ggg.write((char *)&w, 4);//не понял???? //- ширина файла rez.bmp изменяется на ширину файла 1.bmp//СПАСИБО КЭП. я не понял ЗАЧЕМ это делать????? Как мне по твоему поментять размер того, что я хочу????
	ggg.write((char *)&h, 4);//не понял???? //- высота файла rez.bmp изменяется на высоту файла 1.bmp
	fff.read((char *)&buf, 28);
	ggg.write((char *)&buf, 28);

	if (step >= w)
		step = w;

	newstep = w / (step + 1);

	if (!newstep)
		newstep = 1;

	step_r = (rr - r1) / ((w / newstep) - 1);
	step_g = (gg - g1) / ((w / newstep) - 1);
	step_b = (bb - b1) / ((w / newstep) - 1);


	tmp_r = r1; tmp_g = g1; tmp_b = b1;

		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
					if (((w - j) >= newstep) && ((j % newstep)==0)) {
						r1 += step_r;
						g1 += step_g;
						b1 += step_b;
					}
				c.r = (unsigned char)r1;
				c.g = (unsigned char)g1;
				c.b = (unsigned char)b1;
				ggg.write((char *)&c, 3);
			}
			r1 = tmp_r;
			g1 = tmp_g;
			b1 = tmp_b;
		}
	fff.close();
	ggg.close();
	//system("pause"); 
	return 1;
}
