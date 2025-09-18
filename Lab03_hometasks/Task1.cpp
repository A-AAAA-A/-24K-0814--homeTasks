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

//Inserting At Front:
void insertAtFront(ShoppingCart* &head, string item, int price){
    ShoppingCart* temp=new ShoppingCart(item,price);
    temp->next=head;
    head=temp;
}

//Insert at End:
void insertAtEnd(ShoppingCart* &head, string item, int price){
    ShoppingCart* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }

    ShoppingCart* cartToInsert= new ShoppingCart(item,price);
    temp->next=cartToInsert;
    cartToInsert->next=nullptr;
}

void insertAtposition(ShoppingCart* &head, int pos, string item, int price){
    if(pos==1){
        insertAtFront(head,item,price);
        return;
    }
    int count=1;
    ShoppingCart* temp=head;

    while(count<pos-1){
        temp=temp->next;
        count++;
    }

    if(temp->next==nullptr){
        insertAtEnd(head,item,price);
        return;
    }

    ShoppingCart* cartToInsert=new ShoppingCart(item,price);
    cartToInsert->next=temp->next;
    temp->next=cartToInsert;
}

void search(ShoppingCart* &head, string name){
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

    insertAtFront(head,"iPad",10);
    insertAtFront(head,"tablet",400);
    insertAtFront(head,"Phone",700);
    insertAtFront(head,"Laptop",1000);

    insertAtFront(head,"SmartWatch",200);

    insertAtEnd(head,"Keyboard",80);

    insertAtposition(head,4,"Monitor",300);

    search(head,"tablet");

    cout<<endl<<"Complete shopping cart: "<<endl;
    display(head);
    
}
