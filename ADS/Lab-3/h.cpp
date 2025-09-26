#include <iostream>
#include <vector>
using namespace std;

int findLine(vector<int>& prefix, int x) {
    int left = 0, right = prefix.size() - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        
        if(prefix[mid] < x) left = mid + 1;
        else if(prefix[mid] > x) right = mid - 1;
        else return mid;
    }
    return left;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector <int> lines_in_blocks(n);
    for(int i = 0; i < n; i++){
        cin >> lines_in_blocks[i];
    }
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + lines_in_blocks[i - 1]; // 0 + 3; 3 + 4 => для первого блока: 0-3, для второго блока: 4-7
    }
    
    vector <int> lines_with_mistake(m);
    for(int i = 0; i < m; i++){
        cin >> lines_with_mistake[i];
    }

    for(int x : lines_with_mistake){
        int line = findLine(prefix, x);
        cout << line << "\n";
    }
}