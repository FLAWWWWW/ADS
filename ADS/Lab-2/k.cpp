#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Node {
    public:
    string data;
    Node *next, *prev;

    Node(string data) {
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

    void push_back(string data) {
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

    void push_front(string data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            else 
                front = NULL;
        }
    }

    void pop_front() {
        if (front != NULL) {
            front = front->next;
            if (front != NULL)
                front->prev = NULL;
            else
                tail = NULL;
        }
    }

    void del_node(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == front) 
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    Node* find_node(string data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next; 
        }
        return NULL;
    }

    void insert_node(Node *node1, string data) {
        Node *node = new Node(data);
        if (node1 == tail) 
            push_back(data);
        else {
            Node *node2 = node1->next;
            node1->next = node;
            node->prev = node1;
            node->next = node2;
            node2->prev = node;
        }
    }

    bool contains(string x) {
        return find_node(x) != NULL;
    }
};

int main() {

    int t = 0, n = 0;
    string temp;
    cin >> t;

    while (t--) {
        LinkedList list;
        LinkedList duplicates;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> temp;
            if(!list.contains(temp) && !duplicates.contains(temp)){
                list.push_back(temp);
            }
            else if(list.contains(temp)) {
                list.del_node(list.find_node(temp));
                duplicates.push_back(temp);
            }

            if(list.front != NULL)
                cout << list.front->data << " ";
            if(list.tail == NULL)
                cout << -1 << " ";
        }
        cout << endl;
    }

    return 0;
}