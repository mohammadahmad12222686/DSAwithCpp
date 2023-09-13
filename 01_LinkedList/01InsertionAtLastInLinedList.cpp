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
    node* head=nullptr;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    display(head);

}