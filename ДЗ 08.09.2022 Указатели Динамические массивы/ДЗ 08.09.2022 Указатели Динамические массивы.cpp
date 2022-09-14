#include <iostream>
#include <ctime>
using namespace std;

int* make_arr(size_t n);
void fill_random(int* arr, size_t length);
void print_arr(int* arr, size_t length);
void elements_ar1(int* ar1, int* ar2, int* ar3, size_t m, size_t n, int* px);
void show_elements_ar1(int* ar3, size_t p);

int main()
{
    srand(time(0));

    int m, n;

    int p = 0;
    int* px = &p;

    cout << "Enter the size of 1 dynamic array:\n";
    cin >> m;
    cout << "Enter the size of 2 dynamic array:\n";
    cin >> n;

    int* ar1 = nullptr;
    int* ar2 = nullptr;
    int* ar3 = nullptr; // первый массив с результатами

    ar1 = make_arr(m);
    ar2 = make_arr(n);
    ar3 = make_arr(p); 

    fill_random(ar1, m); 
    fill_random(ar2, n);

    cout << "\n\t1 dynamic array:\n";
    print_arr(ar1, m);
    cout << "\n\t2 dynamic array:\n\n";
    print_arr(ar2, n);

    elements_ar1(ar1, ar2,ar3, m, n, px);
    show_elements_ar1(ar3, p);
    
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
        arr[i] = rand() % 20 + 1;
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

    for (size_t i = 0; i < m; i++)// mas 1
    {
        for (size_t y = 0; y < n; y++) // mas 2
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

void show_elements_ar1(int* ar3, size_t p)
{
    cout << "\n Elements 1 array that are not present in the second:\n";
    for (size_t i = 0; i < p; i++)
    {
        cout << ar3[i] << ' ';
    }
    cout << "\n";
}