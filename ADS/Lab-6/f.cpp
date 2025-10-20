#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string lastname;
    string firstname;
    double gpa;
};

double gradeToNumber(string grade) {
    if (grade == "A+") return 4.00;
    if (grade == "A") return 3.75;
    if (grade == "B+") return 3.50;
    if (grade == "B") return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C") return 2.00;
    if (grade == "D+") return 1.50;
    if (grade == "D") return 1.00;
    if (grade == "F") return 0.00;
    return 0.00;
}

void quick_sort(vector<Student>& arr, int l, int r) {
    if (l >= r) return;
    
    Student pivot = arr[(l + r) / 2];
    int i = l;
    int j = r;

    while (i <= j) {
        while (arr[i].gpa < pivot.gpa || 
               (arr[i].gpa == pivot.gpa && arr[i].lastname < pivot.lastname) ||
               (arr[i].gpa == pivot.gpa && arr[i].lastname == pivot.lastname && arr[i].firstname < pivot.firstname)) {
            i++;
        }
        
        while (arr[j].gpa > pivot.gpa || 
               (arr[j].gpa == pivot.gpa && arr[j].lastname > pivot.lastname) ||
               (arr[j].gpa == pivot.gpa && arr[j].lastname == pivot.lastname && arr[j].firstname > pivot.firstname)) {
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
    string grade;
    int n, m, credits;
    cin >> n;
    
    vector<Student> students(n);
    
    for (int i = 0; i < n; i++) {
        cin >> students[i].lastname >> students[i].firstname;
        
        cin >> m;
        
        double count = 0;
        double sum = 0;
        
        for (int j = 0; j < m; j++) {
            cin >> grade >> credits;
            
            double grade_num = gradeToNumber(grade);
            sum += grade_num * credits;
            count += credits;
        }
        
        students[i].gpa = sum / count;
    }
    
    quick_sort(students, 0, n - 1);
    
    cout << fixed << setprecision(3);
    for (int i = 0; i < n; i++) {
        cout << students[i].lastname << " " << students[i].firstname << " " << students[i].gpa << endl;
    }
    
    return 0;
}