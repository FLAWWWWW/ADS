#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSplit(vector<long long> nums, long long mid, long long k){
    long long sector = 1;
    long long sum = 0;

    for(long long num : nums){
        if(sum + num > mid){
            sector++;
            sum = num;
            if(sector > k) return false;
        }
        else{
            sum += num;
        }
    }
    return sector <= k;
}

long long findSum(vector<long long> nums){
    long long sum = 0;
    for(long long num : nums){
        sum += num;
    }
    return sum;
}

long long binary_search(vector<long long> nums, long long k) {
    long long l = *max_element(nums.begin(), nums.end()), r = findSum(nums);
    while (l < r)
    {
        long long mid = (l + r) / 2;
        if (canSplit(nums, mid, k))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << binary_search(nums, k);
    return 0;
}