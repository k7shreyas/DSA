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
        front=rear=0;
        this->size=size;
        p = new int[size];
    }
    bool cisEmpty();
    bool cisFull();
    void cenq(int);
    int cdeq();
    void cdisplay();
};
bool queue::cisEmpty()
{
    return(front==rear);
}
bool queue::cisFull()
{
    return((rear+1)%size==front);
}
void queue::cenq(int elem)
{
    if(!cisFull())
    {
        rear=(rear+1)%size;
        p[rear]=elem;
    }
    else
        cout<<"Queue full";
}
int queue::cdeq()
{
    if(!cisEmpty())
    {
        front=(front+1)%size;
        int elem=p[front];
        return elem;
    }
    else
        return -1;
}
void queue::cdisplay()
{
    int init=(front+1)%size;
    while(init!=(rear+1)%size)
    {
        cout<<'|'<<p[init]<<'|';
        //important
        init=(init+1)%size;
    }
}

int main()
{
    int sz;
    cout<<"Enter size for queue: ";
    cin>>sz;
    queue q(sz);
    q.cenq(5);
    q.cenq(6);
    q.cenq(7);
    q.cenq(8);
    q.cenq(9);
    //q.cenq(10);
    q.cdeq();
    q.cdeq();
    q.cenq(11);
    q.cdisplay();
}