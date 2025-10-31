#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void displaySubtree(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    displaySubtree(root->left);
    displaySubtree(root->right);
}

long long getSubtreeSum(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + getSubtreeSum(root->left) + getSubtreeSum(root->right);
}

bool findSubtreeWithSum(Node* root, int targetSum, Node** resultRoot) {
    if (root == nullptr) {
        return false;
    }

    long long currentSum = getSubtreeSum(root);

    if (currentSum == targetSum) {
        *resultRoot = root;
        return true;
    }

    if (findSubtreeWithSum(root->left, targetSum, resultRoot)) {
        return true;
    }

    if (findSubtreeWithSum(root->right, targetSum, resultRoot)) {
        return true;
    }

    return false;
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(3);
    root->right->left = newNode(12);
    root->right->right = newNode(8);
    root->left->left->left = newNode(1);

    int targetSum = 10;
    Node* foundSubtreeRoot = nullptr;

    cout << "--- Warehouse Inventory Tree (Node = Item Count) ---" << endl;
    cout << "Target Total Quantity (Sum): **" << targetSum << "**" << endl;
    cout << "----------------------------------------------------" << endl;

    if (findSubtreeWithSum(root, targetSum, &foundSubtreeRoot)) {
        cout << "Subtree found whose total quantity equals " << targetSum << "." << endl;
        cout << "The nodes (inventory counts) in this subtree are (Pre-order Traversal): ";
        displaySubtree(foundSubtreeRoot);
        cout << endl;
    } else {
        cout << "No subtree found whose total quantity equals " << targetSum << "." << endl;
    }

    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
