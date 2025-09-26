#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p) {
    if (p == 0) {
        node->next = head;
        head = node;
        return head;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1; i++) {
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    return head;
}

Node* remove(Node* head, int p) {
    if (!head)
    {
        return nullptr;
    };
    if (p == 0) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1; i++) {
        cur = cur->next;
    }
    Node* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    return head;
}

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2){
        return head;
    };
    Node* node;
    if (p1 == 0) {
        node = head;
        head = head->next;
    } else {
        Node* cur = head;
        for (int i = 0; i < p1 - 1; i++) cur = cur->next;
        node = cur->next;
        cur->next = node->next;
    }
    node->next = nullptr;
    head = insert(head, node, p2);
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

void print(Node* head) {
    if (!head) {
        cout << -1 << endl;
        return;
    }
    Node* cur = head;
    while (cur) {
        cout << cur->val;
        if (cur->next) cout << " ";
        cur = cur->next;
    }
    cout << endl;
}

int length(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* cyclic_left(Node* head, int x) {
    int n = length(head);
    if (n == 0 || x % n == 0) {
        return head;
    };
    x %= n;
    Node* cur = head;
    for (int i = 0; i < x - 1; i++) cur = cur->next;
    Node* newHead = cur->next;
    cur->next = nullptr;
    Node* tail = newHead;
    while (tail->next) {
        tail = tail->next;
    };
    tail->next = head;
    return newHead;
}

Node* cyclic_right(Node* head, int x) {
    int n = length(head);
    if (n == 0 || x % n == 0) {
        return head;
    };
    x %= n;
    return cyclic_left(head, n - x);
}

int main() {
    Node* head = nullptr;
    while (true) {
        int command;
        cin >> command;
        if (command == 0) {
            break;
        } else if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        } else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}