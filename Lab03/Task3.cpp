#include <iostream>
using namespace std;

class Node
{
public:
    string data;
    Node* next;
    Node* prev;

    Node(string val) : data(val), next(NULL), prev(NULL) {}
};

class railwaySystem
{
private:
    Node* head;
    Node* tail;

public:
    railwaySystem() : head(NULL), tail(NULL) {}

    void addCompartmentAtEnd(string val) 
    {
        Node* newNode = new Node(val);
        if (!head) 
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void removeCompartmentAtFront() 
    {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }

    Node* searchCompartmentBypostion(int position) 
    {
        Node* temp = head;
        int index = 0;
        while (temp && index < position-1) 
        {
            temp = temp->next;
            index++;
        }
        return temp;
    }

    void displayTrain() 
    {
        Node* temp = head;
        while (temp) 
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~railwaySystem() 
    {
        Node* temp;
        while (head) 
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() 
{
    railwaySystem train;
    train.addCompartmentAtEnd("Compartment 1");
    train.addCompartmentAtEnd("Compartment 2");
    train.addCompartmentAtEnd("Compartment 3");

    cout << "Current train configuration: \n";
    train.displayTrain();

    cout << "Removing compartment at front." << endl;
    train.removeCompartmentAtFront();
    train.displayTrain();

    int searchPosition = 1;
    Node* found = train.searchCompartmentBypostion(searchPosition);
    if (found) 
    {
        cout << "Found compartment at position " << searchPosition << ": " << found->data << endl;
    }
    else 
    {
        cout << "No compartment found at position " << searchPosition << endl;
    }

    return 0;

}
