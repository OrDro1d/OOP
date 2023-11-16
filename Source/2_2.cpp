#include <iostream>
#include <cmath>

using namespace std;

class Triangle
{
private:
    double a, b, c;

public:
    Triangle(double a = 0, double b = 0, double c = 0);
    Triangle(const Triangle &obj);
    ~Triangle();

    void setTriangle(double customA, double customB, double customC);
    const bool existence();
    const void perimeter();
    const void area();
    const void corners();
    const void sides();
};

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    Triangle t = Triangle(a, b, c);

    if (t.existence())
    {
        cout << "Данный треугольник существует." << endl;
        cout << "Свойства заданного Вами треугольника: " << endl;

        t.sides();
        t.perimeter();
        t.area();
        t.corners();

        Triangle t2 = t;
        cout << "Объект 't2' был создан и скопировал свойства объекта 't'" << endl;
        t2.sides();

        return 0;
    }

    else
    {
        cout << "Данный треугольник НЕ существует." << endl;

        return 0;
    }
}

Triangle::Triangle(double a = 0, double b = 0, double c = 0)
{
    setTriangle(a, b, c);
    cout << " -- Был вызван конструктор -- " << endl;
}

Triangle::Triangle(const Triangle &obj)
{
    a = obj.a;
    b = obj.b;
    c = obj.c;
    cout << " -- Был вызван конструктор копирования -- " << endl;
}

void Triangle::setTriangle(double customA, double customB, double customC)
{
    a = customA;
    b = customB;
    c = customC;
}

const bool Triangle::existence()
{
    if (a <= 0.0 || b <= 0.0 || c <= 0.0)
        return false;

    if (a < b + c && b < a + c && c < a + b)
        return true;
    else
        return false;
}

const void Triangle::perimeter()
{
    cout << "   Периметр: " << a + b + c << endl;
}

const void Triangle::area()
{
    double p = (a + b + c) / 2;
    cout << "   Площадь: " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
}

const void Triangle::corners()
{
    const double PI = 3.141592653589793;
    double alpha, beta, gamma;
    alpha = acos((c * c + b * b - a * a) / (2 * c * b)) * 180 / PI;
    beta = acos((c * c + a * a - b * b) / (2 * c * a)) * 180 / PI;
    gamma = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;
    cout << "   Углы: " << alpha << ", " << beta << ", " << gamma << endl;
}

const void Triangle::sides()
{
    cout << "   Стороны: " << a << ", " << b << ", " << c << endl;
}

Triangle::~Triangle()
{
    cout << " -- Был вызван деструктор -- " << endl;
    cout << "Память освобождена: объект был удалён." << endl;
}