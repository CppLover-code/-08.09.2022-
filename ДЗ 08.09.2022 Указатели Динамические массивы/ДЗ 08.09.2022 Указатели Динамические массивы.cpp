//Первое задание
#include <iostream>
#include <ctime>
using namespace std;

int* make_arr(size_t n);
void fill_random(int* arr, size_t length);
void print_arr(int* arr, size_t length);
void elements_ar1(int* ar1, int* ar2, int* ar3, size_t m, size_t n, int* px);
void copy_ar(int* ar3, int* ar4, size_t p, int* cx);
void result_clean(int* ar3, int* ar4, int* ar5, size_t p, size_t c, int* dx);
void show_result(int* ar5, size_t d);
void del_arr(int* ar, size_t n);

int main()
{
    srand(time(0));

    int m, n; // 1-2 ar size

    int p = 0;// 3 ar size
    int* px = &p;

    int c = 0;// 4 ar size
    int* cx = &c;

    int d = 0;// 5 ar size
    int* dx = &d;

    cout << "Enter the size of 1 dynamic array:\n";
    cin >> m;
    cout << "Enter the size of 2 dynamic array:\n";
    cin >> n;

    int* ar1 = nullptr;
    int* ar2 = nullptr;
    int* ar3 = nullptr; // первый массив результатов с повторяющимися элементами
    int* ar4 = nullptr; // копия 3 массива
    int* ar5 = nullptr; // результат в новом массиве без повторений

    ar1 = make_arr(m);
    ar2 = make_arr(n);
    ar3 = make_arr(p); 
    ar4 = make_arr(c);
    ar5 = make_arr(d);

    fill_random(ar1, m); 
    fill_random(ar2, n);

    cout << "\n\t1 dynamic array:\n";
    print_arr(ar1, m);
    cout << "\n\t2 dynamic array:\n\n";
    print_arr(ar2, n);

    elements_ar1(ar1, ar2, ar3, m, n, px);
    copy_ar(ar3, ar4, p, cx);
    result_clean(ar3, ar4, ar5, p, c, dx);
    show_result(ar5, d);  

    del_arr(ar1, m);
    del_arr(ar2, n);
    //del_arr(ar3, p);
    //del_arr(ar4, c);
    //del_arr(ar5, d);
   
    return 0;
}

int* make_arr(size_t n) 
{
    if (n > 100) // "некий лимит памяти"
    {     
        return NULL;   // превышен "лимит" - возврат NULL как признак ошибки
    }
    return new int[n]; // выделение реальной памяти
}

void fill_random(int* arr, size_t length) 
{
    if (!arr) // для борьбы с ошибкой arr = NULL
    {  
        cout << "fill_random: NULL pointer error" << "\n";
        return;
    }
    for (size_t i = 0; i < length; i++) 
    {
        arr[i] = rand() % 10 + 1;
    }
}

void print_arr(int* arr, size_t length) 
{
    if (!arr) 
    {
        cout << "print_arr: NULL pointer error" << "\n";
        return;
    }
    for (size_t i = 0; i < length; i++) 
    {
        cout << arr[i] << ' ';
    }
    cout << "\n";
}

void elements_ar1(int* ar1, int* ar2, int* ar3, size_t m, size_t n, int *px)
{
    int same = 0;

    for (size_t i = 0; i < m; i++)//  1 ar
    {
        for (size_t y = 0; y < n; y++) // 2 ar
        {
            if (ar2[y] == ar1[i]) same++;
        }
        if (same == 0)
        {
            ar3[*px] = ar1[i];
            *px = *px + 1;
        }
        same = 0;
    }
}

void copy_ar(int* ar3, int* ar4, size_t p, int* cx)
{
    for (size_t i = 0; i < p; i++)
    {
        ar4[*cx] = ar3[i];
        *cx = *cx + 1;
    }
}

void result_clean(int* ar3, int* ar4, int* ar5, size_t p, size_t c, int* dx)
{
    int l = p - 1;
    for (size_t i = 0; i < p; i++)
    {
        int w = 0;

        for (size_t y = i + 1; y < c; y++)
        {
            if (ar3[i] != ar4[y])
            {
                w++;
            }
            else
            {
                l--;
                w = 0;
                break;
            }
        }
        if (w == l)
        {
            ar5[*dx] = ar3[i];
            *dx = *dx + 1;
            l = l - 1;
        }
    }
}

void show_result(int* ar5, size_t d)
{
    cout << "\n Elements 1 array that are not present in the second:\n\n";
    for (size_t i = 0; i < d; i++)
    {
        cout << ar5[i] << ' ';
    }
    cout << "\n";
}

void del_arr(int* ar, size_t n)
{
    for (int y = 0; y < n; y++)
    {
        ar[y] = NULL;
    }
    delete[] ar;
}

