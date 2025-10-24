#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

Node* getTail(Node* head) {
    if (head == nullptr) return nullptr;
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

void cleanupList(Node* head) {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

Node* partition(Node* head, Node* end, Node*& newHead, Node*& newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* current = head;
    Node* tail = pivot;

    while (current != pivot) {
        if (current->data < pivot->data) {
            if (newHead == nullptr) {
                newHead = current;
            }
            prev = current;
            current = current->next;
        } else { 
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            tail->next = current;
            tail = current;
            current->next = nullptr;
            current = temp;
        }
    }

    if (newHead == nullptr) {
        newHead = pivot;
    }
    
    newEnd = tail; 

    return pivot;
}

Node* quickSortRec(Node* head, Node* end) {
    if (head == nullptr || head == end || head->next == end) {
        return head;
    }

    Node* newHead = nullptr;
    Node* newEnd = nullptr;

    Node* pivot = partition(head, end, newHead, newEnd);
    
    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr; 

        newHead = quickSortRec(newHead, temp);

        getTail(newHead)->next = pivot;
    }

    pivot->next = quickSortRec(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node*& head) {
    if (!head || !head->next) {
        return;
    }
    Node* tail = getTail(head);
    head = quickSortRec(head, tail);
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(7);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(3);

    std::cout << "Original List: ";
    displayList(head);

    quickSort(head);

    std::cout << "Sorted List: ";
    displayList(head);
    
    cleanupList(head);

    return 0;
}
