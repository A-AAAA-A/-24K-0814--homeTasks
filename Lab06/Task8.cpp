#include <iostream>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    double totalPrice;
};

void swap(Order &a, Order &b) {
    Order temp = a;
    a = b;
    b = temp;
}

int partition(Order arr[], int low, int high) {
    double pivot = arr[high].totalPrice;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].totalPrice < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Order arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Order orders[5] = {
        {101, "Alice", 250.50},
        {102, "Bob", 120.75},
        {103, "Charlie", 300.00},
        {104, "David", 180.20},
        {105, "Eve", 220.10}
    };
    int n = 5;
    quickSort(orders, 0, n - 1);
    cout << "Sorted Orders (by Total Price):\n";
    for (int i = 0; i < n; i++)
        cout << "OrderID: " << orders[i].orderID << "  Name: " << orders[i].customerName << "  Total: " << orders[i].totalPrice << endl;
    return 0;
}
