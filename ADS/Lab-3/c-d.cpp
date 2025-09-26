#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long binary_search(const vector<long long>& nums, long long x, long long y) {
    long long n = nums.size();

    long long left = 0, right = n - 1, leftIndex = -1;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (nums[mid] >= x) {
            leftIndex = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    left = 0, right = n - 1;
    long long rightIndex = -1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (nums[mid] <= y) {
            rightIndex = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (leftIndex == -1 || rightIndex == -1 || leftIndex > rightIndex) return 0;
    return rightIndex - leftIndex + 1;
}

int main() {
    long long n, q;
    cin >> n >> q;

    vector<long long> nums(n);
    vector<long long> num_of_indeces(q);
    for (long long i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (long long i = 0; i < q; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (r1 < l2 || r2 < l1) {
            num_of_indeces[i] = binary_search(nums, l1, r1) + binary_search(nums, l2, r2);
        } else {
            num_of_indeces[i] = binary_search(nums, min(l1, l2), max(r1, r2));
        }
    }

    for (long long i = 0; i < q; i++) {
        cout << num_of_indeces[i] << endl;
    }
    return 0;
}
