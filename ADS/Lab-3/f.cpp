#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void binary_search(vector<int> nums, int x) {
    int left = 0, right = nums.size() - 1;
    int sum = 0, count = 0;
    int result = -1;


    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] <= x){
              result = mid;
              left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    for(int i = 0; i < result + 1; i++) {
        sum += nums[i];
        count++;
    }
    cout << count << " " << sum << endl;
}
int main() {

    int n, p; // p - round number
    int temp;
    cin >> n;

    vector<int> opponents_power(n);
    
    map<int, int> wins;
    for (int i = 0; i < n; i++) {
        cin >> opponents_power[i];
    }

    sort(opponents_power.begin(), opponents_power.end());

    cin >> p;
    vector<int> mark_power(p);

    for (int i = 0; i < p; i++) {
        cin >> temp;
        mark_power[i] = temp;
    }

    for (int i = 0; i < p; i++) {
        binary_search(opponents_power, mark_power[i]);
    }
}