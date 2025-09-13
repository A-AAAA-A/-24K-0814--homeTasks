#include <iostream>
using namespace std;
class Node
{
public:
    string data;
    Node* next;

    Node(string val) : data(val), next(NULL) {}
};

class libraryCatelog
{
private:
    Node* head;

public:
    libraryCatelog() : head(NULL) {}

    void addAtTail(string val) 
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

    void removeBook(string target) 
    {
        if (!head) return;
        if (head->data == target) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (curr && curr->data != target) 
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr) 
        {
            prev->next = curr->next;
            delete curr;
        }
    }

    Node* searchBookByTitle(string target) 
    {
        Node* temp = head;
        while (temp && temp->data != target) 
        {
            temp = temp->next;
        }
        return temp;
    }

    Node* searchBookByPosition(int position) 
    {
        Node* temp = head;
        int index = 0;
        while (temp && index < position) 
        {
            temp = temp->next;
            index++;
        }
        return temp;
    }
    void displayCatalog() 
    {
        Node* temp = head;
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout<<endl;
    }

    ~libraryCatelog() 
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
    libraryCatelog catalog;
    catalog.addAtTail("The Great Gatsby");
    catalog.addAtTail("1984");
    catalog.addAtTail("To Kill a Mockingbird");

    cout << "Catalog after adding books:" << endl;
    catalog.displayCatalog();

    string searchTitle = "1984";
    Node* foundBook = catalog.searchBookByTitle(searchTitle);
    if (foundBook) 
    {
        cout << "Found book: " << foundBook->data << endl;
    } 
    else 
    {
        cout << "Book not found: " << searchTitle << endl;
    }

    int position = 1;
    Node* bookAtPosition = catalog.searchBookByPosition(position);
    if (bookAtPosition) 
    {
        cout << "Book is at position " << position << ": " << bookAtPosition->data << endl;
    } 
    else 
    {
        cout << "No book found at position " << position << endl;
    }

    catalog.removeBook("1984");
    cout << "Catalog after removing '1984':" << endl;
    catalog.displayCatalog();

    return 0;
}
