#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    int data;
    node(int val){
        data =val;
        next=nullptr;
    }
};

void insertBeforeHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void deletehead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}




 void deletekar(node* &head, int key){

    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deletehead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=key){
        temp=temp->next;
    }

    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;


 }
void display(node* head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"Null";

}

int main(){
    node* head=nullptr;
    insertBeforeHead(head,1);
    insertBeforeHead(head,2);
    insertBeforeHead(head,3);
    insertBeforeHead(head,4);
    insertBeforeHead(head,5);
    insertBeforeHead(head,11);
    insertBeforeHead(head,6);
    insertBeforeHead(head,7);
    insertBeforeHead(head,9);
    insertBeforeHead(head,8);
    deletekar(head, 2);
    deletehead(head);
    display(head);

}