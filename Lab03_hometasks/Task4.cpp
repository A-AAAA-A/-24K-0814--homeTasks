#include<iostream>
using namespace std;

class Ticket{
public:
    int ticketID;
    string customerName;
    string rideName;
    Ticket* next;
    
    Ticket(int id, string name, string ride){
        ticketID=id;
        customerName=name;
        rideName=ride;
        next=nullptr;
    }
};

void insertAtFront(Ticket* &head,Ticket* &tail, int id, string name, string ride){
    Ticket* ticketToInsert=new Ticket(id,name,ride);
    if(head==nullptr){
        tail=head=ticketToInsert;
        tail->next=head;
    }
    else{
        tail->next=ticketToInsert;
        ticketToInsert->next=head;
        head=ticketToInsert;
    }
}

void insertAtEnd(Ticket* &head, Ticket* &tail, int id, string name, string ride){
    Ticket* ticketToInsert= new Ticket(id,name,ride);

    if(head==nullptr && tail==nullptr){
        head=tail=ticketToInsert;
        tail->next=head;
    }
    else{
        ticketToInsert->next=tail->next;
        tail->next=ticketToInsert;
        tail=ticketToInsert;
    }
}

void CancelTicketByID(Ticket*  &head, Ticket* &tail, int id){

    if(head==nullptr){
        cout<<"List is empty nothing to delete!"<<endl;
        return;
    }
    int pos=1;
    Ticket* temp=head;
    do{
        if(temp->ticketID==id){
            break;
        }
        pos++;
        temp=temp->next;
    }
    while(temp!=head);

    if(pos==1){
        Ticket* temp=head;
        if(head==tail){
            head=tail=nullptr;

        }
        else{
            head=head->next;
            tail->next=head;
        }
        temp->next=nullptr;
        delete temp;
        return;
    }

    Ticket* prev=head;
    int count=1;

    while(count<pos-1 && prev->next!=head){
        prev=prev->next;
        count++;
    }

    if(prev->next==head){
        cout<<"Position is out of range!"<<endl;
        return;
    }

    Ticket* ticketTodelete=prev->next;

    if(ticketTodelete==tail){
        tail=prev;
    }

    prev->next=ticketTodelete->next;
    ticketTodelete->next=nullptr;
    delete ticketTodelete;
}

void cancelFirstTicket(Ticket* &head, Ticket* &tail){
    Ticket* temp=head;
    if(head==nullptr){
        cout<<"List is empty!"<<endl;
        return;
    }
    else if(head==tail){
        head=tail=nullptr;
        delete temp;
    }
    else{
        tail->next=head->next;
        head=head->next;
        delete temp;
    }
}

void searchById(Ticket* &head, int id){
    Ticket* temp=head;
    do{
        if(temp->ticketID==id){
            cout<<"Ticket found: "<<temp->ticketID<<"-"<<temp->customerName<<"-"<<temp->rideName<<endl;
            return;
        }
        temp=temp->next;
    }
    while(temp!=head);
    cout<<"No ticket with ID: "<<id<<" is found in the list."<<endl;
}


int totalTickets(Ticket* &head){
    Ticket* temp=head;
    if(head==nullptr){
        return 0;
    }
    else{
        int count=0;
        do{
            count++;
            temp=temp->next;
        }
        while(temp!=head);
        return count;
    }
}

void findNextTicket(Ticket* head, int ticketID) {
    if (head==nullptr) {
        cout<<"No tickets in the list!"<<endl;
        return;
    }
    Ticket* temp=head;
    do{
        if(temp->ticketID==ticketID) {
            cout<<"Next ticket after "<<ticketID<<" is: "<<temp->next->ticketID<<"-"<<temp->next->customerName<<"-"<<temp->next->rideName<<endl;
            return;
        }
        temp=temp->next;
    } while(temp!=head);
    cout << "Ticket with ID " << ticketID << " is not on the list!" << endl;
}



void display(Ticket* &head){
    Ticket* temp=head;
    do{
        cout<<temp->ticketID<<"-"<<temp->customerName<<"-"<<temp->rideName<<" -> ";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<head->ticketID<<"-"<<head->customerName<<"-"<<head->rideName<<" "<<endl;
}

int main(){

    Ticket* head=nullptr;
    Ticket* tail=nullptr;

    insertAtFront(head,tail,3,"Abdullah","Ferris Wheel");
    insertAtFront(head,tail,2,"Ali","Bumper car");
    insertAtFront(head,tail,1,"Ahmed","Elephant Ride");

    insertAtEnd(head,tail,4,"Shakir","Flying Fritter");
    
    CancelTicketByID(head,tail,3);
    cancelFirstTicket(head,tail);



    display(head);

    searchById(head,4);
    cout<<"Total Number of Tickets are: "<<totalTickets(head)<<endl;
    findNextTicket(head,2);

}
