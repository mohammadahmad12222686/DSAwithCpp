

/*************************************Implement_Stack_Using_Queue***************OPTIMISED****************/

class MyStack {
    queue<int> *q;

public:
    MyStack() {
        q=new queue<int>();//MEMORY AYSE ALLOCATE KARWATE HAIN YAAD RAKHNA AHMAD BHAI
        
    }
    
    void push(int x) {

        q->push(x);
        for(int i=0;i<q->size()-1;i++)
        {
            int r=q->front();
            q->pop();
            q->push(r);
        }

        
    }
    
    int pop() {
        if(!q->empty()){
            int g=q->front();
            q->pop();
            return g;
        }
        return -1;
   
    }
    
    int top() {
        if(!q->empty())  return q->front();
            return -1;
        
    }
    
    bool empty() {
        return q->empty();
    }
};