////Второе задание
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int* make_arr(size_t n)
//{
//    if (n > 100) // "некий лимит памяти"
//    {
//        return NULL;   // превышен "лимит" - возврат NULL как признак ошибки
//    }
//    return new int[n]; // выделение реальной памяти
//}
//
//void fill_random(int* arr, size_t length)
//{
//    if (!arr) // для борьбы с ошибкой arr = NULL
//    {
//        cout << "fill_random: NULL pointer error" << "\n";
//        return;
//    }
//    for (size_t i = 0; i < length; i++)
//    {
//        arr[i] = rand() % 10 + 1;
//    }
//}
//void print_arr(int* arr, size_t length)
//{
//    if (!arr)
//    {
//        cout << "print_arr: NULL pointer error" << "\n";
//        return;
//    }
//    for (size_t i = 0; i < length; i++)
//    {
//        cout << arr[i] << ' ';
//    }
//    cout << "\n";
//}
//void new_arr(int* ar1, int* ar2, int* ar3, size_t m, size_t n, int *px)
//{
//    for (size_t i = 0; i < m; i++)
//    {
//        int w = 0;
//        for (size_t y = 0; y < n; y++)
//        {
//            if (ar1[i] != ar2[y])
//            {
//                w++;
//            }
//            else
//            {
//                w = w + 0;
//            }
//        }
//        if (w == n)
//        {
//            ar3[*px] = ar1[i];
//            *px = *px + 1;
//        }
//    }
//    for (size_t i = 0; i < n; i++)
//    {
//        int w = 0;
//        for (size_t y = 0; y < m; y++)
//        {
//            if (ar2[i] != ar1[y])
//            {
//                w++;
//            }
//            else
//            {
//                w = w + 0;
//            }
//        }
//        if (w == m)
//        {
//            ar3[*px] = ar2[i];
//            *px = *px + 1;
//        }
//    }
//}
//void copy_ar(int* ar3, int* ar4, size_t p, int* cx)
//{
//    for (size_t i = 0; i < p; i++)
//    {
//        ar4[*cx] = ar3[i];
//        *cx = *cx + 1;
//    }
//}
//void result_clean(int* ar3, int* ar4, int* ar5, size_t p, size_t c, int* dx)
//{
//    int l = p - 1;
//    for (size_t i = 0; i < p; i++)
//    {
//        int w = 0;
//
//        for (size_t y = i + 1; y < c; y++)
//        {
//            if (ar3[i] != ar4[y])
//            {
//                w++;
//            }
//            else
//            {
//                l--;
//                w = 0;
//                break;
//            }
//        }
//        if (w == l)
//        {
//            ar5[*dx] = ar3[i];
//            *dx = *dx + 1;
//            l = l - 1;
//        }
//    }
//}
//void show_result(int* ar5, size_t d)
//{
//    cout << "\n Different elements of two arrays:\n\n";
//    for (size_t i = 0; i < d; i++)
//    {
//        cout << ar5[i] << ' ';
//    }
//    cout << "\n";
//}
//void del_arr(int* ar, size_t n)
//{
//    for (int y = 0; y < n; y++)
//    {
//        ar[y] = NULL;
//    }
//    delete[] ar;
//}
//
//int main()
//{
//    setlocale(0, "rus");
//    srand(time(0));
//
//    int m, n; // 1-2 ar size
//
//    int p = 0;// 3 ar size
//    int* px = &p;
//
//    int c = 0;// 4 ar size
//    int* cx = &c;
//
//    int d = 0;// 5 ar size
//    int* dx = &d;
//
//    cout << "Enter the size of 1 dynamic array:\n";
//    cin >> m;
//    cout << "Enter the size of 2 dynamic array:\n";
//    cin >> n;
//
//    int* ar1 = nullptr;
//    int* ar2 = nullptr;
//    int* ar3 = nullptr;
//    int* ar4 = nullptr; 
//    int* ar5 = nullptr; 
//
//    ar1 = make_arr(m);
//    ar2 = make_arr(n);
//    ar3 = make_arr(p);
//    ar4 = make_arr(c);
//    ar5 = make_arr(d);
//
//    fill_random(ar1, m);
//    fill_random(ar2, n);
//
//    cout << "\n\t1 dynamic array:\n";
//    print_arr(ar1, m);
//    cout << "\n\t2 dynamic array:\n\n";
//    print_arr(ar2, n);
//    new_arr(ar1, ar2, ar3, m, n, px);
//    copy_ar(ar3, ar4, p, cx);
//    result_clean(ar3, ar4, ar5, p, c, dx);
//    show_result(ar5, d);
//
//    del_arr(ar1, m);
//    del_arr(ar2, n);
//    //del_arr(ar3, p);
//    //del_arr(ar4, c);
//    //del_arr(ar5, d);
//
//    return 0;
//}