#include<iostream>
using namespace std;

class ShoppingCart{
public:
    string itemName;
    int price;
    ShoppingCart* next;

    //Constructor:
    ShoppingCart(string name, int pric){
        itemName=name;
        price=pric;
        next=nullptr;
    }
};

void insertAtFront(ShoppingCart* &head,ShoppingCart* &tail, string item, int price){
    ShoppingCart* temp=new ShoppingCart(item,price);
    if(head==nullptr){
        head=tail=temp;
        return;
    }
    temp->next=head;
    head=temp;
}

void insertAtEnd(ShoppingCart* &head,ShoppingCart* &tail, string item, int price){
    ShoppingCart* cartToInsert= new ShoppingCart(item,price);
    
    if (tail==nullptr){
        head=tail=cartToInsert;
        return;
    }

    tail->next=cartToInsert;
    tail=cartToInsert;
}

void insertAtposition(ShoppingCart* &head,ShoppingCart* &tail, int pos, string item, int price){
    if(pos==1){
        insertAtFront(head,tail,item,price);
        return;
    }
    int count=1;
    ShoppingCart* temp=head;

    while(count<pos-1){
        temp=temp->next;
        count++;
    }

    if(temp->next==nullptr){
        insertAtEnd(head,tail,item,price);
        return;
    }

    ShoppingCart* cartToInsert=new ShoppingCart(item,price);
    cartToInsert->next=temp->next;
    temp->next=cartToInsert;
}

void searchByName(ShoppingCart* &head, string name){
    ShoppingCart* temp=head;
    int pos=1;
    while(temp!=nullptr){
        if(temp->itemName==name){
            cout<<"Item found at position: "<<pos<<endl<<"Item name: "<<temp->itemName<<" Item Price: "<<temp->price<<endl;
            return;
        }
        pos++;
        temp=temp->next;
    }
    cout<<"Item named: "<<name<<" is not found in the list."<<endl;
}

void searchByPosition(ShoppingCart* head, int pos){
    if(pos<=0){
        cout<<"Invalid position!"<<endl;
        return;
    }
    ShoppingCart* temp = head;
    int count = 1;

    while(temp != nullptr && count<pos) {
        temp=temp->next;
        count++;
    }

    if(temp==nullptr){
        cout<<"Position out of range!"<<endl;
    }
    else{
        cout<<"Item at position "<<pos<<": "<<temp->itemName<<" - $"<<temp->price<<endl;
    }
}


void deleteFront(ShoppingCart* &head,ShoppingCart* &tail){
    if(head == nullptr){ 
        return;
    }     
    ShoppingCart* temp=head;
    head=head->next;
    if(head == nullptr) {
        tail = nullptr;
    }    
    delete temp;
}

void display(ShoppingCart* &head){
    ShoppingCart* temp=head;
    while(temp!=nullptr){
        cout<<temp->itemName<<"- $"<<temp->price<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}


int main(){
    ShoppingCart* head=nullptr;
    ShoppingCart* tail=nullptr;

    insertAtFront(head,tail,"iPad",10);
    insertAtFront(head,tail,"tablet",400);
    insertAtFront(head,tail,"Phone",700);
    insertAtFront(head,tail,"Laptop",1000);

    insertAtFront(head,tail,"SmartWatch",200);

    insertAtEnd(head,tail,"Keyboard",80);

    insertAtposition(head,tail,4,"Monitor",300);

    searchByName(head,"tablet");

    cout<<endl<<"Complete shopping cart: "<<endl;
    display(head);

    cout<<"Deleting item from front: "<<endl;
    deleteFront(head,tail);
    display(head);

    searchByPosition(head,3);

}
