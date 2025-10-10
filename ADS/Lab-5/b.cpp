#include <iostream>
#include <vector>
using namespace std;

// Та же логика как с MinHeap, только теперь у 
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
    int n;
    cin >> n;
    
    MaxHeap heap;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.insert(x);
    }
    
    while (heap.size() > 1) {
        int first = heap.extractMax();
        int second = heap.extractMax();
        
        // Если у нас разные камни, то мы хотим их разность снова вставить в кучу
        if (first != second) {
            heap.insert(first - second);
        }
    }
    
    if (heap.empty()) {
        cout << 0 << endl;
    } else {
        cout << heap.getMax() << endl;
    }
    
    return 0;
}