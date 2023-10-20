/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * insertAtTail(Node *head, int k) {
    // Write your code here
    Node* newnode=new Node(k);
    if(head==nullptr){
        head=newnode;
        return head;
    }
   
    Node* temp=head;
    
      while (temp->next != nullptr) {
        temp = temp->next;
      }
    
   
    newnode->prev = temp;
    temp->next = newnode;

    return head;
    
}
