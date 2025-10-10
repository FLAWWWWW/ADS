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

    void prePrint(Node *root) {
        // Если дерево пустое, то ничего не выводим и вообще выходим из функции
        if(root == NULL)
            return;

        // Выводим сначала рут, а там уже двигаемся влево, вправо и тоже выводим, если они есть
        cout << root->data << " ";
        prePrint(root->left);
        prePrint(root->right);
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

    // Вызов функции вывода и внутри него поиска нужного элемента
    cin >> x;
    bst->prePrint(bst->find(bst->root, x));

    return 0;
}