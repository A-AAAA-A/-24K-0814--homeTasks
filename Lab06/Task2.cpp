#include <iostream>
#include <string>
using namespace std;

void merge(string names[], int times[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L_names[10], R_names[10];
    int L_times[10], R_times[10];

    for (int i = 0; i < n1; i++) {
        L_names[i] = names[left + i];
        L_times[i] = times[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R_names[j] = names[mid + 1 + j];
        R_times[j] = times[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L_times[i] <= R_times[j]) {
            names[k] = L_names[i];
            times[k] = L_times[i];
            i++;
        } else {
            names[k] = R_names[j];
            times[k] = R_times[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        names[k] = L_names[i];
        times[k] = L_times[i];
        i++;
        k++;
    }

    while (j < n2) {
        names[k] = R_names[j];
        times[k] = R_times[j];
        j++;
        k++;
    }
}

void mergeSort(string names[], int times[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(names, times, left, mid);
        mergeSort(names, times, mid + 1, right);
        merge(names, times, left, mid, right);
    }
}

int main() {
    const int n = 10;
    string names[n] = {
        "Borat", "Ahmed", "Dawood", "Shakir", "Usman",
        "Farooq", "Gujjar", "Chaman", "Ismail", "Jamal"
    };

    int times[n] = {360, 420, 390, 405, 375, 450, 395, 370, 410, 430};

    cout << "Original finish times:\n";
    for (int i = 0; i < n; i++)
        cout << names[i] << " - " << times[i] << "s\n";

    mergeSort(names, times, 0, n - 1);

    cout << "\nTop 5 Fastest Runners:\n";
    for (int i = 0; i < 5; i++)
        cout << i + 1 << ". " << names[i] << " - " << times[i] << "s\n";

    return 0;
}
