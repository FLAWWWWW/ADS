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

class BST {
    public:
        Node *root;
        BST() {
            root = NULL;
        }

        // Создание нового элемента дерева с заданным значением
        Node* create_tree_element(Node *root, int value, int z) {
            if (root == NULL)
                return new Node(value);

            if (z == 0 && root->left == NULL)
                root->left = new Node(value);
            else if (z == 1 && root->right == NULL)
                root->right = new Node(value);

            return root;
        }

        int countOfTree(Node *root) {
            if (root == NULL) return 0;

            // Идея: добавлять в очередь корни дерева и в последствии их удалять
            // Мы берём корни дерева, чтобы взять их левый и правый элементы
            queue<Node*> q;
            q.push(root);

            // Наша максимальная ширина
            int max_count = 0;

            while (!q.empty()) {
                int level_width = q.size();
                // Если у нас текущая ширина больше, чем максимальная, то заменяем
                max_count = max(max_count, level_width);

                // Тут мы хотим взять все последующие корни в текущей ширине
                for (int i = 0; i < level_width; ++i) {
                    Node *cur = q.front(); q.pop();
                    if (cur->left) q.push(cur->left);
                    if (cur->right) q.push(cur->right);
                }
            }

            return max_count;
        }

        Node *find(Node *root, int value) {
            if (root == NULL || root->data == value)
                return root;

            Node *leftResult = find(root->left, value);
            if (leftResult != NULL) return leftResult;

            return find(root->right, value);
        }
};

int main() {
    int n = 0, x = 0, y = 0, z = 0;
    cin >> n;

    // Создание элементов дерева, где x у нас отвечает за отца (мы его ищем через find)
    // y - значение, z - левый или правый сын
    BST *bst = new BST();
    bst->root = bst->create_tree_element(bst->root, 1, 0); 

    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y >> z;
        Node* parent = bst->find(bst->root, x);
        bst->create_tree_element(parent, y, z);
    }

    // Выводим максимальную ширину
    cout << bst->countOfTree(bst->root);

    return 0;
}