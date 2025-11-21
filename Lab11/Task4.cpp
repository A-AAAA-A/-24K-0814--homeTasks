#include <iostream>

using namespace std;

class Node {
public:
    int rollNo;
    string name;

    Node(int r,string n) : rollNo(r),name(n){}
};

class HashTable {
public:
    Node* arr[15];



    int hashing(string s){
		int sum = 0;
		for(int i=0; i<s.length(); i++){
			sum += (int)s[i];
		}
		return sum%100;
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
        for (int i = 0; i < 100; i++) {
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
