/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node* head){
        if(!head){
            return head;
        }
         if(head->next==nullptr){
            return head;
        }
        ListNode* temp=head;
       
        while(temp->next!=NULL){
            ListNode* search=temp->next;
            ListNode* minnode;
            int min=INT_MAX;
            while(search!=nullptr){
                if(search->val<min){
                    min=search->val;
                    minnode=search;
                }
                search=search->next;
            }

            if(temp->val>min){
                minnode->val=temp->val;
                temp->val=min;
            }
   
            temp=temp->next;
        }
        return head;
}
