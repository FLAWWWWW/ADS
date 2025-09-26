#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> st;

    for (char c : str) {
        if (!st.empty() && st.top() == c) st.pop(); // мы проходимся по всем буквам и если последнее значение "закрывается" (повторяется) текущим, то мы его удаляем - скобка закрыта
        else st.push(c);
    }

    if(st.empty()) cout << "YES";
    else cout << "NO";

    return 0;
}
