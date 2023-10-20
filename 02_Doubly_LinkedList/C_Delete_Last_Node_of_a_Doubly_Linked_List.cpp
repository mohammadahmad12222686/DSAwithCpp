/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * deleteLastNode(Node *head) {

    Node* jisko=head;
    // if(head==nullptr){
    //     return head;
    // }
    if(head->next==nullptr){
        Node* temp= head;
        delete head;
        return NULL;
    }
    while(jisko->next!=nullptr)
    {
        jisko=jisko->next;
    }
    Node* temp=jisko;
    jisko->prev->next=nullptr;
    delete jisko;
    return head;
}
