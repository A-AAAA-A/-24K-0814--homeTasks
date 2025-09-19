#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            comparisons++;
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        comparisons++;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comparisons) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            comparisons++;
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

void shellSort(int arr[], int n, int &comparisons) {
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            comparisons++;
            while(j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
                comparisons++;
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[20] = {64, 34, 25, 12, 22, 11, 90, 15, 56, 17, 8, 67, 45, 23, 76, 38, 90, 56, 14, 72};

    int comparisons;

    cout << "Original Array: ";
    printArray(arr, 20);

    int arrCopy[20];
    for(int i = 0; i < 20; i++) arrCopy[i] = arr[i];

    comparisons = 0;
    bubbleSort(arrCopy, 20, comparisons);
    cout << "Bubble Sort: ";
    printArray(arrCopy, 20);
    cout << "Comparisons: " << comparisons << endl;

    for(int i = 0; i < 20; i++) arrCopy[i] = arr[i];
    comparisons = 0;
    insertionSort(arrCopy, 20, comparisons);
    cout << "Insertion Sort: ";
    printArray(arrCopy, 20);
    cout << "Comparisons: " << comparisons << endl;

    for(int i = 0; i < 20; i++) arrCopy[i] = arr[i];
    comparisons = 0;
    selectionSort(arrCopy, 20, comparisons);
    cout << "Selection Sort: ";
    printArray(arrCopy, 20);
    cout << "Comparisons: " << comparisons << endl;

    for(int i = 0; i < 20; i++) arrCopy[i] = arr[i];
    comparisons = 0;
    shellSort(arrCopy, 20, comparisons);
    cout << "Shell Sort: ";
    printArray(arrCopy, 20);
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}
