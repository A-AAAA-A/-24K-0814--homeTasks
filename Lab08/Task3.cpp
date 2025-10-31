#include <iostream>

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

bool isFullBinaryTree(Node* root) {
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

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    std::cout << "--- Game Level Tree Structure ---" << std::endl;
    std::cout << "Root: Level 1" << std::endl;
    std::cout << "Children of 1: Levels 2 (left) and 3 (right)" << std::endl;
    std::cout << "Children of 2: Levels 4 and 5" << std::endl;
    std::cout << "Children of 3: Levels 6 and 7" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    if (isFullBinaryTree(root)) {
        std::cout << "The created tree is a **Full Binary Tree**." << std::endl;
        std::cout << "This structure adheres to the rule that every node has either zero or two children, ensuring symmetrical gameplay progression." << std::endl;
    } else {
        std::cout << "The created tree is **NOT** a Full Binary Tree." << std::endl;
        std::cout << "A full binary tree requires every internal node to have exactly two children." << std::endl;
    }

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
