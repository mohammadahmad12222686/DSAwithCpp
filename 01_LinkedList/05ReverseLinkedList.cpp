#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=nullptr;
    }
};

void insertAtHead(node* &head, int val){
    
    node* n=new node(val);
    n->next=head;
    head=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}



void reverseList(node* &head){
    node* prevptr=nullptr;
    node* currptr=head;
    node* nextptr;
    while(currptr!=nullptr){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    head=prevptr;   
}
int main(){
    node* head=nullptr;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtHead(head,7);
    display(head);
    reverseList(head);
    display(head);

}