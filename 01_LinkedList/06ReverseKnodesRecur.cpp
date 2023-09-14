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
void insertAtEnd(node* &head, int val){
    node* n=new node(val);

    if(head==nullptr){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next !=nullptr){
        temp=temp->next;
    }
    temp->next=n;   
}

node* revKnode(node* &head, int k){

    node* prevptr=nullptr;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=nullptr && count<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=nullptr)
    {
    head->next= revKnode(nextptr, k);
    }
    return prevptr;
}

void display(node* head){
    node* temp=head;
    cout<<"Nodes are: ";
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}

int main(){
    int k=2;
    node* head=nullptr;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    insertAtEnd(head,7);
    insertAtEnd(head,8);
    display(head);

    node* newhead=revKnode(head, k);
    display(newhead);

}