#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
    public:
    pair<int, int> data;
    Node *next, *prev;

    Node(pair<int, int> data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *tail, *front;

    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(pair<int, int> data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    Node* find_node(int value) {
        Node *node = front;
        while (node != NULL) {
            if (node->data.first == value)
                return node;
            node = node->next;
        }
        return NULL;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    LinkedList list;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (list.find_node(nums[i]) == NULL) {
            list.push_back({nums[i], 0});
        }
    }

    for (int i = 0; i < n; i++) {
        Node* node = list.find_node(nums[i]);
        if (node != NULL) {
            node->data.second++;
        }
    }

    int maxFreq = 0;
    Node* cur = list.front;
    while (cur != NULL) {
        if (cur->data.second > maxFreq)
            maxFreq = cur->data.second;
        cur = cur->next;
    }

    vector<int> modes;
    cur = list.front;
    while (cur != NULL) {
        if (cur->data.second == maxFreq)
            modes.push_back(cur->data.first);
        cur = cur->next;
    }

    sort(modes.rbegin(), modes.rend());

    for (int x : modes) {
        cout << x << " ";
    }

    return 0;
}
