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
        while (arr[i] < pivot) i++;
        // Находим элемент справа, который должен быть слева
        while (arr[j] > pivot) j--;

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

    vector<int> nums_1(n);
    vector<int> nums_2(m);
    vector<int> result;

    for (int i = 0; i < n; i++) {
        cin >> nums_1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> nums_2[i];
    }

    quick_sort(nums_1, 0, nums_1.size() - 1);
    quick_sort(nums_2, 0, nums_2.size() - 1);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (nums_1[i] == nums_2[j]) {
            result.push_back(nums_1[i]);
            i++;
            j++;
        }
        else if (nums_1[i] < nums_2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}