#include <bits/stdc++.h>
using namespace std;

int main() {

    queue<int> BorisCards;
    queue<int> NursikCards;

    int b1, b2, b3, b4, b5, n1, n2, n3, n4, n5;

    cin >> b1 >> b2 >> b3 >> b4 >> b5 >> n1 >> n2 >> n3 >> n4 >> n5;

    BorisCards.push(b1); BorisCards.push(b2); BorisCards.push(b3); BorisCards.push(b4); BorisCards.push(b5);
    NursikCards.push(n1); NursikCards.push(n2); NursikCards.push(n3); NursikCards.push(n4); NursikCards.push(n5);

    int count = 0; // количество ходов

    // у игры есть максимум 1000000 раундов или пока карты игроков не закончатся
    while(count <= 1000000 && !BorisCards.empty() && !NursikCards.empty()){
        count++;

        int borisCard = BorisCards.front();
        int nursikCard = NursikCards.front();

        BorisCards.pop(); NursikCards.pop(); // мы "забираем" карты игроков и начинаем их сравнивать

        // случай если Борис победил
        if((borisCard == 0 && nursikCard == 9) || (borisCard > nursikCard && (borisCard != 9 || nursikCard != 0))){
            BorisCards.push(borisCard);
            BorisCards.push(nursikCard);
        }
        else {
            NursikCards.push(borisCard);
            NursikCards.push(nursikCard);
        }
        
    }

    
    if(count >= 1000000) cout << "blin nichiya";
    else if(BorisCards.empty()) cout << "Nursik " << count;
    else cout << "Boris " << count;

    return 0;
}
