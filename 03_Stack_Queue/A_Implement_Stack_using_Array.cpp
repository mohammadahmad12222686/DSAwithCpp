// Stack class.
/* 
1.  Stack is a data structure that follows the Last In First Out.
2.  push(): Insert the element in the stack.
    pop(): Remove and return the topmost element of the stack.
    top(): Return the topmost element of the stack
    size(): Return the number of remaining elements in the stack.

3. STACK STL C++
#include <stack>
using namespace std;
stack<int> stackname;
    i)stackname.empty()
        Parameters :No parameters are passed.
        Returns :True, if stack is empty; False, Otherwise
    ii)stackname.size()
        Parameters :No parameters are passed.
        Returns :Number of elements in the container.
    iii)stackname.push(value)
        Parameters: The value of the element to be inserted is passed as the parameter.
        Result: Adds an element of value the same as that of the parameter passed at the top of the stack.
    iv)stackname.pop()
        Parameters: No parameters are passed.
        Result: Removes the newest element in the stack or basically the top element.
    v)stackname.top()
        Parameters: No value is needed to pass as the parameter.
        Return Value: Direct reference to the top element of the stack container. Simply returns the value of top element of stack.
    vi)stackname1.swap(stackname2)
        Parameters: The name of the stack with which the contents have to be swapped. 
        Result: All the elements of the 2 stack are swapped.
    


*/
/********************************************************Implement_Stack_using_Array********************************************/
class Stack {
    int * arr;//dynamically memory allocate karwaya hain
    int Top;
    int size;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        size=capacity;
        arr=new int[size];
        Top=-1;
    }

    void push(int num) {
        // Write your code here.
        if (Top != size - 1) {
          Top++;
          arr[Top] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(Top!=-1){
            int x=arr[Top];
            Top--;
            return x;
        }
        else{
            return -1;
        }
    }
    
    int top() {
        // Write your code here.
        if(Top!=-1){
            return arr[Top];
        }
        else{
            return -1;
        }
    }
    
    int isEmpty() {
        // Write your code here.
        if(Top==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int isFull() {
        // Write your code here.
        if(Top==size-1){
            return 1;
        }else{
            return 0;
        }
    }
    
};
