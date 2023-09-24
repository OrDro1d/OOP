#include <iostream>
#include <cmath>

using namespace std;

class Triangle
{
private:
    double a, b, c;

public:
    Triangle();
    Triangle(double a, double b, double c);
    Triangle(const Triangle &obj);
    void setTriangle(double custom_a, double custom_b, double custom_c);
    bool existence();
    void perimeter();
    void area();
    void corners();
    void sides();
    ~Triangle();
};

Triangle::Triangle()
{
    a = b = c = 1.0;
}

Triangle::Triangle(double a, double b, double c)
{
    setTriangle(a, b, c);
}

Triangle::Triangle(const Triangle &obj)
{
}

void Triangle::setTriangle(double custom_a, double custom_b, double custom_c)
{
    a = custom_a;
    b = custom_b;
    c = custom_c;
}

bool Triangle::existence()
{
    if (a < b + c && b < a + c && c < a + b)
        return true;
    else
        return false;
}

void Triangle::perimeter()
{
    cout << "   Периметр: " << a + b + c << endl;
}

void Triangle::area()
{
    double p = (a + b + c) / 2;
    cout << "   Площадь: " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
}

void Triangle::corners()
{
    const double PI = 3.141592653589793;
    double alpha, beta, gamma;
    alpha = acos((c * c + b * b - a * a) / (2 * c * b)) * 180 / PI;
    beta = acos((c * c + a * a - b * b) / (2 * c * a)) * 180 / PI;
    gamma = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;
    cout << "   Углы: " << alpha << ", " << beta << ", " << gamma << endl;
}

void Triangle::sides()
{
    cout << "   Стороны: " << a << ", " << b << ", " << c << endl;
}

Triangle::~Triangle()
{
    cout << "Память освобождена: объект был удалён." << endl;
}

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

        return 0;
    }

    else
    {
        cout << "Данный треугольник НЕ существует." << endl;

        return 0;
    }
}