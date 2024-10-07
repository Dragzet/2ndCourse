#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void bfs(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

int sumLeaves(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return root->data;
    return sumLeaves(root->left) + sumLeaves(root->right);
}

int height(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void menu() {
    Node* root = nullptr;
    int choice, val;
    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Node\n";
        cout << "2. In-order\n";
        cout << "3. BFS\n";
        cout << "4. Leaves summ\n";
        cout << "5. Height\n";
        cout << "6. Exit\n";
        cout << "choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "value: ";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "In-order: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "BFS: ";
                bfs(root);
                cout << endl;
                break;
            case 4:
                cout << "summ: " << sumLeaves(root) << endl;
                break;
            case 5:
                cout << "height: " << height(root) << endl;
                break;
            case 6:
                exit(0);
            default:
                cout << "Choose again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
