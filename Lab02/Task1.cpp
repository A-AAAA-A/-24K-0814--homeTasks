#include <iostream>

class DynamicArray {
private:
    int* arr;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    DynamicArray array;
    
    array.push_back(10);
    array.push_back(20);
    array.push_back(30); 
    array.push_back(40);

    array.print(); 

    return 0;
}
