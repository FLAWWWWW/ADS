#include <iostream>
#include <vector>
using namespace std;

int find_min_length(vector<int>& prefix, int x) {
    int n = prefix.size() - 1;
    int min_length = n + 1;

    for (int i = 1; i <=n; i++){
        int target = prefix[i] - x;

        int left = 0, right = i - 1;
        int best = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (prefix[mid] <= target){
                best = mid;
                left = mid + 1;
            } 
            else right = mid - 1;
        }
        if (best != -1) {
            int length = i - best;
            if (length < min_length) {
                min_length = length;
            }
        }
    }

    return min_length;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector <int> lines_in_blocks(n);
    for(int i = 0; i < n; i++){
        cin >> lines_in_blocks[i];
    }

    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + lines_in_blocks[i - 1]; // 0 + 3; 3 + 4 => для первого блока: 0-3, для второго блока: 4-7
    }

    cout << find_min_length(prefix, k);
}