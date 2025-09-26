#include <bits/stdc++.h>

using namespace std;

int main(){

    string str1;
    string str2;
    stack<char> st1;
    stack<char> st2;

    cin >> str1 >> str2;

    for(int i = 0; i < str1.size(); i++){
        if(str1[i] != '#') st1.push(str1[i]); // если у нас буква - вписываем в стек
        else st1.pop(); // если у нас # то удаляем последнее значение
    }
    for(int i = 0; i < str2.size(); i++){
        if(str2[i] != '#') st2.push(str2[i]);
        else st2.pop();
    }

    if(st1 == st2) cout << "Yes";
    else cout << "No";

    return 0;
}