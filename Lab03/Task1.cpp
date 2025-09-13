#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node* next;

    Node(string val) : data(val), next(NULL) {}
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insertAtFront(string val) 
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(string val) 
    {
        Node* newNode = new Node(val);
        if (!head) 
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(string target, string val) 
    {
        Node* temp = head;
        while (temp && temp->data != target) 
        {
            temp = temp->next;
        }
        if (temp) 
        {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    Node* search(string target) 
    {
        Node* temp = head;
        while (temp) 
        {
            if (temp->data == target) 
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void display() 
    {
        Node* temp = head;
        while (temp) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


    ~LinkedList() 
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
    LinkedList list;
    list.insertAtFront("Deep Learning");
    list.insertAtEnd("Machine Learning");
    list.insertAfter("Artificial Intelligence", "Operating System");
    list.insertAfter("Operating System", "Cyber Security");
    list.insertAtEnd("Database systems");
    cout<<list.search("Database systems")->data<<endl;
    list.display(); 

    return 0;
}
