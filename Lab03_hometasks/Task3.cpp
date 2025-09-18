#include<iostream>
using namespace std;

class CartItems{
public:
    int id;
    string itemName;
    int price;
    CartItems* prev;
    CartItems* next;
    
    CartItems(int iD, string name, int pric){
        id=iD;
        itemName=name;
        price=pric;
        prev=nullptr;
        next=nullptr;
    }
};

void insertAtHead(CartItems* &head, int id, string name, int price){
    if(head==nullptr){
        CartItems* temp= new CartItems(id,name,price);
        head=temp;
    }
    else{
        CartItems* temp=new CartItems(id,name,price);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }    
}

void insertAtEnd(CartItems* &head, int id, string name, int price){
    if(head==nullptr){
        CartItems* temp = new CartItems(id,name,price);
        head=temp;
    }
    else{
        CartItems* ItemToInsert= new CartItems(id,name,price);
        CartItems* temp=head;

        while(temp->next!=nullptr){
            temp=temp->next;
        }

        temp->next=ItemToInsert;
        ItemToInsert->prev=temp;
    }    
}

void removeFirst(CartItems* &head){
    if(head==nullptr){
        cout<<"List is empty, no item to remove!"<<endl;
        return;
    }
    else{
        CartItems* temp=head;
        head=head->next;
        if(head != nullptr) { 
            head->prev=nullptr;
        }
        temp->next=nullptr;
        delete temp;
    }
}

void removeLast(CartItems* &head){
    if(head==nullptr){
        cout<<"List is empty, no item to remove!"<<endl;
        return;
    }
    else if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    else{
        CartItems* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->prev->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    }
}

void searchByID(CartItems* &head, int id){
    CartItems* temp=head;
    while(temp!=nullptr){
        if(temp->id==id){
            cout<<"ID found: "<<temp->id<<"-"<<temp->itemName<<"-"<<temp->price<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"No item by this ID is found! "<<endl;
}

void updatePriceByID(CartItems* &head, int id, int newPrice){
    CartItems* temp=head;
    while(temp!=nullptr){
        if(temp->id==id){
            temp->price=newPrice;
            cout<<"price updated!"<<endl;
            cout<<"New price: "<<temp->id<<"-"<<temp->itemName<<"-"<<temp->price<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"No item by this ID is found! "<<endl;
}


void displayFromFrontToEnd(CartItems* head){
    if (head==nullptr) {
        cout<<"Cart is empty!"<<endl;
        return;
    }
    CartItems* temp=head;
    while(temp!=nullptr){
        cout<<temp->id<<"-"<<temp->itemName<<"-"<<temp->price<<"$ -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void displayFromEndToFront(CartItems* head){
    if (head==nullptr) {
        cout<<"Cart is empty!"<<endl;
        return;
    }

    CartItems* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    while (temp != nullptr) {
        cout<<temp->id<<"-"<<temp->itemName<<"-"<<temp->price<<"$ -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int totalItemsInCart(CartItems* &head){
    if(head==nullptr){
        return 0;
    }
    CartItems* temp=head;
    int count=0;
    while(temp!=nullptr){
        temp=temp->next;
        count++;
    }
    return count;
}

void mostExpensiveItem(CartItems* &head){
    if(head==nullptr){
        cout<<"No utems are there!"<<endl;
        return;
    }
    else{
        CartItems* temp=head;
        CartItems* expensive=head;
        while(temp!=nullptr){
            if(temp->price>expensive->price){
                expensive=temp;
            }
            temp=temp->next;
        }
        cout<<"Most expensive item: "<<expensive->id<<"-"<<expensive->itemName<<"-"<<expensive->price<<endl;
    }
}


int main(){

    CartItems* head=nullptr;

    cout<<"Inserting at head: "<<endl;
    insertAtHead(head,01,"Bread",30);
    insertAtHead(head,06,"Avacado",7);
    displayFromFrontToEnd(head);

    cout<<"Inserting at end: "<<endl;
    insertAtEnd(head,02,"Choclate",10);
    insertAtEnd(head,07,"Syrup",30);
    displayFromFrontToEnd(head);

    cout<<"Removing first and last item: "<<endl;
    removeFirst(head);
    removeLast(head);

    displayFromFrontToEnd(head);
    searchByID(head,02);
    updatePriceByID(head,02,20);
    

    cout<<"Cart from end to front: "<<endl;
    displayFromEndToFront(head);

    cout<<"Total Items in Cart are: "<<totalItemsInCart(head)<<endl;
    cout<<"Most expensive item is: "<<endl;
    mostExpensiveItem(head);
}    
