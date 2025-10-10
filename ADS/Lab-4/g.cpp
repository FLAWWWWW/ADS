#include <iostream>
#include <vector>

using namespace std;

// Ноде представляющий элемент дерева
class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
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
        // МЫ НЕ ДОБАВЛЯЕМ ДУБЛИКАТЫ
        if(value < root->data)
            root->left = create_tree_element(root->left, value);
        else if (value > root->data)
            root->right = create_tree_element(root->right, value);

        return root;
    }

    int heightAndUpdateDiameter(Node* node, int& diameter) { // мы передаём так диаметр, чтобы он у нас менялся
        if (node == nullptr) return 0;
        
        // Ищем диаменты слева и справа
        int left = heightAndUpdateDiameter(node->left, diameter);
        int right = heightAndUpdateDiameter(node->right, diameter);
        
        // Меняем текущий диаметр, если новый больше
        diameter = max(diameter, left + right);
        
        return 1 + max(left, right);
    }

    int findDistance(Node *root){
        int diameter = 0;
        heightAndUpdateDiameter(root, diameter);
        return diameter + 1;
    }
};


int main(){

    int n = 0;
    cin >> n;
    BST *bst = new BST();

    // Создание элементов дерева
    for(int i = 0; i < n; i++){
        int value = 0;
        cin >> value;
        bst->root = bst->create_tree_element(bst->root, value);
    }

    cout << bst->findDistance(bst->root);

    return 0;
}