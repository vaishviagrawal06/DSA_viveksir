// Queue implementation
#include <bits/stdc++.h>
#define SIZE 100
using namespace std;
class Queue
{
public:
    int data[SIZE];
    int front; // front → index of first element
    int rear;  // rear → index of last element
};
Queue *p = NULL, s1;
void init(Queue *&p, Queue &s1) //*&p means reference to pointer
                                // &s1 means reference to object
{
    p = &s1;
    p->front = -1;
    p->rear = -1;
}
int empty(Queue *&p) // to check queue empty hai ki nhii
{
    if (p->front == -1)
        return 1;
    else
        return 0;
}
int full(Queue *&p) // check ki queue full hai ya nhii
{
    if (p->rear == SIZE - 1)
        return 1;
    else
        return 0; // rear last index me pahuch gya to it means ki queue is full
}
void enqueue(Queue *&p, int x)
{
    if (full(p) == 1) // check ki queue is full or not
    {
        cout << "Queue is full" << endl;
        ;
        return;
    }
    else // agar queue full nhi hai to
    {
        if (p->front == -1)
        {
            p->front = 0;
        }
        p->rear++;
        p->data[p->rear] = x;
        return;
    }
}
int dequeue(Queue *&p) // remove operation
{
    if (empty(p)) // agar queue empty hai to
    {
        cout << "Empty queue!";
        return -1;
    }
    else
    {
        if (p->front == p->rear) // agar queue me ek hi element bacha ho to
        {
            int y;
            y = p->data[p->front];
            p->front = p->rear = -1;
            return y;
        }
        else
        {
            int y; // agar ek se jayada element hai to
            y = p->data[p->front];
            p->front++;
            return y;
        }
    }
}
int main()
{
    init(p, s1);
    enqueue(p, 1);
    enqueue(p, 2);
    enqueue(p, 3);
    enqueue(p, 4);
    enqueue(p, 5);
    enqueue(p, 6);
    enqueue(p, 7);
    enqueue(p, 8);
    enqueue(p, 9);
    enqueue(p, 10);
    cout << "Queue:";
    int count = p->rear - p->front + 1; // calculate number of element in queue
    for (int i = 0; i < count; i++)     // jo jo element remove hote jaa rahe hai usko print karwana hai
    {
        int k = dequeue(p);
        cout << k << " ";
    }
    return 0;
}