#include<iostream>
using namespace std;

class node
{
    int data;
    node* next;
    friend class link;
};
class link
{
    node* head;
    public:
    void create();
    void display();
    void recDisplay(node*);
    int len();
    void insert(int, int);
    void del(int);
    void reverse();
    void recReverse(node*, node*);
};

void link::create()
{
    node *temp,*newnode;
    head=new node();
    head->next=head;
    temp=head;
    int choice=1;
    while(choice)
    {
        newnode=new node();
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next=head;
        temp->next=newnode;
        temp=newnode;
        cout<<"Want another node?(1/0)";
        cin>>choice;
    }
    //recDisplay(head->next);
}

void link::display()
{
    node* temp;
    temp=head->next;
    while(temp!=head)
    {
        cout<<temp->data;
        temp=temp->next;
        if(temp!=head)
            cout<<"->";
    }
    cout<<"\n";
}

void link::recDisplay(node* temp)
{
    if(temp!=head)
    {
        cout<<temp->data;
        recDisplay(temp->next);
    }
}
/*************************
void link::reverse()
{
    node *p,*q,*r;
    q=r=NULL;
    p = head;
    while(p!=head)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
    //assigning circular link
    while(q->next!=NULL)
        q=q->next;
    q->next=head;
    //display linked list
    node* temp;
    temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data;
        temp=temp->next;
        if(temp->next)
            cout<<"->";
    }
    cout<<"\n";
}

void link::recReverse(node* q, node* p)//debug
{
    if(p!=NULL)
    {
        recReverse(p,p->next);
        p->next=q;
    }
    else
    {
        head=q;
    }
    node* temp;
    temp=head;
    while(temp->next!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
        if(temp->next)
            cout<<"->";
    }
    cout<<"\n";
}
************************************/
int link::len()
{
    node* temp;
    temp = head->next;
    int length=0;
    while(temp!=head)
    {
        length++;
        temp=temp->next;
    }
    return length;
}

void link::insert(int x, int val)
{
   node *temp,*newnode;
   //for finding length
   node* temp1;
   temp1 = head->next;
   int length=0;
   while(temp1!=head)
   {
       length++;
       temp1=temp1->next;
   }//length search complete

   if(x==1 && x<length+1)
   {
       temp=head->next;
       newnode = new node();
       //cout<<"Enter data: ";
       newnode->data=val;
       newnode->next=temp;
       head->next=newnode;
   }
   else if(x>1 && x<length+1)
   {
       int pos=1;
       temp=head;
       while(pos<x)
       {
           temp=temp->next;
           pos++;
       }
       newnode = new node();
       newnode->data=val;
       newnode->next=temp->next;
       temp->next=newnode;
   }
   else if(x==length+1)
   {
        temp=head;
        while(temp->next!=head)
            temp=temp->next;
        //cout<<"Enter data for newnode: ";
        newnode = new node();
        newnode->data=val;
        newnode->next=head;
        temp->next=newnode;
   }
}

void link::del(int x)
{
   node *temp,*temp1;
   temp1 = head->next;
   int length=0;
   while(temp1!=head)
   {
       length++;
       temp1=temp1->next;
   }
   if(x==1 && x<length)
   {
       temp = head->next;
       head->next=temp->next;
       //delete temp;
   }
   else if(x>1 && x<length)
   {
       int pos=1;
       temp=head;
       while(pos<x)
       {
           temp=temp->next;
           pos++;
       }
       temp->next=temp->next->next;
       //delete temp;
   }
   else if(x==length)
   {
       int pos=1;
       temp=head;
       while(pos<x)
       {
           temp=temp->next;
           pos++;
       }
       temp->next=head;
       //delete temp;
   }
}

int main()
{
    node  *q,*p;
    link l;
    l.create();
    //l.display();
    //l.len();
    l.insert(2,4);
    l.insert(1,3);
    l.insert(6,5);
    l.del(2);
    l.del(1);
    l.del(4);
    l.display();
}