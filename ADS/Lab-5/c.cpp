#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> a;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    int getMax() { return a[0]; }

    void insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;
        while (ind > 0 && a[ind] > a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1) return;
        
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] > a[left(i)])
            j = right(i);
            
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMax() {
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0) heapify(0);
        return root_value;
    }

    int size() { return a.size(); }
    bool empty() { return a.empty(); }
};

int main() {
    int n, x;
    cin >> n >> x;
    
    MaxHeap heap;
    
    for (int i = 0; i < n; i++) {
        int seats;
        cin >> seats;
        heap.insert(seats);
    }
    
    long long total = 0;
    
    for (int i = 0; i < x; i++) {
        // Если все ряды пусты, то мы закончили
        if (heap.empty()) break;
        
        // Получаем прибыль с места
        int current = heap.extractMax();
        total += current;
        
        // Отправляем обратно в кучу наш ряд с оставшимися местами
        if (current > 1) {
            heap.insert(current - 1);
        }
    }
    
    cout << total << endl;
    
    return 0;
}