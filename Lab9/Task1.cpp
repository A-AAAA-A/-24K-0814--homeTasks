#include <iostream>
using namespace std;

struct Node {
    int rollNumber;
    Node* left;
    Node* right;
    int height;
    Node(int roll) : rollNumber(roll), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, int rollNumber) {
    if (!node) return new Node(rollNumber);
    if (rollNumber < node->rollNumber)
        node->left = insert(node->left, rollNumber);
    else if (rollNumber > node->rollNumber)
        node->right = insert(node->right, rollNumber);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && rollNumber < node->left->rollNumber)
        return rightRotate(node);
    if (balance < -1 && rollNumber > node->right->rollNumber)
        return leftRotate(node);
    if (balance > 1 && rollNumber > node->left->rollNumber) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && rollNumber < node->right->rollNumber) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->rollNumber << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;
    int rollNumbers[] = {10, 20, 30, 40, 50};
    for (int roll : rollNumbers) {
        root = insert(root, roll);
    }
    root = insert(root, 15);
    inOrder(root);
    cout << endl;
    return 0;
}
