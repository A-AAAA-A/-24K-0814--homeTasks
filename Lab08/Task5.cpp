#include <iostream>

using namespace std;

struct Product {
    int id;
    int quantity;
    Product* left;
    Product* right;
};

Product* newProduct(int id, int quantity) {
    Product* node = new Product();
    node->id = id;
    node->quantity = quantity;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Product* insertOrUpdate(Product* root, int id, int quantity) {
    if (root == nullptr) {
        return newProduct(id, quantity);
    }

    if (id < root->id) {
        root->left = insertOrUpdate(root->left, id, quantity);
    } else if (id > root->id) {
        root->right = insertOrUpdate(root->right, id, quantity);
    } else {
        root->quantity = quantity;
    }
    return root;
}

Product* searchProduct(Product* root, int id) {
    if (root == nullptr || root->id == id) {
        return root;
    }

    if (id < root->id) {
        return searchProduct(root->left, id);
    } else {
        return searchProduct(root->right, id);
    }
}

struct MaxProduct {
    Product* node = nullptr;
    int maxQuantity = -1;
};

void findMaxQuantity(Product* root, MaxProduct& maxProd) {
    if (root == nullptr) {
        return;
    }

    if (root->quantity > maxProd.maxQuantity) {
        maxProd.maxQuantity = root->quantity;
        maxProd.node = root;
    }

    findMaxQuantity(root->left, maxProd);
    findMaxQuantity(root->right, maxProd);
}

void deleteTree(Product* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Product* inventoryRoot = nullptr;

    inventoryRoot = insertOrUpdate(inventoryRoot, 101, 50);
    inventoryRoot = insertOrUpdate(inventoryRoot, 50, 20);
    inventoryRoot = insertOrUpdate(inventoryRoot, 150, 80);
    inventoryRoot = insertOrUpdate(inventoryRoot, 75, 10);
    inventoryRoot = insertOrUpdate(inventoryRoot, 125, 120);

    inventoryRoot = insertOrUpdate(inventoryRoot, 150, 200);

    cout << "Retailer Product Tracking" << endl;

    int searchID = 125;
    Product* result = searchProduct(inventoryRoot, searchID);
    if (result) {
        cout << "Search ID " << searchID << ": Qty " << result->quantity << endl;
    } else {
        cout << "Product ID " << searchID << " not found." << endl;
    }

    MaxProduct maxFinder;
    findMaxQuantity(inventoryRoot, maxFinder);

    if (maxFinder.node) {
        cout << "Highest Quantity Product ID: " << maxFinder.node->id << ", Qty: " << maxFinder.maxQuantity << endl;
    } else {
        cout << "Inventory is empty." << endl;
    }

    deleteTree(inventoryRoot);

    return 0;
}
