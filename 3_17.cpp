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

    const double calculateDeterminant();
    Matrix inverse();
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
    // cout << "Частное матриц:" << endl;
    // resultMatrix.print();

    cout << "Транспонированная первая матрица:" << endl;
    resultMatrix = matrix.transposition();
    resultMatrix.print();

    cout << "Детерминант первой матрицы:" << endl;
    cout << matrix.calculateDeterminant() << endl;

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
        cout << "[> ERROR: Для нахождения суммы размеры матриц должны совпадать! <" << endl;
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
        cout << "[> ERROR: Для нахождения разности размеры матриц должны совпадать! <]" << endl;
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
        cout << "[> ERROR: Для нахождения произведения двух матриц количество колонок первой матрицы и количество строк второй матрицы должны совпадать! <]" << endl;
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

const Matrix Matrix::operator/(Matrix &customMatrix)
{
    Matrix temp(rows, cols);
    Matrix inversedCustomMatrix = customMatrix.inverse();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.matrix[i][j] = inversedCustomMatrix.matrix[i][j];
        }
    }

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
    if (rows == customMatrix.rows && cols == customMatrix.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] += customMatrix.matrix[i][j];
            }
        }
    }
    else
    {
        cout << "[> ERROR: Для нахождения суммы размеры матриц должны совпадать! <" << endl;
    }
}

void Matrix::operator-=(const Matrix &customMatrix)
{
    if (rows == customMatrix.rows && cols == customMatrix.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] -= customMatrix.matrix[i][j];
            }
        }
    }
    else
    {
        cout << "[> ERROR: Для нахождения разности размеры размеры матриц должны совпадать! <" << endl;
    }
}

void Matrix::operator*=(const Matrix &customMatrix)
{
    if (rows == customMatrix.rows && cols == customMatrix.cols)
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
    else
    {
        cout << "[> ERROR: Для нахождения произведения размеры матриц должны совпадать! <" << endl;
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
    if (rows == customMatrix.rows && cols == customMatrix.cols)
    {
    }
    else
    {
        cout << "[> ERROR: Для нахождения произведения размеры матриц должны совпадать! <" << endl;
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

const double Matrix::calculateDeterminant()
{
    if (rows == cols)
    {
        if (rows == 2)
        {
            return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        }

        Matrix matrixMinor(rows - 1, cols - 1);

        double calculateDeterminant = 0;

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

            calculateDeterminant += (i % 2 == 0) ? matrix[0][i] * matrixMinor.calculateDeterminant() : -matrix[0][i] * matrixMinor.calculateDeterminant();
        }

        return calculateDeterminant;
    }
    else
    {
        cout << "[> ERROR: Для нахождения детерминанта данная матрица должна быть квадратной! <" << endl;
    }
}

Matrix Matrix::inverse()
{
    if (rows == cols)
    {
        double determinant = calculateDeterminant();

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

                temp.matrix[i][j] = matrixMinor.calculateDeterminant();
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
        temp = temp * (1 / determinant);

        return temp;
    }
    else
    {
        cout << "[> ERROR: Для нахождения обратной матрицы данная матрица должна быть квадратной! <" << endl;
    }
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