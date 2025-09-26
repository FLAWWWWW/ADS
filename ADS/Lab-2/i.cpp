#include <iostream>
#include <string>
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
        cout << "ok" << endl;
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
        cout << "ok" << endl;
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
};


int main() {
    LinkedList list;
    string command, data;

    while (true) {
        cin >> command;

        if (command == "add_front") {
            cin >> data;
            list.push_front(data);
        } 
        else if (command == "add_back") {
            cin >> data;
            list.push_back(data);
        } 
        else if (command == "erase_front") {
            if (list.front != NULL) {
                cout << list.front->data << endl;
                list.pop_front();
            } else {
                cout << "error" << endl;
            }
        } 
        else if (command == "erase_back") {
            if (list.tail != NULL) {
                cout << list.tail->data << endl;
                list.pop_back();
            } else {
                cout << "error" << endl;
            }
        } 
        else if (command == "front") {
            if (list.front != NULL)
                cout << list.front->data << endl;
            else
                cout << "error" << endl;
        } 
        else if (command == "back") {
            if (list.tail != NULL)
                cout << list.tail->data << endl;
            else
                cout << "error" << endl;
        } 
        else if (command == "clear") {
            list.front = NULL;
            list.tail = NULL;
            cout << "ok" << endl;
        } 
        else if (command == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }

    return 0;
}
