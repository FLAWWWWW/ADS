#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int> nums, int x) {
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == x) return true;
        else if(nums[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    int n, x, temp;
    vector<int> nums;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> temp;
        nums.push_back(temp);
    }

    cin >> x;

    if(binary_search(nums, x)) cout << "Yes" << endl;
    else cout << "No" << endl;
}