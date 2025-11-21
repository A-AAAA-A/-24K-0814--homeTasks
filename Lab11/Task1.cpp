#include <iostream>

using namespace std;

class Node {
public:
    string key;
    Node* next;

    Node(string key) : key(key), next(NULL) {}
};

class HashTable {
public:
    Node* arr[10];

    HashTable() {
        for (int i = 0; i < 10; i++)
            arr[i] = NULL;
    }

    int hashing(string s){
		int sum = 0;
		for(int i=0; i<s.length(); i++){
			sum += (int)s[i];
		}
		return sum%10;
	}

    void insert(string s){
        Node *nn = new Node(s);
        int index = hashing(s);

        if(arr[index] == nullptr){
            arr[index] = nn;
        }
        else{
            Node* temp = arr[index];
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
        

    void display() {
        for (int i = 0; i < 10; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = arr[i];
            while (temp != NULL) {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable table;
    table.insert("apple");
    table.insert("banana");
    table.insert("mango");
    table.insert("grapes");
    table.insert("apple");
    table.insert("peach");
    table.display();
}
