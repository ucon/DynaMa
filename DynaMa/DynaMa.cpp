// DynaMa.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int* makeString(int column_count, int diff)
{
    int val = 17;
    int* myStr = new int[column_count];
    for (int i = 0; i < column_count; i++) 
    {
        myStr[i] = val * diff;
        val++;
    }
    return myStr;
}

int** append2matr(int**& matr, int* myStr, int row_count)
{
    int** new_matr;
    new_matr = new int* [sizeof(int*) * row_count];
    for (int i = 0; i < row_count; i++)
    {
        new_matr[i] = matr[i];
    }
    new_matr[row_count] = myStr;
    return new_matr;
}

void print_matr(int** matr, int row_count, int column_count)
{
    cout << "Matrix" << endl;
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++)
            cout << "\t" << matr[i][j] << " ";
        cout << endl;
    }

}


int main()
{
    int** matr; // указатель на int*

    int row_count;
    int column_count;
 
    cout << "String number ? ";
    cin >> row_count;
    cout << "Column number ? ";
    cin >> column_count;

    matr = new int* [row_count]; 

    for (int i = 0; i < row_count; i++)
    {
        matr[i] = new int[column_count];
        matr[i] = makeString(column_count, i+1);
        matr = append2matr(matr, matr[i], i);
    }



    // выводим
    print_matr(matr, row_count, column_count);
//    add_stroki(massiv_massivov, row_count, column_count);
//    print(massiv_massivov, row_count, column_count);


    // освобождаем память
    // Сначала удаляем 5 массивов, потом удаляем массив, в котором лежали их адреса.
//    for (int i = 0; i < row_count; i++)
//        delete[] massiv_massivov[i];
//    delete[] massiv_massivov;
//}
}


