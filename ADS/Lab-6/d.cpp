#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

void quick_sort(vector<Date>& arr, int l, int r) {
    if (l >= r) return;
    
    Date pivot = arr[(l + r) / 2];
    int i = l;
    int j = r;

    while (i <= j) {
        // Сравниваем даты: сначала год, потом месяц, потом день
        while (arr[i].year < pivot.year || 
               (arr[i].year == pivot.year && arr[i].month < pivot.month) ||
               (arr[i].year == pivot.year && arr[i].month == pivot.month && arr[i].day < pivot.day)) {
            i++;
        }
        
        while (arr[j].year > pivot.year || 
               (arr[j].year == pivot.year && arr[j].month > pivot.month) ||
               (arr[j].year == pivot.year && arr[j].month == pivot.month && arr[j].day > pivot.day)) {
            j--;
        }

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
    string temp;
    
    vector<Date> dates(n);
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        
        // Переводим строку в интеджер
        dates[i].day = stoi(temp.substr(0, 2));
        dates[i].month = stoi(temp.substr(3, 2));
        dates[i].year = stoi(temp.substr(6, 4));
    }
    
    quick_sort(dates, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        if (dates[i].day < 10) cout << "0";
        cout << dates[i].day << "-";
        
        if (dates[i].month < 10) cout << "0";
        cout << dates[i].month << "-";
    
        cout << dates[i].year << endl;
    }
    
    return 0;
}