#include <iostream>
using namespace std;

struct Node {
    int val, height;
    Node *left, *right;
    Node(int v) { val = v; height = 1; left = right = nullptr; }
};

int h(Node* n) { return n ? n->height : 0; }

int balance(Node* n) { return n ? h(n->left) - h(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}

Node* insert(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->val) root->left = insert(root->left, v);
    else if (v > root->val) root->right = insert(root->right, v);
    else return root;

    root->height = 1 + max(h(root->left), h(root->right));
    int b = balance(root);

    if (b > 1 && v < root->left->val) return rightRotate(root);
    if (b < -1 && v > root->right->val) return leftRotate(root);
    if (b > 1 && v > root->left->val) { root->left = leftRotate(root->left); return rightRotate(root); }
    if (b < -1 && v < root->right->val) { root->right = rightRotate(root->right); return leftRotate(root); }

    return root;
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->val << " ";
    inorder(r->right);
}

void printBalances(Node* r) {
    if (!r) return;
    printBalances(r->left);
    cout << "Node " << r->val << " BF=" << balance(r) << endl;
    printBalances(r->right);
}

int main() {
    Node* root = nullptr;
    int a[] = {10,5,15,3,7};
    for (int x : a) root = insert(root, x);

    root = insert(root, 12);

    cout << "Balance Factors:" << endl;
    printBalances(root);

    cout << "Tree Height: " << h(root) << endl;

    cout << "Final AVL (Inorder): ";
    inorder(root);
    cout << endl;
}
