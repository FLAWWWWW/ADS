#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void quick_sort(vector<char>& arr, int l, int r) {
    if (l >= r) return; // Если вышли за границы, то выходим
    
    // Выбираем средний элемент как опорный, чтобы разделить массив пополам
    char pivot = arr[(l + r) / 2];
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
    string input;
    
    getline(cin, input);

    vector<char> chars;

    for (char c : input) {
        chars.push_back(c);
    }

    if (!chars.empty()) {
        quick_sort(chars, 0, chars.size() - 1);
    }

    for (char c : chars) {
        cout << c;
    }

    return 0;
}