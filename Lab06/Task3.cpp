#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    float price;
    string description;
    bool available;
};

void swap(Product &a, Product &b) {
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price; 
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int n = 3;
    Product products[n];

    cout << "Enter details for 3 products:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, products[i].name);

        cout << "Price: ";
        cin >> products[i].price;
        cin.ignore();

        cout << "Description: ";
        getline(cin, products[i].description);

        cout << "Available (1 for Yes, 0 for No): ";
        cin >> products[i].available;
        cin.ignore();
    }

    quickSort(products, 0, n - 1);

    cout << "\nProducts sorted by price (ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        cout << "Name: " << products[i].name << endl;
        cout << "Price: $" << products[i].price << endl;
        cout << "Description: " << products[i].description << endl;
        cout << "Availability: " << (products[i].available ? "In Stock" : "Out of Stock") << endl;
    }

    return 0;
}
