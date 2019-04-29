// Класс квадратные уравнения. Хранить коэффициенты и корни.
//много где не хватает const!!!!!
#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

class QuadraticEquation {
private:
	double _a; // коэффициент 'a' квадратного уравнения ах^2+bx+c=0
	double _b; // коэффициент 'b' квадратного уравнения ах^2+bx+c=0
	double _c; // коэффициент 'c' квадратного уравнения ах^2+bx+c=0
	double _x1; // корень квадратного уравнения ах^2+bx+c=0
	double _x2; // корень квадратного уравнения ах^2+bx+c=0

public:
	QuadraticEquation() : _a{ 1 }, _b{ 1 }, _c{ 1 } {if (!_a) { _a = 1; } cout << "Constructor works\n"; };// почему не все поля проинициализированны????
	QuadraticEquation(double a, double b, double c) : _a{ a }, _b{ b }, _c{ c } {if (!_a) { _a = 1; } cout << "Constructor with coefficients a,b,c works\n"; };// не всё, что надо он делает????
	QuadraticEquation(const QuadraticEquation &t) : _a{ t._a }, _b{ t._b }, _c{ t._c }{ cout << "Copy constructor\n"; };// не всё, что надо он делает????
	~QuadraticEquation() { cout << "Destructor works\n"; };

	void set_a(double a) { if (!a) { _a = 1; } else { _a = a; } };// не всё, что надо он делает????
	void set_b(double b) { _b = b; };// не всё, что надо он делает????
	void set_c(double c) { _c = c; };// не всё, что надо он делает????

	double get_a() { return _a; };
	double get_b() { return _b; };
	double get_c() { return _c; };

	QuadraticEquation& operator = (const QuadraticEquation& p) {// не всё, что надо он делает????
		_a = p._a;
		_b = p._b;
		_c = p._c;
		return *this;
	}
	QuadraticEquation operator + (const QuadraticEquation& q) {// не всё, что надо он делает????
		if (!(_a + q._a))
		{
			cout<<"It is impossible to add, because the coefficient at 'a' is zero\n";
			return QuadraticEquation(*this);
		}
		return QuadraticEquation(_a + q._a, _b + q._b, _c + q._c);
	}
	QuadraticEquation operator - (const QuadraticEquation& q) {// не всё, что надо он делает????
		if (!(_a - q._a))
		{
			cout << "Impossible to subtract, because the coefficient at 'a' is zero\n";
			return QuadraticEquation(*this);
		}
		return QuadraticEquation(_a - q._a, _b - q._b, _c - q._c);
	}
	QuadraticEquation operator * (double q) {//а зачем тут &
		if (!(_a * q))
		{
			cout << "Impossible to multiply, because the coefficient at 'a' is zero\n";
			return QuadraticEquation(*this);
		}
		return QuadraticEquation(_a * q, _b * q, _c * q);
	}
	QuadraticEquation operator / (double q) {
		if (!q) {
			cout << "Impossible to divide\n";
			return QuadraticEquation(*this);
		}
		return QuadraticEquation(_a / q, _b / q, _c / q);
	}
	
	void get_roots(int* array_roots) {//зачем ЭТО всё тут???????????????? Подумай
		if (!_b && !_c) {
			_x1 = 0;
			array_roots[0] = _x1;
			cout << "One root: " << "x = " << _x1 << "\n";
		}
		if (!_b && _c != 0) {
			if (((-1)*_c / _a) > 0) {
				_x1 = sqrt((-1)*_c / _a);
				_x2 = (-1)* sqrt((-1)*_c / _a);
				array_roots[0] = _x1;
				array_roots[1] = _x2;
				cout << "Two roots: " << "x1 = " << _x1 << "," << "x2 = " << _x2 << "\n";
			}
		}
		if (_b != 0 && !_c) {
				_x1 = 0;
				_x2 = (-1)*_b / _a;
				array_roots[0] = _x1;
				array_roots[1] = _x2;
				cout << "Two roots: " << "x1 = " << _x1 << "," << "x2 = " << _x2 << "\n";
		}
		if(_b!=0 && _c!=0){
			double D = _b * _b - 4 * _a * _c;
			if (D < 0) {
				array_roots = nullptr;
				cout << "No roots\n";
			}
			if (D == 0) {
				_x1 = (-1) * _b / (2 * _a);
				array_roots[0] = _x1;
				cout << "One root: " << "x = " << _x1 << "\n";
			}
			if (D > 0) {
				_x1 = ((-1)*_b + sqrt(D)) / (2 * _a);
				_x2 = ((-1)*_b - sqrt(D)) / (2 * _a);
				array_roots[0] = _x1;
				array_roots[1] = _x2;
				cout << "Two roots: " << "x1 = " << _x1 << "," << "x2 = " << _x2 << "\n";
			}
		}
	}

