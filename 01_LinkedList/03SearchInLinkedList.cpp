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


bool search(node* head, int key){
    node* temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            return true;
        }
        else false;
        temp=temp->next;
    }

}

int main(){
    node* head=nullptr;
    insertBeforeHead(head,1);
    insertBeforeHead(head,2);
    insertBeforeHead(head,3);
    insertBeforeHead(head,4);
    insertBeforeHead(head,5);
    int ans=search(head,0);
    cout<<ans;
}