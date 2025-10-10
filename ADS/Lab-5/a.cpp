#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
public:
    vector<long long> a;

    // У нас количество узлов на уровне i будет равно 2^i
    // Чтобы получить первый индекс уровня i, нужно взять 2^i - 1
    int parent(int i) { 
        return (i - 1) / 2; 
    }

    // Грубо говоря мы с помощю умножения на i смотрим сколько узлов у нас прошло с прошлого уровня (для третьего уровня прошло 6 индексов/узлов)
    int left(int i) { 
        return 2 * i + 1; 
    }
    int right(int i) { 
        return 2 * i + 2; 
    }

    // Получить первый, в нашем случае минимальный элемент
    long long getMin() { 
        return a[0]; 
    }

    void insert(long long k) {
        a.push_back(k);
        int ind = a.size() - 1;
        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        // Проверяем не вышли ли мы за пределы
        if (left(i) > a.size() - 1) return;
        
        // Выбираем меньшего из двух детей
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);
        
        // Если родитель больше ребёнка, меняем их местами
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    // Тут мы просто хотим взять минимальный элемент и удалить его
    long long extractMin() {
        long long root_value = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0) heapify(0);
        return root_value;
    }

    int size() { return a.size(); }
    bool empty() { return a.empty(); }
};

int main() {
    int n;
    cin >> n;
    
    MinHeap heap;
    
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        heap.insert(x);
    }
    
    long long total_cost = 0;
    
    while (heap.size() > 1) {
        long long first = heap.extractMin();
        long long second = heap.extractMin();
        
        long long cost = first + second;
        total_cost += cost;
        heap.insert(cost);
    }
    
    cout << total_cost << endl;
    
    return 0;
}