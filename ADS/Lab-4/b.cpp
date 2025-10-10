#include <iostream>

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
        if(value <= root->data)
            root->left = create_tree_element(root->left, value);
        else
            root->right = create_tree_element(root->right, value);

        return root;
    }

    // Поиск элемента в дереве с которого мы будем искать количество в size
    Node *find(Node *root, int value){
        // возвращаем элемент с заданным значением. Если не нашёлся, то вернём NULL, а если нашёлся, то вернём найденный элемент
        if(root == NULL || root->data == value)
            return root;

        // Это чтобы двигаться по дереву в зависимости от того значение наше меньше или больше (чтобы понимать, влево нам или направо)
        if(value < root->data)
            return find(root->left, value);
        else
            return find(root->right, value);
    }

    int size(Node *root){
        // Если у нас не получилось найти элемент, то вернём 0
        if(root == NULL)
            return 0;
        // Если получилось найти, то тогда мы вернём количество, которое вычисляется как: (левый элемент, если он есть + правый элемент, если он есть + 1, это и есть наш сам элемент root)
        return size(root->left) + size(root->right) + 1;
    }
};


int main(){

    int n = 0, x = 0;
    cin >> n;
    string path;
    BST *bst = new BST();

    // Создание элементов дерева
    for(int i = 0; i < n; i++){
        int value = 0;
        cin >> value;
        bst->root = bst->create_tree_element(bst->root, value);
    }

    // Вызов функции калькулятора и внутри него поиска нужного элемента
    cin >> x;
    cout << bst->size(bst->find(bst->root, x)) << endl;

    return 0;
}