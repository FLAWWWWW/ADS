#include <iostream>
#include <vector>
using namespace std;

pair<int, int> searchInRow(const vector<int>& row, int x, int rowIndex) {
    int left = 0, right = row.size() - 1;
    if (rowIndex % 2 == 0) { 
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (row[mid] == x) return {rowIndex, mid};
            else if (row[mid] < x) right = mid - 1;
            else left = mid + 1;
        }
    } else { 
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (row[mid] == x) return {rowIndex, mid};
            else if (row[mid] < x) left = mid + 1;
            else right = mid - 1;
        }
    }
    return {-1, -1};
}

int main() {
    int n;
    cin >> n;
    vector <int> nums_to_find(n);
    for(int i = 0; i < n; i++){
        cin >> nums_to_find[i];
    }

    int numRows, numCols;
    cin >> numRows >> numCols;
    vector<vector<int>> snake(numRows, vector<int>(numCols));

    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            cin >> snake[i][j];
        }
    }

    for(int x : nums_to_find){

        pair<int, int> result = {-1, -1};
        for(int i = 0; i < numRows; i++){
            result = searchInRow(snake[i], x, i); 
            if(result.first != -1){
                break;
            }
        }

        if(result.first == -1){
            cout << -1 << endl;
        }
        else{
            cout << result.first << " " << result.second << endl;
        }

    }
}