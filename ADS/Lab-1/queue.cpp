#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
public:
    Node* front;
    Node* tail;
    int sz;

    Queue() {
        front = NULL;
        tail = NULL;
        sz = 0;
    }

    void push(int data) {
        Node* node = new Node(data);
        if (tail == NULL) { 
            front = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        sz++;
    }

    void pop() {
        if (front != NULL) {
            Node* temp = front;
            front = front->next;
            if (front == NULL) {
                tail = NULL;
            }
            delete temp;
            sz--;
        }
    }

    int front() {
        if (front != NULL) {
            return front->data;
        }
        return -1;
    }

    int size() {
        return this->sz;
    }

    bool empty() {
        return (sz == 0);
    }
};