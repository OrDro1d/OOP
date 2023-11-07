/*
    Задача №4 вариант 9:
    1. Класс: Комплексное число в показательной форме a=r·e^(µi)
    2. Элементы класса: Модуль r и аргумент µ числа
    3. Методы: Конструктор, деструктор, вывод комплексного числа в алгебраической, тригонометрической и экспоненциальной формах
    4. Операции: Сложение (+), вычитание (-), умножение (*), деление (/) комплексных чисел
*/

#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
private:
    double r, f;

public:
    ComplexNumber(double r = 0, double f = 0);
    ~ComplexNumber(){};

    void printExponential() const;
    void printTrigonometric() const;
    void printAlgebraic() const;

    ComplexNumber operator+(ComplexNumber const &number) const;
    ComplexNumber operator-(ComplexNumber const &number) const;
    ComplexNumber operator*(ComplexNumber const &number) const;
    ComplexNumber operator/(ComplexNumber const &number) const;
};

int main()
{
    double r, f;
    cout << "Введите I комплексное число:" << endl;
    cin >> r >> f;
    ComplexNumber num(r, f);

    cout << "Комплексное число в Тригонометрической форме:                 ";
    num.printTrigonometric();
    cout << "Комплексное число в Показательной (Экспоненциальной) форме:   ";
    num.printExponential();
    cout << "Комплексное число в Алгебраической форме:                     ";
    num.printAlgebraic();

    cout << "Введите II комплексное число:" << endl;
    cin >> r >> f;
    ComplexNumber otherNum(r, f);

    cout << "Сумма:         ";
    (num + otherNum).printExponential();
    cout << "Разность:      ";
    (num - otherNum).printExponential();
    cout << "Произведение:  ";
    (num * otherNum).printExponential();
    cout << "Частное:       ";
    (num / otherNum).printExponential();

    return 0;
}

ComplexNumber::ComplexNumber(double r, double f)
{
    this->r = r;
    this->f = f;
};

void ComplexNumber::printExponential() const
{
    if (f >= 0)
    {
        cout << r << "e^(i" << f << ")" << endl;
    }
    else
    {
        cout << r << "e^(-i" << fabs(f) << ")" << endl;
    }
}

void ComplexNumber::printTrigonometric() const
{
    if (f >= 0)
    {
        cout << r << "(cos" << f << " + "
             << "isin" << f << ")" << endl;
    }
    else
    {
        cout << r << "(cos(" << f << ") + "
             << "isin(" << f << "))" << endl;
    }
}

void ComplexNumber::printAlgebraic() const
{
    double a, b;
    b = r * cos(f);
    a = r * sin(f);

    if (b >= 0)
    {
        cout << a << " + "
             << "i" << b << endl;
    }
    else
    {
        cout << a << " - "
             << "i" << fabs(b) << endl;
    }
}

ComplexNumber ComplexNumber::operator+(ComplexNumber const &number) const
{
    double a, b;
    b = r * cos(f);
    a = r * sin(f);

    double otherA, otherB;
    otherB = number.r * cos(number.f);
    otherA = number.r * sin(number.f);

    a += otherA;
    b += otherB;

    return ComplexNumber(sqrt(a * a + b * b), tan(b / a));
}

ComplexNumber ComplexNumber::operator-(ComplexNumber const &number) const
{
    double a, b;
    b = r * cos(f);
    a = r * sin(f);

    double otherA, otherB;
    otherB = number.r * cos(number.f);
    otherA = number.r * sin(number.f);

    a -= otherA;
    b -= otherB;

    return ComplexNumber(sqrt(a * a + b * b), tan(b / a));
}

ComplexNumber ComplexNumber::operator*(ComplexNumber const &number) const
{
    return ComplexNumber(r * number.r, f + number.f);
}

ComplexNumber ComplexNumber::operator/(ComplexNumber const &number) const
{
    return ComplexNumber(r / number.r, f - number.f);
}