// Класс квадратные уравнения. Хранить коэффициенты и корни.

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

class QuadraticEquation{
private: 
	double _a; // коэффициент 'a' квадратного уравнения ах^2+bx+c=0
	double _b; // коэффициент 'b' квадратного уравнения ах^2+bx+c=0
	double _c; // коэффициент 'c' квадратного уравнения ах^2+bx+c=0
	double _x1; // корень квадратного уравнения ах^2+bx+c=0
	double _x2; // корень квадратного уравнения ах^2+bx+c=0
public:
	QuadraticEquation() : _a{ 0 }, _b{ 0 }, _c{ 0 } { cout << "Constructor works\n"; };
	QuadraticEquation(double a, double b, double c) : _a{ a }, _b{ b }, _c{ c } {cout << "Constructor with coefficients a,b,c works\n"; };
	QuadraticEquation(const QuadraticEquation &t) { cout << "Copy constructor\n"; };
	~QuadraticEquation() { cout << "Destructor works\n"; };

	void set_a(double a) { _a = a; };
	void set_b(double b) { _b = b; };
	void set_c(double c) { _c = c; };

	double get_a() { return _a; };
	double get_b() { return _b; };
	double get_c() { return _c; };

	QuadraticEquation& operator = (const QuadraticEquation& p){
		_a = p._a;
		_b = p._b;
		_c = p._c;
		return *this;
	}
	QuadraticEquation operator + (QuadraticEquation& q) {
		return QuadraticEquation(get_a() + q.get_a(), get_b() + q.get_b(), get_c() + q.get_c());
	}
	QuadraticEquation operator - (QuadraticEquation& q) {
		return QuadraticEquation(get_a() - q.get_a(), get_b() - q.get_b(), get_c() - q.get_c());
	} 
	QuadraticEquation operator * (double& q) {
		return QuadraticEquation (get_a() * q, get_b() * q, get_c() * q);
	}
	QuadraticEquation operator / (double& q) {
		if (q != 0) {
			return QuadraticEquation(get_a() / q, get_b() / q, get_c() / q);
		}
		else
			cout << "Impossible to divide\n";
	}

	void print(){
		cout << _a << "x^2";
		if (_b >= 0)
			cout << "+";
			cout << _b << "x";
			if (_c >= 0)
				cout << "+";
			cout << _c << "=0" << "\n";
	}

	int flag;

	void get_roots() {
		if (!_a && !_b && !_c) {
			flag = 3;
		}
		if (!_a && !_b && _c!=0) {		
			flag = 0;
		}
		if (!_a && _b != 0 && !_c) {
			_x1 = 0;
			flag = 1;
			
		}
		if (!_a && _b != 0 && _c != 0) {
			_x1 = (-1)*_c / _b;	
			flag = 1;
		}
		if (_a != 0 && !_b && !_c) {
			_x1 = 0;
			flag = 1;
		}
		if (_a != 0 && _b != 0 && !_c) {
			double D = _b * _b - 4 * _a * _c;
			_x1 = ((-1)*_b + sqrt(D)) / (2 * _a);
			_x2 = ((-1)*_b - sqrt(D)) / (2 * _a);
			flag = 2;

		}
		if (_a != 0 && !_b && _c != 0) {
			double D = _b * _b - 4 * _a * _c;
			if (D < 0) { 
				flag = 0;
			}
			if (D > 0) {
				_x1 = sqrt(D) / (2 * _a);
				_x2 = sqrt(D) / ((-2) * _a);
				flag = 2;
			}
		}
		if (_a != 0 && _b != 0 && _c != 0) {
			double D = _b * _b - 4 * _a * _c;
			if (D < 0) {
				flag = 0;
			}
			if (D == 0) {
				_x1 = (-1) * _b / (2 * _a);
				flag = 1;

			}
			if (D > 0) {
				_x1 = ((-1)*_b + sqrt(D)) / (2 * _a);
				_x2 = ((-1)*_b - sqrt(D)) / (2 * _a);
				flag = 2;
			}
		}
	}
	friend ostream& operator << (ostream & stream, const QuadraticEquation& q)
	{
		if (q.flag == 0) {
			stream << "No roots\n";
		}
		if (q.flag == 1) {
			stream << "One root: " << q._x1 << "\n";
		}
		if (q.flag == 2) {
			stream << "Two roots: " << "x1=" << q._x1 << ", " << "x2=" << q._x2 << "\n";
		}
		if (q.flag == 3) {
			stream << "Infinitely many roots\n";
		}
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

	QuadraticEquation q1{};
	QuadraticEquation q2{ 2,10,12 };
	cout << "q2: ";
	q2.print();
	q2.get_roots();
	cout << q2;
	cout << "=====================================================\n";

	QuadraticEquation p1{ 1,-5,6 };
	cout << "p1: ";
	p1.print();
	QuadraticEquation p2{ 0,0,0 };
	cout << "p2: ";
	p2.print();
	QuadraticEquation p3{};
	p3 = p1 + p2;
	cout << "p3 = p1 + p2: ";
	p3.print();
	p3.get_roots();
	cout << p3;
	cout << "=====================================================\n";

	QuadraticEquation t1{ 1,-5,6 };
	cout << "t1: ";
	t1.print();
	QuadraticEquation t2{ 1,-4,0 };
	cout << "t2: ";
	t2.print();
	QuadraticEquation t3{};
	t3 = t1 - t2;
	cout << "t3 = t1 - t2: ";
	t3.print();
	t3.get_roots();
	cout << t3;
	cout << "=====================================================\n";

	QuadraticEquation h1{ 0.5,-2.5,3 };
	cout << "h1=";
	h1.print();
	QuadraticEquation h2{};
	double tmp1;
	cout << "Введите переменную на которую умножим квадратное уравнение ax^2+bx+c=0: ";
	cin >> tmp1;
	h2 = h1 * tmp1;
	cout << "h2 = h1 * tmp1: ";
	h2.print();
	h2.get_roots();
	cout << h2;
	cout << "=====================================================\n";

	QuadraticEquation f1{ 2,-10,12 };
	cout << "f1: ";
	f1.print();
	QuadraticEquation f2{};
	double tmp2;
	cout << "Введите переменную на которую разделим квадратное уравнение ax^2+bx+c=0: ";
	cin >> tmp2;
	f2 = f1 / tmp2;
	cout << "f2 = f1 / tmp2 (if tmp2==0 then f2=f1): ";
	f2.print();
	f2.get_roots();
	cout << h2;
	cout << "=====================================================\n";
	
	int n = 3;
	QuadraticEquation* array = new (nothrow) QuadraticEquation[3]; 
	if (!array) {
		cout << "No memory!";
		system("pause");
		exit(1);
	}
	array[0] = t1, array[1] = t2, array[2] = p1;

	f2 = array[0] - t2;
	cout << "f2 = array[0] - t2: ";
	f2.print();
	f2.get_roots();
	cout << f2;
	cout << "=====================================================\n";

	f2 = *(array + 1) + p1;
	cout << "f2 = *(array + 1) + p1: ";
	f2.print();
	f2.get_roots();
	cout << f2;
	cout << "=====================================================\n";

	f2 = *(array+2) * tmp1;
	cout << "f2 = *(array+2) * tmp1: ";
	f2.print();
	f2.get_roots();
	cout << f2;
	cout << "=====================================================\n";

	f2 = *(array+2) / tmp2;
	cout << "f2 = *(array+2) / tmp2: ";
	f2.print();
	f2.get_roots();
	cout <<  f2 << "\n";
	delete[]array;
	array = nullptr;

	system("pause");
	return 0;
}