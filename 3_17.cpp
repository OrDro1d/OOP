#include <iostream>
using namespace std;

class DoubleArray
{
private:
    unsigned int n, m;
    double **array;

public:
    void create(unsigned int users_n, unsigned int users_m);
    void fill();
    void createAndFill(unsigned int users_n, unsigned int users_m);
    void print();
    void plus(double num);
    void minus(double num);
    void multiply(double num);
    void divide(double num);
    void equality(DoubleArray users_arr);
};

void DoubleArray::create(unsigned int users_n, unsigned int users_m)
{
    n = users_n;
    m = users_m;

    array = new double *[n];
    for (unsigned int i = 0; i < n; i++)
    {
        array[i] = new double[m];
    }
}

void DoubleArray::fill()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> array[i][j];
        }
    }
}

void DoubleArray::createAndFill(unsigned int users_n, unsigned int users_m)
{
    n = users_n;
    m = users_m;

    array = new double *[n];
    for (unsigned int i = 0; i < n; i++)
    {
        array[i] = new double[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> array[i][j];
        }
    }
}

void DoubleArray::plus(double num)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            array[i][j] += num;
        }
    }
}

void DoubleArray::minus(double num)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            array[i][j] -= num;
        }
    }
}

void DoubleArray::multiply(double num)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            array[i][j] *= num;
        }
    }
}

void DoubleArray::divide(double num)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            array[i][j] /= num;
        }
    }
}

void DoubleArray::print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << array[i][j] << " ";
        }

        cout << endl;
    }
}

void equality(DoubleArray users_arr)
{
}

int main()
{
    unsigned int rows, cols;
    cin >> rows >> cols;

    DoubleArray arr;
    arr.create(rows, cols);
    arr.fill();
    arr.print();
    DoubleArray another_arr;

    return 0;
}