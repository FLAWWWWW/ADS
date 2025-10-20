#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    char target;
    cin >> n;
    
    vector<char> letters(n);
    for (int i = 0; i < n; i++) {
        cin >> letters[i];
    }

    cin >> target;
    
    int left = 0, right = n - 1;
    char result = letters[0];
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (letters[mid] > target) {
            result = letters[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}