#include <iostream>
#include <vector>

using namespace std;

// Ноде представляющий элемент дерева
class Node {
    public:
    int data;
    int count;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->count = 1;
        left = NULL;
        right = NULL;
    }
};

class BST{
    public:
    Node *root;
    BST() {
        root = NULL;
    }

    // Создание нового элемента дерева с заданным значением
    Node* create_tree_element(Node *root, int value){
        if(root == NULL)
            return new Node(value);
        if(value == root->data)
            root->count++;
        else if(value < root->data)
            root->left = create_tree_element(root->left, value);
        else
            root->right = create_tree_element(root->right, value);

        return root;
    }
    Node *findMax(Node *node) {
        if (node == NULL)
            return NULL;
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *deleteroot(Node *root, int data) {
        if (root == NULL)
            return NULL;
            
        if (data < root->data)
            root->left = deleteroot(root->left, data);
        else if (data > root->data)
            root->right = deleteroot(root->right, data);
        else {
            // Нашли элемент
            root->count--;
            
            // Если количество стало 0, удаляем узел
            if (root->count == 0) {
                if (root->right == NULL && root->left == NULL) {
                    delete root;
                    return NULL;
                } else if (root->left == NULL) {
                    Node *temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == NULL) {
                    Node *temp = root->left;
                    delete root;
                    return temp;
                } else {
                    Node *tmp = findMax(root->left);
                    root->data = tmp->data;
                    root->count = tmp->count;
                    // Устанавливаем count в 1 чтобы удалить только один экземпляр
                    tmp->count = 1;
                    root->left = deleteroot(root->left, tmp->data);
                }
            }
        }
        return root;
    }

    int count(Node *root, int value) {
        if (root == NULL)
            return 0;
            
        if (value == root->data)
            return root->count;
        else if (value < root->data)
            return count(root->left, value);
        else
            return count(root->right, value);
    }
};


int main(){

    int n = 0;
    int value = 0;
    cin >> n;
    BST *bst = new BST();

    string command;

    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "insert"){
            cin >> value;
            bst->root = bst->create_tree_element(bst->root, value);
        }
        else if(command == "delete"){
            cin >> value;
            bst->root = bst->deleteroot(bst->root, value);
        }
        else if(command == "cnt"){
            cin >> value;
            cout << bst->count(bst->root, value) << endl;
        }
    }



    return 0;
}