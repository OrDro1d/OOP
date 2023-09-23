#include <iostream>
#include <cmath>

using namespace std;

bool signChecker(int *mas, int &size);
int simpleNumFinder(int *mas, int &size);
void deleteSimpleNums(int index, int *mas, int &size);

int main()
{
    int size;
    cin >> size;

    int *mas = new int[size];

    for (int i = 0; i < size; i++)
        cin >> mas[i];

    if (signChecker(mas, size))
    {
        cout << "Массив является знакочередующимся." << endl;

        delete mas;
        return 0;
    }
    else
    {
        cout << "Массив НЕ является знакочередующимся." << endl;
        cout << "Удаляем простые числа из массива..." << endl;

        int finders_result = simpleNumFinder(mas, size);

        while (finders_result != -1)
        {
            deleteSimpleNums(finders_result, mas, size);
            finders_result = simpleNumFinder(mas, size);
        }

        cout << "Готово: все простые числа были удалены из массива." << endl;

        for (int i = 0; i < size; i++)
            cout << mas[i] << ' ';

        cout << endl;

        if (signChecker(mas, size))
            cout << "Массив стал знакочередующимся." << endl;
        else
            cout << "Массив НЕ стал знакочередующимся." << endl;

        delete mas;
        return 0;
    }
}

bool signChecker(int *mas, int &size)
{
    for (int i = 0; i < size - 1; i++)
        if ((mas[i] > 0 && mas[i + 1] > 0) || (mas[i] < 0 && mas[i + 1] < 0))
            return false;

    return true;
}

int simpleNumFinder(int *mas, int &size)
{
    for (int i = 0; i < size; i++)
        if (mas[i] % 2 == 0)
            return i;
    return -1;
}

void deleteSimpleNums(int index, int *mas, int &size)
{
    for (int i = index; i < size; i++)
        mas[i] = mas[i + 1];
    --size;
}