#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
public:
    vector<long long> a;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    long long getMin() { return a[0]; }

    void insert(long long k) {
        a.push_back(k);
        int ind = a.size() - 1;
        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1) return;
        
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);
            
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

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
    int n, m;
    cin >> n >> m;
    
    MinHeap heap;
    
    for (int i = 0; i < n; i++) {
        long long density;
        cin >> density;
        heap.insert(density);
    }
    
    int operations = 0;
    
    while (!heap.empty() && heap.getMin() < m) {
        // Если мы так и не дошли до нужной плотности и у нас остался только один пузырёк с веществом, то у нас ничего не вышло и выводим -1
        if (heap.size() < 2) {
            cout << -1 << endl;
            return 0;
        }
        
        long long first = heap.extractMin();
        long long second = heap.extractMin();
        
        // По формуле вычисляем новую плотность, заносим её в кучу как новое вещество и увеличиваем количество смешиваний
        long long new_density = first + 2 * second;
        heap.insert(new_density);
        operations++;
    }
    
    cout << operations << endl;
    
    return 0;
}