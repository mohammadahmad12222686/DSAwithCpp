/****************************************Implement_stack_using_Linkedlist***********************************/


/****************************************************************

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


*****************************************************************/

class Stack
{
    //Write your code here
   Node* head;
   int size;
public:
    Stack()
    {
        //Write your code here
        head=nullptr;
        size=0;
    }

    int getSize()
    {
        //Write your code here
        return size;
    }

    bool isEmpty()
    {
        //Write your code here
        if(size==0){
            return true;
        }
        else 
        return false;
        
    }

    void push(int data)
    {
        //Write your code here
        Node* node=new Node(data);
        node->next=head;
        head=node;
        size++;
    }

    void pop()
    {

        //Write your code here
        if(size!=0){
             Node *temp=head;
             head=head->next;
             delete temp;
             size--;

        }
    }

    int getTop()
    {
        //Write your code here
        if(head==NULL){
            return -1;
        }
        else{
            
            return head->data;
        }
    }
};