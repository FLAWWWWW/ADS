#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int num_of_tests;
    cin >> num_of_tests;
    vector<int> sizes(num_of_tests);

    for (int i = 0; i < num_of_tests; i++) {
        cin >> sizes[i];
    }

    for (int i = 0; i < num_of_tests; i++) {
        int size = sizes[i];
        queue<int> cards;
        vector<int> result(size); 
        int num_of_deleted_card = 1; // с каждым раундом у нас всё больше удаляются карты (на 2 раунде удаляется 2 карты)
        // а также карта которая должна уйти первой совпадает с раундом
        for (int j = 1; j <= size; j++) {
            cards.push(j);
        }

        while (!cards.empty()) {
            for (int j = 0; j < num_of_deleted_card; j++) {
                cards.push(cards.front());
                cards.pop();
            }
            result[cards.front() - 1] = num_of_deleted_card;
            num_of_deleted_card++; 
            cards.pop();
        }

        for (int j = 0; j < size; j++) {
            cout << result[j] << " ";
        }
        cout << "\n";
    }
    // суть в том что мы для каждого раунда находим индекс карты которая должна уйти (передняя карта)
    return 0;
}