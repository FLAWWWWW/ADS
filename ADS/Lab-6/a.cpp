#include <iostream>
#include <vector>
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
    int n;
    char temp;
    cin >> n;

    vector<char> vowels;
    vector<char> consonants;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
            vowels.push_back(temp);
        }
        else {
            consonants.push_back(temp);
        }
    }

    if (!vowels.empty()) {
        quick_sort(vowels, 0, vowels.size() - 1);
    }
    
    if (!consonants.empty()) {
        quick_sort(consonants, 0, consonants.size() - 1);
    }

    for (char c : vowels) {
        cout << c;
    }
    for (char c : consonants) {
        cout << c;
    }

    return 0;
}