#include <iostream>

using namespace std;

struct Employee {
    int id;
    Employee* left;
    Employee* right;
};

Employee* newEmployee(int id) {
    Employee* node = new Employee();
    node->id = id;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Employee* insertEmployee(Employee* root, int id) {
    if (root == nullptr) {
        return newEmployee(id);
    }

    if (id < root->id) {
        root->left = insertEmployee(root->left, id);
    } else if (id > root->id) {
        root->right = insertEmployee(root->right, id);
    }
    return root;
}

Employee* findLCA(Employee* root, int id1, int id2) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->id > id1 && root->id > id2) {
        return findLCA(root->left, id1, id2);
    }

    if (root->id < id1 && root->id < id2) {
        return findLCA(root->right, id1, id2);
    }

    return root;
}

void deleteTree(Employee* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Employee* root = nullptr;

    root = insertEmployee(root, 100); 
    root = insertEmployee(root, 50);
    root = insertEmployee(root, 150);
    root = insertEmployee(root, 40);
    root = insertEmployee(root, 60);
    root = insertEmployee(root, 120);
    root = insertEmployee(root, 180);

    int emp1 = 40;
    int emp2 = 60;
    Employee* lcaNode = findLCA(root, emp1, emp2);

    cout << "Employee Hierarchy LCA" << endl;
    cout << "Employees: " << emp1 << " and " << emp2 << endl;

    if (lcaNode) {
        cout << "Closest Common Manager (LCA) ID: **" << lcaNode->id << "**" << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    deleteTree(root);

    return 0;
}
