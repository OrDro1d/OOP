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
    void setTriangle(double custom_a, double custom_b, double custom_c);
    bool existence();
    void perimeter();
    void area();
    void corners();
    void printSides();
    // ~Triangle();
};

Triangle::Triangle()
{
    a = b = c = 1.0;
}

Triangle::Triangle(double a, double b, double c)
{
    setTriangle(a, b, c);
}

void Triangle::setTriangle(double custom_a, double custom_b, double custom_c)
{
    a = custom_a;
    b = custom_b;
    c = custom_c;
}

bool Triangle::existence()
{
    if (a > b + c && b > a + c && c > a + b)
        return true;
    else
        return false;
}

void Triangle::perimeter()
{
    cout << a + b + c << endl;
}

void Triangle::area()
{
    double p = (a + b + c) / 2;
    cout << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
}

void Triangle::corners()
{
    const double PI = 3.141592653589793;
    double alpha, beta, gamma;
    alpha = acos((c * c + b * b - a * a) / (2 * c * b)) * 180 / PI;
    beta = acos((c * c + a * a - b * b) / (2 * c * a)) * 180 / PI;
    gamma = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;
    cout << alpha << " " << beta << " " << gamma << endl;
}

void Triangle::printSides()
{
    cout << a << " " << b << " " << c << endl;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    Triangle t = Triangle(a, b, c);
    t.printSides();
    t.perimeter();
    t.area();
    t.corners();

    return 0;
}