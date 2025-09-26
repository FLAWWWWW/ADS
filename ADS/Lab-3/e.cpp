#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_length(vector<int> a, int k){
    int left = 0, right = a.size() - 1;

    while(left < right){
        int mid = (right+left)/2;
        if (mid == k){
            return a[mid - 1];
            left = mid + 1;
        } 
        else{
            right = mid - 1;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> max_coordinat(n); 
    
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        max_coordinat[i] = max(x2, y2); 
    }

    sort(max_coordinat.begin(), max_coordinat.end());
    
    cout << find_length(max_coordinat, k);
}