#include<iostream>
using namespace std;

class node
{
    int data;
    node* next;
    friend class Q;
};
class Q
{
    node *front,*rear;
    public:
    Q()
    {
        front=rear=NULL;
    }
    bool isEmpty();
    void enq(int);
    int deq();
    void display();
};

bool Q::isEmpty()
{
    return(rear==NULL);
}
void Q::enq(int elem)
{
    node *newnode;
    newnode = new node();
    if(newnode==NULL)
        cout<<"Heap full. Can't enqueue";
    else
    {
        newnode->data=elem;
        newnode->next=NULL;
        if(front==NULL)
            front=rear=newnode;
        else
        {
            rear->next=newnode;
            rear=newnode;
        }
    }
}
int Q::deq()
{
    node* temp;
    temp=front;
    int elem = temp->data;
    front=front->next;
    //delete temp;
    return elem;
}
void Q::display()
{
    node *temp;
    temp=front;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|";
        temp=temp->next;
    }
}

int main()
{
    Q q;
    q.enq(5);
    q.enq(6);
    q.enq(7);
    q.enq(8);
    q.deq();
    q.deq();
    q.display();
}