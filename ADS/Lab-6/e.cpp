#include <iostream>
#include <vector>

using namespace std;


void quick_sort(vector<int>& arr, int l, int r) {
    if (l >= r) return; // Если вышли за границы, то выходим
    
    // Выбираем средний элемент как опорный, чтобы разделить массив пополам
    int pivot = arr[(l + r) / 2];
    int i = l;
    int j = r;

    // Разделение массива
    while (i <= j) {
        // Находим элемент слева, который должен быть справа
        while (arr[i] > pivot) i++;
        // Находим элемент справа, который должен быть слева
        while (arr[j] < pivot) j--;

        // Меняем элементы местами, если нужно
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Рекурсивно сортируем левую часть
    if (l < j)
        quick_sort(arr, l, j);
    // Рекурсивно сортируем правую часть
    if (i < r)
        quick_sort(arr, i, r);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        // Собираем элементы столбца в отдельный вектор
        vector<int> column;
        for (int i = 0; i < n; i++) {
            column.push_back(matrix[i][j]);
        }
        
        quick_sort(column, 0, n - 1);
        
        for (int i = 0; i < n; i++) {
            matrix[i][j] = column[i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}