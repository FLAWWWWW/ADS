#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void buildBalancedOrder(const vector<int>& sorted, vector<int>& result, int left, int right) {
    if (left > right) return;
    
    int mid = (right + left) / 2;
    // Мы отправляем назад серединный элемент, который мы хотим получить потом в начале после сортировки
    result.push_back(sorted[mid]);
    
    // Мы начинаем перебирать от этой середины право и лево и потом уже у этого право и лево мы тоже берём середины и рассматриваем их право и лево
    buildBalancedOrder(sorted, result, left, mid - 1);
    buildBalancedOrder(sorted, result, mid + 1, right);
}

int main() {
    int N;
    cin >> N;
    
    int size = pow(2, N) - 1;
    vector<int> arr(size);
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    // Сортируем массив по возрастанию
    sort(arr.begin(), arr.end());
    
    // Строим порядок для сбалансированного BST
    vector<int> result;
    buildBalancedOrder(arr, result, 0, size - 1);
    
    // Выводим результат
    for (int i = 0; i < size; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}