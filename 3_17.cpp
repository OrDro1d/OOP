#include <iostream>
using namespace std;

class Array
{
private:
    int rows, cols;
    double **array;

public:
    Array(){};
    Array(int customRows, int customCols);
    Array(const Array &obj);

    void create(int customRows, int customCols);
    void fill();
    void createAndFill(int customRows, int customCols);
    void print();

    const Array operator+(const Array &customArr);
    const Array operator-(const Array &customArr);
    const Array operator*(const Array &customArr);
    const Array operator*(const double &number);
    const Array operator/(const Array &customArr);
    const Array operator/(const double &number);

    void operator+=(const Array &customArr);
    void operator-=(const Array &customArr);
    void operator*=(const Array &customArr);
    void operator*=(const double &number);
    void operator/=(const Array &customArr);
    void operator/=(const double &number);

    const bool operator==(const Array &usersArr);
    const bool operator!=(const Array &usersArr);

    const Array inverse();
    const Array transposition();

    ~Array();
};

int main()
{
    Array arr;

    int rows, cols;
    cin >> rows >> cols;

    cout << "Заполните первый массив:" << endl;
    arr.create(rows, cols);
    arr.fill();
    arr.print();

    Array anotherArr;

    int anotherRows, anotherCols;
    cin >> anotherRows >> anotherCols;

    cout << "Заполните второй массив:" << endl;
    anotherArr.createAndFill(anotherRows, anotherCols);
    anotherArr.print();

    Array resultArr = arr * anotherArr;
    cout << "Вот результирующий массив:" << endl;
    resultArr.print();

    return 0;
}

Array::Array(int customRows, int customCols)
{
    rows = customRows;
    cols = customCols;

    array = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = 0;
        }
    }
}

void Array::create(int customRows, int customCols)
{
    rows = customRows;
    cols = customCols;

    array = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = 0.0;
        }
    }
}

Array::Array(const Array &obj)
{
    rows = obj.rows;
    cols = obj.cols;

    array = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = obj.array[i][j];
        }
    }
}

void Array::fill()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> array[i][j];
        }
    }
}

void Array::createAndFill(int customRows, int customCols)
{
    rows = customRows;
    cols = customCols;

    array = new double *[rows];

    for (int i = 0; i < rows; i++)
    {
        array[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> array[i][j];
        }
    }
}

void Array::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << array[i][j] << " ";
        }

        cout << endl;
    }
}

const Array Array::operator+(const Array &customArr)
{
    Array temp(customArr.rows, customArr.cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.array[i][j] = customArr.array[i][j] + array[i][j];
        }
    }

    return temp;
}

const Array Array::operator-(const Array &customArr)
{
    Array temp(customArr.rows, customArr.cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.array[i][j] = customArr.array[i][j] - array[i][j];
        }
    }

    return temp;
}

const Array Array::operator*(const Array &customArr)
{
    Array temp(rows, customArr.cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < customArr.cols; j++)
        {
            double counter = 0;
            for (int k = 0; k < cols; k++)
            {
                counter += array[i][k] * customArr.array[k][j];
            }
            temp.array[i][j] = counter;
        }
    }

    return temp;
}

const Array Array::operator*(const double &number)
{
    Array temp(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.array[i][j] = array[i][j] * number;
        }
    }

    return temp;
}

const Array Array::operator/(const Array &customArr)
{
    Array temp(rows, customArr.cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < customArr.cols; j++)
        {
            double counter = 0;
            for (int k = 0; k < cols; k++)
            {
                counter += array[i][k] / customArr.array[k][j];
            }
            temp.array[i][j] = counter;
        }
    }

    return temp;
}

const Array Array::operator/(const double &number)
{
    Array temp(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.array[i][j] = array[i][j] / number;
        }
    }

    return temp;
}

void Array::operator+=(const Array &customArr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] += customArr.array[i][j];
        }
    }
}

void Array::operator-=(const Array &customArr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] -= customArr.array[i][j];
        }
    }
}

void Array::operator*=(const Array &customArr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < customArr.cols; j++)
        {
            double counter = 0;
            for (int k = 0; k < cols; k++)
            {
                counter += array[i][k] * customArr.array[k][j];
            }
            array[i][j] = counter;
        }
    }
}

void Array::operator*=(const double &number)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] *= number;
        }
    }
}

void Array::operator/=(const Array &customArr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < customArr.cols; j++)
        {
            double counter = 0;
            for (int k = 0; k < cols; k++)
            {
                counter += array[i][k] / customArr.array[k][j];
            }
            array[i][j] = counter;
        }
    }
}

void Array::operator/=(const double &number)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] /= number;
        }
    }
}

const bool Array::operator==(const Array &customArr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array[i][j] != customArr.array[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

const bool Array::operator!=(const Array &customArr)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (array[i][j] != customArr.array[i][j])
            {
                return true;
            }
        }
    }

    return false;
}

const Array Array::inverse()
{
}
const Array Array::transposition()
{
}

Array::~Array()
{
    for (int i = 0; i < rows; i++)
    {
        delete array[i];
    }

    delete array;
}