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

    void convertToGST(Node *root, int &sum){
        if(root == NULL) return;
        
        // Сначала обходим правое поддерево (большие значения)
        convertToGST(root->right, sum);
        
        // Сохраняем оригинальное значение и обновляем текущий корень
        int original_val = root->data;
        sum += original_val;
        root->data = sum;
        
        
        // Затем обходим левое поддерево (меньшие значения)
        convertToGST(root->left, sum);
    }
    
    void inOrderTraversal(Node *root) {
        if(root == NULL) return;
        
        inOrderTraversal(root->right);
        cout << root->data << " ";
        inOrderTraversal(root->left);
    }
    
    // Основная функция для преобразования и вывода
    void greaterSumTree() {
        int sum = 0;
        convertToGST(root, sum);
        inOrderTraversal(root);
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

    bst->greaterSumTree();

    return 0;
}