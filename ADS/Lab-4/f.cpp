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

    int countOfTriangles(Node *root){
        int count = 0;
        
        // Если текущий корень у нас пустой, то мы возвращаем 0
        if(root == NULL) return 0;

        // Если у нас есть левый или правый элемент, то мы считаем их количество треугольников
        if(root->left != NULL) count += countOfTriangles(root->left);
        if(root->right != NULL) count += countOfTriangles(root->right);

        // Если слева и справа есть элементы, то мы засчитываем как треугольник
        if(root->left != NULL && root->right != NULL) count += 1;

        return count;
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

    cout << bst->countOfTriangles(bst->root);

    return 0;
}