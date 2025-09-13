#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;


    Node(int val) : data(val), next(NULL){}
};

void listSort(Node* head) 
{
    if (!head) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

Node* mergelists(Node* list1, Node* list2) 
{
    if (!list1) return list2;
    if (!list2) return list1;

    Node* temp = list1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

Node* middleNode(Node* head) 
{
    if (!head) return NULL;
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void removeDuplicates(Node* head) 
{
    if (!head) return;
    Node* current = head;

    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

Node* mergeSortedlists(Node* list1, Node* list2) 
{
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->data < list2->data) {
        list1->next = mergeSortedlists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeSortedlists(list1, list2->next);
        return list2;
    }
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void freeList(Node* head)
{
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() 
{
    Node* head1 = new Node(3);
    head1->next = new Node(1);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(2);
    printList(head1);
    listSort(head1);
    printList(head1);

    Node* head2 = new Node(6);
    head2->next = new Node(5);
    printList(head2);
    Node* mergedHead = mergelists(head1, head2);
    printList(mergedHead);

    Node* mid = middleNode(mergedHead);
    cout << "Middle Node: " << mid->data << endl; 
    
    removeDuplicates(mergedHead);
    printList(mergedHead);

    Node* listA = new Node(1);  
    listA->next = new Node(3);
    listA->next->next = new Node(5);
    Node* listB = new Node(2);
    listB->next = new Node(4);
    Node* mergedList = mergeSortedlists(listA, listB);
    printList(mergedList);


    freeList(mergedHead);
    freeList(mergedList);

    return 0;
}
