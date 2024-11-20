#include <iostream>
#include <climits> // Для использования INT_MAX
#include <vector>  // Для хранения путей

using namespace std;

const int V = 9;

void Dijkstra(int GR[V][V], int st, long long& operations);
void PrintPath(int parent[], int j);  // Функция для печати пути

int main()
{
    setlocale(LC_ALL, "Russian"); // правильная строка для локализации
    int start;
    int GR[V][V] = {
        {0,  7,  10, 0,  0,  0,  0 , 0,  0},//   A матрица смежности
        {7,  0,  0,  0,  0,  9,  27, 0,  0},//   B
        {10, 0,  0,  0,  31, 8,  0,  0,  0},//   C
        {0,  0,  0,  0,  32, 0,  0,  17, 21},//  D
        {0,  0,  31, 32, 0,  0,  0,  0,  0},//   E
        {0,  9,  8,  0,  0,  0,  0,  11, 0},//   F
        {0,  27, 0,  0,  0,  0,  0,  0,  15},//  G
        {0,  0,  0,  17, 0,  11, 0,  0,  15},//  H
        {0,  0,  0,  21, 0,  0,  15, 15, 0} };// I
    //       A   B   C   D   E   F   G   H   I

    char symbols[40];
    bool pr = false;
    printf("введите начальную вершину(A-I): ");

    while (!pr)
    {
        cin >> symbols;
        if (symbols[1] == '\0' && (symbols[0] == 'A' || symbols[0] == 'B' || symbols[0] == 'C' ||
            symbols[0] == 'D' || symbols[0] == 'E' || symbols[0] == 'F' ||
            symbols[0] == 'G' || symbols[0] == 'H' || symbols[0] == 'I'))
            pr = true;
        else
            printf("Надо ввести одну букву из диапазона A-I!: ");
    }
    int letter = symbols[0] - 'A';  // Преобразуем символ в индекс (A = 0, B = 1, и т.д.)

    long long operations = 0;  // Счетчик операций
    Dijkstra(GR, letter, operations);

    // Вывод асимптотики и числа операций
    printf("Общее количество операций: %lld\n", operations);
    printf("Оценка сложности алгоритма Дейкстры для данной реализации: O(V^2)\n");
}

void Dijkstra(int GR[V][V], int st, long long& operations)
{
    int length[V], index, u;
    bool visited[V];
    int parent[V];  // Массив для хранения пути

    // Инициализация массива расстояний, посещений и посещенных
    for (int i = 0; i < V; i++)
    {
        length[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;  // -1 означает, что у вершины нет посещенной
        operations++;  // операция для каждой инициализации
    }
    length[st] = 0;

    // Основной цикл поиска кратчайших путей
    for (int count = 0; count < V - 1; count++)
    {
        int min = INT_MAX;

        // Поиск вершины с минимальным расстоянием
        for (int i = 0; i < V; i++)
        {
            operations++;  // операция для каждой проверки вершины
            if (!visited[i] && length[i] <= min)
            {
                min = length[i];
                index = i;
                operations++;  // операция для обновления минимума
            }
        }

        u = index;
        visited[u] = true;
        operations++;  // операция для отметки вершины как посещенной

        // Обновление расстояний до соседей
        for (int i = 0; i < V; i++)
        {
            operations++;  // операция для каждой проверки соседа
            if (!visited[i] && GR[u][i] && length[u] != INT_MAX && length[u] + GR[u][i] <= length[i])
            {
                length[i] = length[u] + GR[u][i];
                parent[i] = u;  // Сохраняем предшественника
                operations++;  // операция для обновления расстояния
            }
        }
    }

    // Вывод результатов
    printf("Длина маршрутов и пути:\n");
    for (int i = 0; i < V; i++)
    {
        if (length[i] != INT_MAX)
        {
            printf("Из вершины %c в %c : %d, Путь: ", (char)(st + 'A'), (char)(i + 'A'), length[i]);
            PrintPath(parent, i);  // Выводим путь
            printf("\n");
        }
        else
            printf("Из вершины %c в %c : недоступен\n", (char)(st + 'A'), (char)(i + 'A'));
    }
}

// Функция для вывода пути
void PrintPath(int parent[], int j)
{
    // Базовый случай: если у вершины нет предшественника
    if (parent[j] == -1)
        return;

    // Рекурсивно выводим путь до вершины-источника
    PrintPath(parent, parent[j]);

    // Выводим текущую вершину
    printf("%c ", (char)(j + 'A'));
}
