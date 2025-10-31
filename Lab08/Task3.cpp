#include <iostream>

using namespace std;

struct GameNode {
    int data;
    GameNode* left;
    GameNode* right;
};

GameNode* newGameNode(int data) {
    GameNode* node = new GameNode();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool isFullBinaryTree(GameNode* root) {
    if (root == nullptr) {
        return true;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }

    if (root->left && root->right) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }

    return false;
}

void deleteTree(GameNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    GameNode* root = newGameNode(1);
    root->left = newGameNode(2);
    root->right = newGameNode(3);
    root->left->left = newGameNode(4);
    root->left->right = newGameNode(5);
    root->right->left = newGameNode(6);
    root->right->right = newGameNode(7);

    cout << "--- Game Level Tree Check ---" << endl;
    cout << "Created a sample tree." << endl;

    if (isFullBinaryTree(root)) {
        cout << "Result: **Full Binary Tree** confirmed." << endl;
    } else {
        cout << "Result: **NOT** a Full Binary Tree." << endl;
    }

    deleteTree(root);

    return 0;
}
