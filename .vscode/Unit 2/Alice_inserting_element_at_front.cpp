// You are using GCC
#include<iostream>
using namespace std;
class Node{
    public:
  int data;
  Node* next;
  
  Node(int value):data(value), next(nullptr){};
};
void insEleToFro(Node*& Head, int value){
    Node* newNode= new Node(value);
    newNode->next=Head;
    Head=newNode;
}
void printnode(Node* Head){
    Node* current=Head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
};


int main(){
    Node* Head=nullptr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int number;
        cin>>number;
        insEleToFro(Head, number);
        // Node* newnode=Node(number);
        // newnode ->next=Head;
        // Head=newnode;
    }
    int x;
    cin>>x;
    cout<<"Created Linked List: ";
    printnode(Head);
    insEleToFro(Head,x);
    cout<<"Final list: ";
    printnode(Head);
}