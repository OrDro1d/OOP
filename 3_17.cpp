#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    double **matrix = nullptr;

public:
    Matrix(){};
    Matrix(int customRows, int customCols);
    Matrix(const Matrix &obj);

    void create(int customRows, int customCols);
    void fill();
    void createAndFill(int customRows, int customCols);
    void print();

    void operator=(const Matrix &customMatrix);

    const Matrix operator+(const Matrix &customMatrix);
    const Matrix operator-(const Matrix &customMatrix);
    const Matrix operator*(const Matrix &customMatrix);
    const Matrix operator*(const double &number);
    const Matrix operator/(const Matrix &customMatrix);
    const Matrix operator/(const double &number);

    void operator+=(const Matrix &customMatrix);
    void operator-=(const Matrix &customMatrix);
    void operator*=(const Matrix &customMatrix);
    void operator*=(const double &number);
    void operator/=(const Matrix &customMatrix);
    void operator/=(const double &number);

    const bool operator==(const Matrix &usersMatrix);
    const bool operator!=(const Matrix &usersMatrix);

    const Matrix inverse();
    const Matrix transposition();

    ~Matrix();
};

int main()
{
    Matrix matrix;

    cout << "Задайте размеры первой матрицы:" << endl;
    int rows, cols;
    cin >> rows >> cols;

    cout << "Заполните первую матрицу:" << endl;
    matrix.create(rows, cols);
    matrix.fill();
    cout << "Ваша первая матрица:" << endl;
    matrix.print();

    Matrix anotherMatrix, resultMatrix;

    cout << "Задайте размеры второй матрицы:" << endl;
    int anotherRows, anotherCols;
    cin >> anotherRows >> anotherCols;

    cout << "Заполните вторую матрицу:" << endl;
    anotherMatrix.createAndFill(anotherRows, anotherCols);
    cout << "Ваша вторая матрица:" << endl;
    anotherMatrix.print();

    cout << "Произведение матриц:" << endl;
    resultMatrix = matrix * anotherMatrix;
    resultMatrix.print();

    // resultMatrix = matrix / anotherMatrix;
    // cout << "Частное массивов:" << endl;
    // resultMatrix.print();

    cout << "Транспонированная матрица:" << endl;
    resultMatrix = matrix.transposition();
    resultMatrix.print();

    return 0;
}

Matrix::Matrix(int customRows, int customCols)
{
    rows = customRows;
    cols = customCols;

    matrix = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &obj)
{
    rows = obj.rows;
    cols = obj.cols;

    matrix = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = obj.matrix[i][j];
        }
    }
}

void Matrix::create(int customRows, int customCols)
{
    rows = customRows;
    cols = customCols;

    matrix = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
    }
}

void Matrix::fill()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void Matrix::createAndFill(int customRows, int customCols)
{
    rows = customRows;
    cols = customCols;

    matrix = new double *[rows];

    for (int i = 0; i < rows; i++)

    {
        matrix[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void Matrix::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

void Matrix::operator=(const Matrix &customMatrix)
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete matrix[i];
        }

        delete matrix;
    }

    rows = customMatrix.rows;
    cols = customMatrix.cols;

    matrix = new double *[rows];

    for (int i = 0; i < rows; i++)

    {
        matrix[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = customMatrix.matrix[i][j];
        }
    }
}

const Matrix Matrix::operator+(const Matrix &customMatrix)
{
    if (customMatrix.rows == rows && customMatrix.cols == cols)
    {
        Matrix temp(customMatrix.rows, customMatrix.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.matrix[i][j] = customMatrix.matrix[i][j] + matrix[i][j];
            }
        }

        return temp;
    }
    else
    {
        cout << "[ -- ERROR: Для нахождения суммы размеры матриц должны совпадать! -- ]" << endl;
    }
}

const Matrix Matrix::operator-(const Matrix &customMatrix)
{
    if (customMatrix.rows == rows && customMatrix.cols == cols)
    {
        Matrix temp(customMatrix.rows, customMatrix.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.matrix[i][j] = customMatrix.matrix[i][j] - matrix[i][j];
            }
        }

        return temp;
    }
    else
    {
        cout << "[ -- ERROR: Для нахождения разности размеры матриц должны совпадать! -- ]" << endl;
    }
}

const Matrix Matrix::operator*(const Matrix &customMatrix)
{

    if (customMatrix.rows == cols)
    {
        Matrix temp(rows, customMatrix.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < customMatrix.cols; j++)
            {
                double counter = 0;
                for (int k = 0; k < cols; k++)
                {
                    counter += matrix[i][k] * customMatrix.matrix[k][j];
                }
                temp.matrix[i][j] = counter;
            }
        }

        return temp;
    }
    else
    {
        cout << "[ -- ERROR: Для нахождения произведения двух матриц количество колонок первой матрицы и количество строк второй матрицы должны совпадать! -- ]" << endl;
    }
}

const Matrix Matrix::operator*(const double &number)
{
    Matrix temp(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.matrix[i][j] = matrix[i][j] * number;
        }
    }

    return temp;
}

// const Matrix Matrix::operator/(const Matrix &customMatrix)
// {
// }

const Matrix Matrix::operator/(const double &number)
{
    Matrix temp(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.matrix[i][j] = matrix[i][j] / number;
        }
    }

    return temp;
}

void Matrix::operator+=(const Matrix &customMatrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] += customMatrix.matrix[i][j];
        }
    }
}

void Matrix::operator-=(const Matrix &customMatrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] -= customMatrix.matrix[i][j];
        }
    }
}

void Matrix::operator*=(const Matrix &customMatrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < customMatrix.cols; j++)
        {
            double counter = 0;
            for (int k = 0; k < cols; k++)
            {
                counter += matrix[i][k] * customMatrix.matrix[k][j];
            }
            matrix[i][j] = counter;
        }
    }
}

void Matrix::operator*=(const double &number)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] *= number;
        }
    }
}

// void Matrix::operator/=(const Matrix &customMatrix)
// {
// }

void Matrix::operator/=(const double &number)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] /= number;
        }
    }
}

const bool Matrix::operator==(const Matrix &customMatrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != customMatrix.matrix[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

const bool Matrix::operator!=(const Matrix &customMatrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != customMatrix.matrix[i][j])
            {
                return true;
            }
        }
    }

    return false;
}

const Matrix Matrix::inverse()
{
    Matrix temp(rows, cols);

    return temp;
}

const Matrix Matrix::transposition()
{
    Matrix temp(cols, rows);

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            temp.matrix[i][j] = matrix[j][i];
        }
    }

    return temp;
}

Matrix::~Matrix()
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete matrix[i];
        }

        delete matrix;
    }
}