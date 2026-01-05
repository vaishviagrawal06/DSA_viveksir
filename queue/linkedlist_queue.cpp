//linked list implimentation of queue
#include<bits/stdc++.h>
using namespace std;

class LQueue 
{
    public:
    int data;
    LQueue* next;
};
LQueue *front ,*rear = NULL,*temp,*ttemp; // temp or ttemp temprory pointer
void enqueue(LQueue *&front,LQueue *&rear,int x) 
{
    if(front == NULL)
    {
        temp = new LQueue(); // dynamically memory banana hai
        temp->data = x;
        temp -> next = NULL; //ek hi node hai kyunki next me NULL hai ya next full hai
        front = rear = temp ; // front and rear dono same node pe point karenge

    }
    else
    {
        temp = rear; // rear ko temp me store kar lo
        ttemp = new LQueue();
        rear= ttemp; // rear ab ne node ko pint karne laga
        ttemp ->data = x;
        temp ->next = ttemp; 
        ttemp ->next = NULL;
        rear = ttemp;

    }
};
int dequeue(LQueue *&front,LQueue *&rear)
{
    if(front == NULL)
    {
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    else{
        if(front == rear){    //ek hi node haii
            int y = front ->data;
            delete front;
            front= rear = NULL;
            return y;
        }

        else{
            temp = front ; // front ko temp me store kar lo
            front = front ->next;
            int y = temp ->data;
            temp ->next = NULL;
            delete temp;
            return y;
        }    
    }
    
}

int main(){
    enqueue(front,rear,1);
    enqueue(front,rear,2);
    enqueue(front,rear,3);
    enqueue(front,rear,4);
    enqueue(front,rear,5);
    cout<<"Queue:";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
    cout<<dequeue(front,rear)<<" ";
}
