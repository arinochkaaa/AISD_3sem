﻿#include <iostream>
#include <Windows.h>
#include <chrono> 

using namespace std;
using namespace std::chrono;  


void Floud();       
void ShowTables();  


int D[6][6]
{
    //	 1   2   3   4   5   6
        {0, 28, 21, 59, 12, 27},         // От вершины 1 до остальных вершин
        {7, 0, 24, INT_MAX, 21, 9},      // От вершины 2 до остальных вершин
        {9, 32, 0, 13, 11, INT_MAX},     // От вершины 3 до остальных вершин
        {8, INT_MAX, 5, 0, 16, INT_MAX}, // От вершины 4 до остальных вершин
        {14, 13, 15, 10, 0, 22},         // От вершины 5 до остальных вершин
        {15, 18, INT_MAX, INT_MAX, 6, 0} // От вершины 6 до остальных вершин
};


int S[6][6]
{
    //   1  2  3  4  5  6
        {0, 2, 3, 4, 5, 6},  
        {1, 0, 3, 4, 5, 6},  
        {1, 2, 0, 4, 5, 6},  
        {1, 2, 3, 0, 5, 6},  
        {1, 2, 3, 4, 0, 6},  
        {1, 2, 3, 4, 5, 0}   
};

int main()
{
    
    SetConsoleCP(1251);          
    SetConsoleOutputCP(1251);    

    
    auto start = high_resolution_clock::now();

    Floud();

   
    auto stop = high_resolution_clock::now();

    
    auto duration = duration_cast<microseconds>(stop - start);

    
    ShowTables();

    
    cout << "\nВремя выполнения алгоритма: " << duration.count() << " микросекунд\n";
    
    cout << "О-большое  O(n^3), где n - количество вершин\n";
}

// Реализация алгоритма Флойда-Уоршалла
void Floud()
{
    
    for (int m = 0; m < 6; m++)      // Перебираем каждую вершину как промежуточную
    {
        for (int i = 0; i < 6; i++)  // Перебираем строки (начальные вершины пути)
        {
            for (int j = 0; j < 6; j++)  // Перебираем столбцы (конечные вершины пути)
            {
               
                if (D[i][j] > D[i][m] + D[m][j])  // Сравниваем текущий путь с обходным через m
                {
                    D[i][j] = D[i][m] + D[m][j];  // Обновляем матрицу расстояний новым кратчайшим путём
                    S[i][j] = S[i][m];            // Обновляем матрицу путей — кратчайший путь теперь проходит через m
                }
            }
        }
    }
}


void ShowTables()
{
    
    cout << "Длины:\n";
    cout << "\t1\t2\t3\t4\t5\t6\t\n";   
    cout << "----------------------------------------------------------\n";

    
    for (int i = 0; i < 6; i++)  
    {
        cout << i + 1 << "|\t";  
        for (int j = 0; j < 6; j++)  
        {
            cout << D[i][j] << "\t"; 
        }
        cout << "\n";  
    }

    
    cout << "\n\nМатрица 'пути'\n";
    cout << "\t1\t2\t3\t4\t5\t6\t\n"; 
    cout << "----------------------------------------------------------\n";

 
    for (int i = 0; i < 6; i++) 
    {
        cout << i + 1 << "|\t";  
        for (int j = 0; j < 6; j++)  
        {
            cout << S[i][j] << "\t";  
        }
        cout << "\n";  
    }
}
