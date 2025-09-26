#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
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

    void push_back(int data) {
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

    void push_front(int data) {
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

    Node* find_node(int data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next; 
        }
        return NULL;
    }

    void insert_node(Node *node1, int data) {
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
};

int main() {

    LinkedList list;
    int n = 0, temp = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        list.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0){
            list.push_back(list.front->data); // переносим (оставляем) данные чётных индексов
        }   
        list.pop_front();
    }

    list.print();

    return 0;
}