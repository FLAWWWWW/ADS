#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ages(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() > ages[i]) { // мы удаляем все числа из стака, которые больше текущего, но как только находим число меньше, то идём ниже по условию и выводим его
            st.pop();
        }

        if (st.empty()) {
            cout << -1 << " ";
        } 
        else {
            cout <<st.top() << " ";
        }

        st.push(ages[i]);
    }

    return 0;
}
