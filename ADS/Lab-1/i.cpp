#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    string s;
    cin >> n;
    cin >> s;

    queue<int> KLetters;
    queue<int> SLetters;
    // мы заполняем наши очереди индексами (первым появлением определённой буквы)
    for (int i = 0; i < n; i++) {
        if(s[i] == 'K') KLetters.push(i);
        else SLetters.push(i);
    }

    while(!KLetters.empty() && !SLetters.empty()) {
        if(KLetters.front() < SLetters.front()) KLetters.push(KLetters.front() + n); // мы добавляем в конец очереди букву (грубо говоря она остаётся первой, когда до неё дойдёт круг)
        else SLetters.push(SLetters.front() + n);
        KLetters.pop();
        SLetters.pop();
    }

    if(KLetters.empty()) cout << "SAKAYANAGI";
    else cout << "KATSURAGI";

    return 0;
}
