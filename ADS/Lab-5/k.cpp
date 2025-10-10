#include <iostream>
#include <vector>
#include <string>
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
    int q, k;
    cin >> q >> k;
    
    MinHeap heap;
    long long sum = 0;
    
    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;
        
        if (command == "insert") {
            long long n;
            cin >> n;
            
            // Если у нас меньше чем k коробок, то добавляем новую
            if (heap.size() < k) {
                heap.insert(n);
                sum += n;
            }
            // Если же у нас больше коробок, то тогда мы хотим добавить новую коробку, если в ней больше печенек, чем в наименьшей коробке 
            else if (n > heap.getMin()) {
                // Мы меняем текущую сумму и вместе с этим удаляем текущую коробку с печеньем
                sum -= heap.extractMin();
                heap.insert(n);
                sum += n;
            }
        } else if (command == "print") {
            cout << sum << endl;
        }
    }
    
    return 0;
}