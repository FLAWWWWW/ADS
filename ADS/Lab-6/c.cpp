#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    
    int pivot = arr[(l + r) / 2];
    int i = l;
    int j = r;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        quick_sort(arr, l, j);
    if (i < r)
        quick_sort(arr, i, r);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    quick_sort(nums, 0, n - 1);
    
    int min_diff = 20000000;
    for (int i = 1; i < n; i++) {
        int diff = nums[i] - nums[i - 1];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] == min_diff) {
            cout << nums[i - 1] << " " << nums[i] << " ";
        }
    }
    
    return 0;
}