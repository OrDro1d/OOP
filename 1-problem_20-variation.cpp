#include <iostream>
#include <cmath>

using namespace std;

bool signOrderChecker(int *mas, int &size);
int primeNumFinder(int *mas, int &size);
void deletePrimeNums(int index, int *mas, int &size);

int main()
{
    int size;
    cin >> size;

    int *mas = new int[size];

    for (int i = 0; i < size; i++)
        cin >> mas[i];

    if (signOrderChecker(mas, size))
    {
        cout << "Массив является знакочередующимся." << endl;

        delete mas;
        return 0;
    }
    else
    {
        cout << "Массив НЕ является знакочередующимся." << endl;
        cout << "Удаляем простые числа из массива..." << endl;

        int finders_result = primeNumFinder(mas, size);

        while (finders_result != -1)
        {
            deletePrimeNums(finders_result, mas, size);
            finders_result = primeNumFinder(mas, size);
        }

        cout << "Готово: все простые числа были удалены из массива." << endl;

        for (int i = 0; i < size; i++)
            cout << mas[i] << ' ';

        cout << endl;

        if (signOrderChecker(mas, size))
            cout << "Массив стал знакочередующимся." << endl;
        else
            cout << "Массив НЕ стал знакочередующимся." << endl;

        delete mas;
        return 0;
    }
}

bool signOrderChecker(int *mas, int &size)
{
    for (int i = 0; i < size - 1; i++)
        if ((mas[i] > 0 && mas[i + 1] > 0) || (mas[i] < 0 && mas[i + 1] < 0))
            return false;

    return true;
}

int primeNumFinder(int *mas, int &size)
{
    for (int i = 0; i < size; i++)
    {
        bool flag = true;
        for (int j = 2; j < sqrt(abs(mas[i])) + 1; j++)
        {
            if (mas[i] % j == 0 && abs(mas[i]) != 2)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            return i;
    }

    return -1;
}

void deletePrimeNums(int index, int *mas, int &size)
{
    for (int i = index; i < size; i++)
        mas[i] = mas[i + 1];
    --size;
}