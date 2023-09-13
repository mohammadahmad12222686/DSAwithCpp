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

 void deletekar(node* &head, int key){
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
    deletekar(head, 2);
    display(head);

}