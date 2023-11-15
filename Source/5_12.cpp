/*    Создать класс четырехугольник, члены класса – координаты 4-х точек.
Предусмотреть в классе методы вычисления и вывода сведений о фигуре – длины сторон, диагоналей,
периметр, площадь. Создать производный класс – квадрат, предусмотреть в классе проверку,
является ли фигура квадратом. Написать программу, демонстрирующую работу с классом:
дано N четырехугольников и M квадратов, найти четырехугольники с минимальной и максимальной
площадью и номера одинаковых квадратов. Часть функций определить как
виртуальные.    */

#include <iostream>
#include <cmath>
using namespace std;

class Tetragon
{
protected:
    double ax, ay;
    double bx, by;
    double cx, cy;
    double dx, dy;

public:
    Tetragon(double ax = 0, double ay = 0, double bx = 0, double by = 0,
             double cx = 0, double cy = 0, double dx = 0, double dy = 0);
    ~Tetragon(){};

    double *sides() const;
    virtual void printSides() const;
    double *diagonals() const;
    virtual void printDiagonals() const;
    virtual double perimeter() const;
    virtual void printPerimeter() const;
    virtual double area() const;
    virtual void printArea() const;
};

class Square : public Tetragon
{
public:
    Square(double a = 0);
    Square(double ax, double ay, double bx, double by,
           double cx, double cy, double dx, double dy);
    ~Square(){};

    double sides() const;
    void printSides() const;
    double diagonals() const;
    void printDiagonals() const;
    double perimeter() const;
    void printPerimeter() const;
    double area() const;
    void printArea() const;
};

int main()
{
    cout << "Введите кол-во четырехугольников N и квадратов M:    " << endl;
    unsigned n, m;
    cin >> n >> m;

    double ax, ay, bx, by, cx, cy, dx, dy;
    cout << "Введите координаты вершин ваших четырехугольников:   " << endl;
    Tetragon t[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
        t[i] = Tetragon(ax, ay, bx, by, cx, cy, dx, dy);
    }

    cout << "Введите координаты вершин ваших квадратов:   " << endl;
    Square s[m];
    for (int i = 0; i < m; i++)
    {
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
        s[i] = Square(ax, ay, bx, by, cx, cy, dx, dy);
    }

    double max = t[0].area(), indexMax = 0;
    double min = max, indexMin = 0;
    for (int i = 1; i < n; i++)
    {
        if (t[i].area() > max)
        {
            max = t[i].area();
            indexMax = i;
        }
        if (t[i].area() < min)
        {
            min = t[i].area();
            indexMin = i;
        }
    }

    cout << "Четырехугольник с максимальной площадью:  " << indexMax << endl
         << "Четырехугольник с минимальной площадью:  " << indexMin << endl;

    for (int i = 1; i < m; i++)
    {
        cout << "Одинаковые квадраты с квадратом " << i << ":  ";
        for (int j = 0; j < m; j++)
        {
            if (abs(s[i].sides() - s[j].sides()) < 1e-9)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
// Определения методов класса Tetragon (четырёхугольник).
Tetragon::Tetragon(double ax, double ay, double bx, double by,
                   double cx, double cy, double dx, double dy) : ax(ax), ay(ay), bx(bx), by(by),
                                                                 cx(cx), cy(cy), dx(dx), dy(dy) {}

double *Tetragon::sides() const
{
    double *sides = new double[4];
    sides[0] = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    sides[1] = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
    sides[2] = sqrt((cx - dx) * (cx - dx) + (cy - dy) * (cy - dy));
    sides[3] = sqrt((dx - ax) * (dx - ax) + (dy - ay) * (dy - ay));
    return sides;
}

void Tetragon::printSides() const
{
    cout << sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) << " "
         << sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy)) << " "
         << sqrt((cx - dx) * (cx - dx) + (cy - dy) * (cy - dy)) << " "
         << sqrt((dx - ax) * (dx - ax) + (dy - ay) * (dy - ay)) << endl;
}

