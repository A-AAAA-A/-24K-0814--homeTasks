#include <iostream>
using namespace std;

int comparisons = 0;

int simpleRand(int& seed) {
    const int a = 1664525;
    const int c = 1013904223;
    const int m = 4294967296;
    seed = (a * seed + c) % m;
    return seed % m;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high, int pivotIndex) {
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int pivotChoice, int& seed) {
    if (low < high) {
        int pivotIndex = -1;
        if (pivotChoice == 1) pivotIndex = low;
        else if (pivotChoice == 2) pivotIndex = low + simpleRand(seed) % (high - low + 1);
        else if (pivotChoice == 3) pivotIndex = low + (high - low) / 2;
        else if (pivotChoice == 4) {
            int mid = low + (high - low) / 2;
            if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low])) pivotIndex = mid;
            else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid])) pivotIndex = low;
            else pivotIndex = high;
        }
        int pi = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pi - 1, pivotChoice, seed);
        quickSort(arr, pi + 1, high, pivotChoice, seed);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

void resetComparisons() {
    comparisons = 0;
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int seed = 123456789;

    cout << "Array before sorting:\n";
    printArray(arr, n);

    resetComparisons();
    cout << "\nSorting with First Element as pivot...\n";
    quickSort(arr, 0, n - 1, 1, seed);
    printArray(arr, n);
    cout << "Number of comparisons: " << comparisons << endl;

    resetComparisons();
    cout << "\nSorting with Random Element as pivot...\n";
    quickSort(arr, 0, n - 1, 2, seed);
    printArray(arr, n);
    cout << "Number of comparisons: " << comparisons << endl;

    resetComparisons();
    cout << "\nSorting with Middle Element as pivot...\n";
    quickSort(arr, 0, n - 1, 3, seed);
    printArray(arr, n);
    cout << "Number of comparisons: " << comparisons << endl;

    resetComparisons();
    cout << "\nSorting with Median of Three as pivot...\n";
    quickSort(arr, 0, n - 1, 4, seed);
    printArray(arr, n);
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}

