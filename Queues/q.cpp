#include<iostream>
using namespace std;

class queue
{
    int front, rear;
    int *p;
    int size;
    public:
    queue(int size)
    {
        front=rear=-1;
        this->size=size;
        p = new int[size];
    }
    bool isEmpty();
    bool isFull();
    void enq(int);
    int deq();
    void display();
    //for circular queue
    bool cisEmpty();
    bool cisFull();
    void cenq(int);
    int cdeq();
    void cdisplay();
};

bool queue::isEmpty()
{
    return(front==rear);
}
bool queue::isFull()
{
    return(rear==size-1);
}
void queue::enq(int elem)
{
    if(!isFull())
    {
        rear+=1;
        p[rear]=elem;
    }
    else
        cout<<"Queue full";
}
int queue::deq()
{
    if(!isEmpty())
    {
        front+=1;
        int elem=p[front];
        return elem;
    }
    else
        return -1;
}
void queue::display()
{
    int init=front+1;
    while(init!=rear+1)
    {
        cout<<'|'<<p[init]<<'|';
        init++;
    }
}
//circular queue


int main()
{
    int sz;
    cout<<"Enter size for queue: ";
    cin>>sz;
    queue q(sz);
    q.enq(5);
    q.enq(6);
    q.enq(7);
    q.enq(8);
    q.deq();
    q.display();
}