double *Tetragon::diagonals() const
{
    double *diagonals = new double[2];
    diagonals[0] = sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));
    diagonals[1] = sqrt((bx - dx) * (bx - dx) + (by - dy) * (by - dy));
    return diagonals;
}

void Tetragon::printDiagonals() const
{
    cout << sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy)) << " "
         << sqrt((bx - dx) * (bx - dx) + (by - dy) * (by - dy)) << endl;
}

double Tetragon::perimeter() const
{
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) +
           sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy)) +
           sqrt((cx - dx) * (cx - dx) + (cy - dy) * (cy - dy)) +
           sqrt((dx - ax) * (dx - ax) + (dy - ay) * (dy - ay));
}

void Tetragon::printPerimeter() const
{
    cout << sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) +
                sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy)) +
                sqrt((cx - dx) * (cx - dx) + (cy - dy) * (cy - dy)) +
                sqrt((dx - ax) * (dx - ax) + (dy - ay) * (dy - ay))
         << endl;
}

double Tetragon::area() const
{
    double ab, bc, cd, da, p;
    ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    bc = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
    cd = sqrt((cx - dx) * (cx - dx) + (cy - dy) * (cy - dy));
    da = sqrt((dx - ax) * (dx - ax) + (dy - ay) * (dy - ay));
    p = (ab + bc + cd + da) / 2;
    return sqrt((p - ab) * (p - bc) * (p - cd) * (p - da));
}

void Tetragon::printArea() const
{
    double ab, bc, cd, da, p;
    ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    bc = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
    cd = sqrt((cx - dx) * (cx - dx) + (cy - dy) * (cy - dy));
    da = sqrt((dx - ax) * (dx - ax) + (dy - ay) * (dy - ay));
    p = (ab + bc + cd + da) / 2;
    cout << sqrt((p - ab) * (p - bc) * (p - cd) * (p - da)) << endl;
}
// Определения методов класса Square (квадрат).
Square::Square(double a) : Tetragon(0, 0, 0, a, a, a, a, 0){};

Square::Square(double ax, double ay, double bx, double by,
               double cx, double cy, double dx, double dy) : Tetragon(ax, ay, bx, by,
                                                                      cx, cy, dx, dy)
{
    double ab, bc, cd, da;
    // Стороны возможного квадрата.
    ab = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    bc = sqrt((bx - cx) * (bx - cx) + (by - cy) * (by - cy));
    cd = sqrt((cx - dx) * (cx - dx) + (cy - dy) * (cy - dy));
    da = sqrt((dx - ax) * (dx - ax) + (dy - ay) * (dy - ay));

    try
    {
        if (abs(ab - bc) > 1e-9 || abs(bc - cd) > 1e-9 ||
            abs(cd - da) > 1e-9 || abs(da - ab) > 1e-9)
        {
            throw " - ОШИБКА!: Стороны квадрата должны быть равными! - ";
        }

        double ac, bd, dab, boc;
        // Диагонали возможного квадрата.
        ac = sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));
        bd = sqrt((bx - dx) * (bx - dx) + (by - dy) * (by - dy));
        // Углы возможного квадрата.
        dab = acos((ab * ab + da * da - bd * bd) / (2 * ab * da));
        boc = acos((ab * ab + bc * bc - ac * ac) / (2 * ab * bc));

        if (abs(dab - boc) > 1e-9)
        {
            throw " - ОШИБКА!: Углы квадрата должны быть прямыми и равными между собой! - ";
        }
    }
    catch (const char errorMessage[])
    {
        cout << errorMessage << endl;
        exit(1);
    }
}

double Square::sides() const
{
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

void Square::printSides() const
{
    cout << sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) << endl;
}

double Square::diagonals() const
{
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

void Square::printDiagonals() const
{
    cout << sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) << endl;
}

double Square::perimeter() const
{
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) * 4;
}

void Square::printPerimeter() const
{
    cout << sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) * 4 << endl;
}

double Square::area() const
{
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) *
           sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

void Square::printArea() const
{
    cout << sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) *
                sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by))
         << endl;
}