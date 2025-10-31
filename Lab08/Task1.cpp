#include <iostream>
using namespace std;

struct Node {
    string packageName;
    Node* left;
    Node* right;
    Node(string name) {
        packageName = name;
        left = right = NULL;
    }
};

Node* createPackage(string name) {
    Node* newNode = new Node(name);
    return newNode;
}

void displayTree(Node* root, int space = 0, int height = 5) {
    if (root == NULL) return;
    space += height;
    displayTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";
    cout << root->packageName << "\n";
    displayTree(root->left, space);
}

int main() {
    Node* root = createPackage("World Tours");
    root->left = createPackage("Clifton Tours");
    root->right = createPackage("DHA Tours");
    root->left->left = createPackage("Bhens Colony Tour");
    root->left->right = createPackage("Murree Tour");
    root->right->left = createPackage("Kashmir Tour");
    root->right->right = createPackage("Gilgit Tour");
    cout << "Tour Package Hierarchy:\n";
    displayTree(root);
    return 0;
}
