#include <iostream>
using namespace std;

class maxHeap
{
public:
    int *arr;
    int capacity;
    int size;

    maxHeap(int cap) : capacity(cap), size(0)
    {
        arr = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void heapify(int i)
    {
        int large = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && arr[left]> arr[large])
        {
            large = left;
        }
        if (right < size && arr[right] > arr[large])
        {
            large = right;
        }

        if (large != i)
        {
            swap(arr[i], arr[large]);
            heapify(large);
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
        while (i != 0 && arr[parent(i)] < arr[i])
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
    maxHeap h1(100);

    h1.insert(1500);
    h1.insert(1200);
    h1.insert(1800);
    h1.insert(1600);
    h1.print();

    h1.insert(1700);
    h1.print();
    
    h1.remove();
    h1.print();
}
