#include <iostream>
using namespace std;

class DoubleArray
{
private:
    unsigned int rows, cols;
    double **array;

public:
    void create(unsigned int inputRows, unsigned int inputCols);
    void fill();
    void createAndFill(unsigned int inputRows, unsigned int inputCols);
    void print();
    void plus(double num);
    void minus(double num);
    void multiply(double num);
    int multiply(double *arr, unsigned int rows, unsigned int cols);
    void divide(double num);
    int divide(double *arr, unsigned int rows, unsigned int cols);
    void equality(DoubleArray users_arr);
};

void DoubleArray::create(unsigned int inputRows, unsigned int inputCols)
{
    rows = inputRows;
    cols = inputCols;

    array = new double *[rows];
    for (unsigned int i = 0; i < rows; i++)
    {
        array[i] = new double[cols];
    }
}

void DoubleArray::fill()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> array[i][j];
        }
    }
}

void DoubleArray::createAndFill(unsigned int inputRows, unsigned int inputCols)
{
    rows = inputRows;
    cols = inputCols;

    array = new double *[rows];
    for (unsigned int i = 0; i < rows; i++)
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

void DoubleArray::plus(double num)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] += num;
        }
    }
}

void DoubleArray::minus(double num)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] -= num;
        }
    }
}

void DoubleArray::multiply(double num)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] *= num;
        }
    }
}

int DoubleArray::multiply(double *arr, unsigned int inputRows, unsigned int inputCols)
{
    if (rows == inputCols)
    {
        DoubleArray count_arr;
        count_arr.create(rows, inputCols);
    }
}

void DoubleArray::divide(double num)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] /= num;
        }
    }
}

void DoubleArray::print()
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