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
        if(value <= root->data)
            root->left = create_tree_element(root->left, value);
        else
            root->right = create_tree_element(root->right, value);

        return root;
    }

    // Мистер проверяющий путь
    bool check_tree(Node* cur_elem, string path){
        for(char c : path){
            // Если слева или справа есть поддерево, то мы двигаемся туда, если окажется, что пусто, то возвращаем false
            if(c == 'L' && cur_elem->left != NULL) cur_elem = cur_elem->left;
            else if(c == 'R' && cur_elem->right != NULL) cur_elem = cur_elem->right;
            else return false;
        }
        // Это если путь закончился, но мы так и не нашли пустоты и возвращаем true
        return true;
    }
};

int main(){

    int n = 0, m = 0;
    cin >> n >> m;
    string path;
    BST *bst = new BST();

    // Создание элементов дерева
    for(int i = 0; i < n; i++){
        int value = 0;
        cin >> value;
        bst->root = bst->create_tree_element(bst->root, value);
    }

    // Ввод наших путей и их проверка
    for(int i = 0; i < m; i++){
        cin >> path;
        if(bst->check_tree(bst->root, path)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}