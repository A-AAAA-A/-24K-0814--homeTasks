#include <iostream>
#include <string>

struct Employee {
    std::string name;
    int id;
    double salary;
};

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        
        if (L[i].salary >= R[j].salary) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void displayTopEmployees(Employee arr[], int size) {
    int count = (size < 3) ? size : 3;
    
    std::cout << "\nTop " << count << " Highest-Paid Employees (Sorted by Salary):\n";
    for (int i = 0; i < count; i++) {
        std::cout << "Name: " << arr[i].name 
                  << ", ID: " << arr[i].id 
                  << ", Salary: $" << arr[i].salary << "\n";
    }
}

int main() {
    Employee employees[] = {
        {"Alice", 101, 60000.00},
        {"Bob", 102, 75000.00},
        {"Charlie", 103, 50000.00},
        {"Diana", 104, 120000.00},
        {"Eve", 105, 95000.00},
        {"Frank", 106, 75000.00}, 
        {"Grace", 107, 45000.00},
        {"Henry", 108, 150000.00}, 
        {"Ivy", 109, 80000.00},
        {"Jack", 110, 62000.00},
        {"Kelly", 111, 125000.00},
        {"Liam", 112, 110000.00}
    };

    int n = sizeof(employees) / sizeof(employees[0]);

    std::cout << "Original Employee Data:\n";
    for(int i = 0; i < n; ++i) {
        std::cout << employees[i].name << " (" << employees[i].salary << ")\n";
    }

    mergeSort(employees, 0, n - 1);

    displayTopEmployees(employees, n);

    return 0;
}
