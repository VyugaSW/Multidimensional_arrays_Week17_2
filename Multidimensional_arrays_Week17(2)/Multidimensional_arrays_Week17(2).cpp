
#include <Windows.h>
#include <iostream>

using namespace std;

#define Mode 1

//Задание 1. Транспонирование матрицы — это операция,
//после которой столбцы прежней матрицы становятся строками, а строки столбцами.Напишите функцию
//транспонирования матрицы.

void Task1(int* arr[], int M, int N) {
    int** newArr = new int*[N];
    for (int i = 0; i < N; i++) {
        newArr[i] = new int[M];
        for (int j = 0; j < M; j++) {
            newArr[i][j]= arr[j][i];
        }
    }

    //Для наглядности и проверки
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    }

}


//Задание 2. Создайте динамический массив, хранящий
//в первой строке имя, а во второй — телефон.Организуйте поиск по имени и по номеру телефона и возможность
//ввода и изменения данных.
//
// Как понял я, правильный вид массива:
// {
// {"Pierr"},
// {+78485485},
// {"John"},
// {+96548486}
//}

//Добавление нового имени и телефона
void Task2_cin(char** arr,int &s1) {
    s1++;
    arr[s1 - 1] = new char[256];
    system("cls");
    char* buff = new char[256];
    char* number = new char[255];
    cout << "Введите имя: ";
    cin.ignore(256,'\n'); //Очистка потока ввода (т.к. cin сжирает весь - тварина)
    gets_s(buff, 256); //Сделал gets_s, так как имя может быть из двух слов
    arr[s1 - 1] = buff;
    s1++;
    arr[s1-1] = new char[256];
    cout << "Введите номер телефона: ";
    gets_s(number, 255);
    arr[s1 - 1] = number;
}
//Изменение имени и телефона
void Task2_recin(char** arr, int &s1, int NumbName) {
    system("cls");
    char* newbuff = new char[256];
    char* newnumber = new char[256];
    cout << "Введите новое имя: ";
    cin.ignore(256, '\n'); //Очистка потока ввода
    gets_s(newbuff, 256); 
    arr[NumbName-1] = newbuff;
    cout << "Введите новый номер телефона: ";
    gets_s(newnumber, 256);
    arr[NumbName] = newnumber;
}

void Task2_searchOnName(char** arr,char*name, int s1) {
    system("cls");
    char a;
    for (int i = 0; i < s1;i++) {
        if (arr[i] == name) {
            cout << arr[i] << endl;
            cout << arr[i + 1] << endl;
        }
    }
    cout << "Продолжить? - ";
    cin >> a;
}

void Task2_searchOnNumber(char** arr, char* number, int s1) {
    system("cls");
    char a;
    for (int i = 1; i < s1; i++) {
        if (arr[i] == number) {
            cout << arr[i-1] << endl;
            cout << arr[i] << endl;
        }
    }
    cout << "Продолжить? - ";
    cin >> a;
}


//Mode 0 - первое задание; Mode 1 - второе (Поменяйте значение мод (константы) на 0, чтобы проверить первое)
#if (Mode == 0)
int main()
{
    //Task1
    int M = 2;
    int N = 3;
    int** arr = new int* [M];
    for (int j = 0,k = 0; j < M; j++) {
        arr[j] = new int[N];
    }
    //Заполнение и проверка P.S заполнение столь простое, чтобы легче было соорентироваться
    for (int i = 0, k = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = k;
            k++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //Task1(arr, M, N);


    //Task2



}
#else
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int s1 = 0;
    char** arr = new char*[1];
    int us;
    bool flag = true;
    int uss;
    while (flag) {
        cout << "Выберите опцию:\n\n";
        cout << "1 - ввести новое имя и телефон;\n";
        cout << "2 - изменить имя и телефон;\n";
        cout << "3 - поиск по номеру или телефону;\n";
        cin >> us;
        switch (us) {
        case 1:
            Task2_cin(arr, s1);
            break;
        case 2:
            int nameNumb;
            cout << "Введите номер имя для изменения: ";
            cin >> nameNumb;
            Task2_recin(arr, s1, nameNumb);
            break;
        case 3:
            system("cls");
            cout << "Осуществить поиск по номеру телефона(1)/имени(2):\n";
            cin >> uss;
            char* buff = new char[256];
            switch (uss) {
            case 1:
                cout << "Введите искомый номер телефона: \n";
                cin.ignore(256, '\n'); //Очищаем поток ввода
                gets_s(buff, 256);
                Task2_searchOnNumber(arr, buff, s1);
                break;
            case 2:
                cout << "Введите искомое имя: \n";
                cin.ignore(256, '\n'); //Очищаем поток ввода
                gets_s(buff, 256);
                Task2_searchOnName(arr, buff, s1);
            }
            break;
        }




        //Проверки ради
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < s1; j++) {
                cout << arr[j] << " ";
            }
            cout << endl;
        }



    }

}
#endif

