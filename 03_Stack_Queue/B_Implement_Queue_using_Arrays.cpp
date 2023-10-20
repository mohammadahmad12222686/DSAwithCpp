/*
1.  A Queue is defined as a linear data structure that is open at both ends
    and the operations are performed in First In First Out (FIFO) order.

2. STL C++
#include<queue>
queue<int> q

Method	          Definition
q.empty()	  Returns whether the queue is empty. It return true if the queue is empty otherwise returns false.
q.size()	  Returns the size of the queue.
q.swap()	  Exchange the contents of two queues but the queues must be of the same data type, although sizes may differ.
q.emplace()   Insert a new element into the queue container, the new element is added to the end of the queue.
q.front()	  Returns a reference to the first element of the queue.
q.back()	  Returns a reference to the last element of the queue.
q.push(g) 	  Adds the element ‘g’ at the end of the queue.
q.pop() 	  Deletes the first element of the queue.


*/

/*
    Time complexity: O(1)
    Space complexity: O(1)

    For both enqueue and dequeue operations.
*/
/************************************************Implement_Queue_using_Arrays****************************************************/
class Queue {

    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        arr.resize(100001);//memory aise allocate kiya jaata hai yaad rakhna
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        arr[rear] = e;
        rear++;
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (front == rear) // The queue is empty
            return -1;
        return arr[front++];
    }
};

/*
class Queue {

	int front, rear, maxsize,currsize;
	vector<int> arr;

public:
	Queue()
	{
		front = -1;
		rear = -1;
		arr.resize(100001);
		currsize=0;
		
	}

	Queue(int maxsize)
	{
		(* this).maxsize=maxsize;
		arr.resize(maxsize);
		front = -1;
		rear = -1;
		currsize=0;
		
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		// Write your code here.
		if(currsize==maxsize){
			return;
		}
		if(front==-1){
			front=0;
			rear=0;
		}
		else rear=(rear+1)%maxsize;
		arr[rear]=e;
		rear++;
		currsize++;

	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		// Write your code here.
		if(front==-1 || currsize==0){
			return 0;
		}

			int val=arr[front];
			if(currsize==1){
				front=-1;
				rear=-1;
			}
			else front=(front+1)%maxsize;
			currsize--;
			return val;
	
	}
};
*/