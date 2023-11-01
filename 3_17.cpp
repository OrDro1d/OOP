#include <iostream>
using namespace std;

class Matrix // Мой вариант реализации класса вещественных массивов.
{
private:
    unsigned rows, cols;
    double **matrix = nullptr;

public:
    Matrix(){};
    Matrix(unsigned customRows, unsigned customCols);
    Matrix(const Matrix &obj);

    void create(unsigned customRows, unsigned customCols);
    void fill();
    void createAndFill(unsigned customRows, unsigned customCols);
    const void print();

    void operator=(const Matrix &customMatrix);

    const Matrix operator+(const Matrix &customMatrix);
    const Matrix operator-(const Matrix &customMatrix);
    const Matrix operator*(const Matrix &customMatrix);
    const Matrix operator*(const double &number);
    const Matrix operator/(Matrix &customMatrix);
    const Matrix operator/(const double &number);

    void operator+=(const Matrix &customMatrix);
    void operator-=(const Matrix &customMatrix);
    void operator*=(const Matrix &customMatrix);
    void operator*=(const double &number);
    void operator/=(const Matrix &customMatrix);
    void operator/=(const double &number);

    const bool operator==(const Matrix &usersMatrix);
    const bool operator!=(const Matrix &usersMatrix);

    const double determinant();
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

    cout << "Детерминант первой матрицы:" << endl;
    cout << matrix.determinant() << endl;

    cout << "Транспонированная первая матрица:" << endl;
    resultMatrix = matrix.transposition();
    resultMatrix.print();

    cout << "Инвертированная первая матрица:" << endl;
    resultMatrix = matrix.inverse();
    resultMatrix.print();

    cout << "Произведение матриц:" << endl;
    resultMatrix = matrix * anotherMatrix;
    resultMatrix.print();

    cout << "Частное матриц:" << endl;
    resultMatrix = matrix / anotherMatrix;
    resultMatrix.print();

    return 0;
}

Matrix::Matrix(unsigned customRows, unsigned customCols)
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

void Matrix::create(unsigned customRows, unsigned customCols)
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

void Matrix::createAndFill(unsigned customRows, unsigned customCols)
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

const void Matrix::print()
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
    try
    {
        if (customMatrix.rows != rows || customMatrix.cols != cols)
        {
            throw " - ОШИБКА!: Для нахождения суммы двух матриц их размеры должны совпадать! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }

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

const Matrix Matrix::operator-(const Matrix &customMatrix)
{
    try
    {
        if (customMatrix.rows != rows || customMatrix.cols != cols)
        {
            throw " - ОШИБКА!: Для нахождения разности двух матриц их размеры должны совпадать! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }

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

const Matrix Matrix::operator*(const Matrix &customMatrix)
{
    try
    {
        if (cols != customMatrix.rows)
        {
            throw " - ОШИБКА!: Для нахождения произведения двух матриц количество колонок первой матрицы и количество строк второй матрицы должны совпадать! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }

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

const Matrix Matrix::operator/(Matrix &customMatrix)
{
    Matrix temp(rows, cols), inversedCustomMatrix = customMatrix.inverse();

    temp = *this * inversedCustomMatrix;

    return temp;
}

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
    try
    {
        if (customMatrix.rows != rows || customMatrix.cols != cols)
        {
            throw " - ОШИБКА!: Для нахождения разности двух матриц их размеры должны совпадать! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }

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
    try
    {
        if (customMatrix.rows != rows || customMatrix.cols != cols)
        {
            throw " - ОШИБКА!: Для нахождения разности двух матриц их размеры должны совпадать! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }

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
    try
    {
        if (cols != customMatrix.rows)
        {
            throw " - ОШИБКА!: Для нахождения произведения двух матриц количество колонок первой матрицы и количество строк второй матрицы должны совпадать! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }

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

void Matrix::operator/=(const Matrix &customMatrix)
{

    try
    {
        if (cols != customMatrix.rows)
        {
            throw " - ОШИБКА!: Для нахождения частного двух матриц количество колонок первой матрицы и количество строк второй матрицы должны совпадать! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }
}

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
    if (rows != customMatrix.rows || cols != customMatrix.cols)
    {
        return false;
    }

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

const double Matrix::determinant()
{
    try
    {
        if (rows != cols)
        {
            throw " - ОШИБКА! Для нахождения детерминанта матрица должна быть квадратной! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }

    if (rows == 1)
        return matrix[0][0];

    if (rows == 2)
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];

    Matrix matrixMinor(rows - 1, cols - 1);

    double d = 0; // Думаю очевидно, что d - это детерминант матрицы, да?
    // Просто не придумал как иначе сделать имена переменной детерминанта матрицы и метода разными. Простите.
    for (int i = 0; i < cols; i++)
    {
        for (int j = 1; j < rows; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                if (k != i)
                {
                    matrixMinor.matrix[j - 1][(k < i) ? k : k - 1] = matrix[j][k];
                }
            }
        }

        d += (i % 2 == 0) ? matrix[0][i] * matrixMinor.determinant() : -matrix[0][i] * matrixMinor.determinant();
    }

    return d;
}

const Matrix Matrix::inverse()
{
    try
    {
        if (rows != cols)
        {
            throw " - ОШИБКА! Для нахождения обратной матрицы данная матрица должна быть квадратной! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }

    double d = determinant(); // Думаю очевидно, что d - это детерминант матрицы, да?
    // Просто не придумал как иначе сделать имена переменной детерминанта матрицы и метода разными. Простите.

    try
    {
        if (d == 0)
        {
            throw " - ОШИБКА! Детерминант матрицы равен нулю: обратной матрицы не существует! - ";
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
        exit(1);
    }

    Matrix temp(cols, rows), matrixMinor(rows - 1, cols - 1);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k < rows; k++)
            {
                for (int l = 0; l < cols; l++)
                {
                    if (k != i && l != j)
                    {
                        matrixMinor.matrix[(k < i) ? k : k - 1][(l < j) ? l : l - 1] = matrix[k][l];
                    }
                }
            }

            temp.matrix[i][j] = matrixMinor.determinant();
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ((i + j) % 2 != 0)
            {
                temp.matrix[i][j] = -temp.matrix[i][j];
            }
        }
    }

    temp = temp.transposition();
    temp = temp * (1 / d);

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
            delete[] matrix[i];
        }

        delete[] matrix;
    }
}