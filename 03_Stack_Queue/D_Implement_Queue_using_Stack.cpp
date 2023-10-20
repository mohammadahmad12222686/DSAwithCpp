/*****************************************Implement Queue using Stack**************************************/
class MyQueue {
    public:
    stack<int> *input;//MEMORY DYNAMICALLY ALLOCATE KARWA RAHE
    stack<int> *output;
    MyQueue() {
     input=new stack<int>(); //BHAI YAAD RAKHNA YE
     output=new stack<int>();   
    }
    
    void push(int x) {
        input->push(x);
        
    }
    
    int pop() {
        if(!output->empty()){
            int b=output->top();
            output->pop();
            return b;
        }
        if(output->empty()){
            while(!input->empty()){
                output->push(input->top());
                input->pop();
            }
            int d= output->top();
            output->pop();
            return d;
        }
        else return -1;
        
    }
    
    int peek() {
        if(output->empty()){
            while(!input->empty()){
                output->push(input->top());
                input->pop();
            }
        }
        return output->top();
        
    }
    
    bool empty() {
        return (output->empty() && input->empty());
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */