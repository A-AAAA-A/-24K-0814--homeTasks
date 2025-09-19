#include <iostream>
using namespace std;

void interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while(low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if(arr[pos] == x) {
            cout << "Element found at index " << pos << endl;
            return;
        }
        if(arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    cout << "Element not found" << endl;
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 12, 15, 18, 20, 30, 34, 40, 45, 50, 60, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "Enter the element to search: ";
    cin >> x;

    interpolationSearch(arr, n, x);

    return 0;
}
