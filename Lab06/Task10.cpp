#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countSort(int arr[], int n, int exp) {
    int output[20];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    printArray(arr, n);
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int products[20] = {54321, 12345, 67890, 98765, 45612, 32145, 65432, 78901, 13579, 97531, 86420, 24680, 11223, 33445, 55667, 77889, 99000, 22334, 44556, 66778};
    int n = 20;
    cout << "Before Sorting:\n";
    printArray(products, n);
    cout << "\nDigit-by-digit Sorting:\n";
    radixSort(products, n);
    cout << "\nAfter Sorting:\n";
    printArray(products, n);
    return 0;
}
