#include <iostream>
#include <queue>

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

    int getHeight(Node *root) {
        // Если дерево пустое, то возвращаем 0
        if (root == NULL)
            return 0;
        // Добавляем текущий уровень и проверяем слева и справа есть ли уровни, они добавятся, если есть хотя бы одно (для этого у нас max)
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void sumOfTree(Node *root){
        // Идея: добавлять в очередь корни дерева и в последствии их удалять
        // Мы берём корни дерева, чтобы взять их левый и правый элементы
        queue<Node*> q;
        if(root != NULL)
            q.push(root);
        
        // Пока у нас есть корни
        while(!q.empty()){
            int sum = 0;
            // Нам нужно понять со сколькими корнями мы работаем, чтобы у каждого взять правый и левый элемент
            int s = q.size();
            while(s--){
                Node *cur = q.front();
                // Тут мы добавляем в очередь наши последующие корни, которые сейчас являются правом и левом текущего корня
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
                // Удаляем текущий корень
                q.pop();
                sum += cur->data;
            }
            cout << sum << " ";
        }
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

    // Выводим количество уровней
    int k = bst->getHeight(bst->root);
    cout << k << " ";
    
    // Выводим сумму для каждого уровня
    bst->sumOfTree(bst->root);

    return 0;
}