	friend ostream& operator << (ostream & stream, const QuadraticEquation& q)
	{
		cout << q._a << "x^2";
		if (q._b >= 0)
			cout << "+" ;

		cout << q._b << "x";
		if (q._c >= 0)
			cout << "+";
		cout << q._c << " = 0" << "\n";

		return stream;
	}
	friend istream& operator >> (istream & stream, QuadraticEquation& q)
	{
		stream >> q._a >> q._b >> q._c;
		return stream;
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	int* array_roots = new (nothrow) int[3];
	if (!array_roots) { cout << "No memory"; system("pause"); exit(1); }

	QuadraticEquation q1{};
	QuadraticEquation q2{ 0,0,0 };
	cout << "q2: ";
	cout << q2;
	q2.get_roots(array_roots);
	cout << "=====================================================\n";

	QuadraticEquation p1{ 1,-5,6 };
	cout << "p1: ";
	cout << p1;
	QuadraticEquation p2{ 6,-4,0 };
	cout << "p2: ";
	cout << p2;
	QuadraticEquation p3{};
	p3 = p1 + p2;
	cout << "p3 = p1 + p2: ";
	cout << p3;
	p3.get_roots(array_roots);
	cout << "=====================================================\n";

	QuadraticEquation t1{ 1,-5,6 };
	cout << "t1: ";
	cout << t1;
	QuadraticEquation t2{ 1,-4,0 };
	cout << "t2: ";
	cout << t2;
	QuadraticEquation t3{};
	t3 = t1 - t2;
	cout << "t3 = t1 - t2: ";
	cout << t3;
	t3.get_roots(array_roots);
	cout << "=====================================================\n";

	QuadraticEquation h1{ 0.5,-2.5,3 };
	cout << "h1 = ";
	cout << h1;
	QuadraticEquation h2{};
	double tmp1;
	cout << "Введите переменную (tmp1) на которую умножим квадратное уравнение ax^2+bx+c=0: ";
	cin >> tmp1;
	h2 = h1 * tmp1;
	cout << "h2 = h1 * tmp1: ";
	cout << h2;
	h2.get_roots(array_roots);
	
	cout << "=====================================================\n";

	QuadraticEquation f1{ 2,-10,12 };
	cout << "f1: ";
	cout << f1;
	QuadraticEquation f2{};
	double tmp2;
	cout << "Введите переменную (tmp2) на которую разделим квадратное уравнение ax^2+bx+c=0: ";
	cin >> tmp2;
	f2 = f1 / tmp2;
	cout << "f2 = f1 / tmp2 : ";
	cout << f2;
	f2.get_roots(array_roots);
	cout << "=====================================================\n";

	QuadraticEquation* array = new (nothrow) QuadraticEquation[3];
	if (!array) {
		cout << "No memory!";
		system("pause");
		exit(1);
	}
	array[0] = t1, array[1] = t2, array[2] = p1;

	f2 = array[0] - t2;
	cout << "f2 = array[0] - t2: ";
	cout << f2;
	f2.get_roots(array_roots);
	cout << "=====================================================\n";

	f2 = *(array + 1) + p1;
	cout << "f2 = *(array + 1) + p1: ";
	cout << f2;
	f2.get_roots(array_roots);
	cout << "=====================================================\n";

	f2 = *(array + 2) * tmp1;
	cout << "f2 = *(array+2) * tmp1: ";
	cout << f2;
	f2.get_roots(array_roots);
	cout << "=====================================================\n";

	f2 = *(array + 2) / tmp2;
	cout << "f2 = *(array+2) / tmp2: ";	
	cout << f2;
	f2.get_roots(array_roots);

	delete[]array_roots;
	delete[]array;
	array_roots = nullptr;
	array = nullptr;

	system("pause");
	return 0;
}
