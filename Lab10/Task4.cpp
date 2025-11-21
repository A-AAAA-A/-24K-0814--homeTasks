#include <iostream>
using namespace std;

class minHeap
{
public:
    int *arr;
    int capacity;
    int size;

    minHeap(int cap) : capacity(cap), size(0) {
        arr = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void heapify(int i)
    {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && arr[left] < arr[smallest])
        {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest])
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "heap is full" << endl;
            return;
        }

        arr[size] = val;
        size++;

        int i = size - 1;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void remove()
    {
        if (size <= 0)
        {
            cout << "heap is empty";
            return;
        }

        if (size == 1)
        {
            size--;
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        heapify(0);
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};


int main()
{
    minHeap h1(100);

    h1.insert(100);
    h1.insert(50);
    h1.insert(75);
    h1.insert(60);

    h1.print();

    h1.insert(55);
    h1.print();

    h1.remove();
    h1.print();
}
