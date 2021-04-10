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
    link()
    {
        head = NULL;
    }
    void create();
    void display();
    void recDisplay(node*);
    void recDisRev(node*);
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
    head->next=NULL;
    temp=head;
    int choice=1;
    while(choice)
    {
        newnode=new node();
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
        cout<<"Want another node?(1/0)";
        cin>>choice;
    }
}

void link::display()
{
    node* temp;
    temp=head->next;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
        if(temp)
            cout<<"->";
    }
    cout<<"\n";
}

void link::recDisplay(node* temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data;
        recDisplay(temp->next);
    }
}

void link::recDisRev(node* temp)
{
    if(temp!=NULL)
    {
        recDisRev(temp->next);
        cout<<temp->data;
    }
}

void link::reverse()
{
    node *p,*q,*r;
    q=r=NULL;
    p = head;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
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

int link::len()
{
    node* temp;
    temp = head->next;
    int length=0;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}

void link::insert(int x, int val)
{
    node *temp,*newnode;
    temp=head;
    int p=1;
    while(p<x)
    {
        temp=temp->next;
        p++;
    }
    newnode = new node();
    newnode->data=val;
    newnode->next=temp->next;
    temp->next=newnode;
}

void link::del(int pos)
{
    node* temp;
    temp = head;
    int p=1;
    while(p<pos)
    {
        temp=temp->next;
        p++;
    }
    temp->next=temp->next->next;
}

int main()
{
    node  *q,*p;
    link l;
    l.create();
    //l.len();
    l.insert(2,4);
    l.insert(1,3);
    l.insert(6,5);
    l.del(2);
    l.del(1);
    l.del(4);
    l.display();
}

/*****
 * node *temp,*temp1;
   temp1 = head->next;
   int length=0;
   while(temp1!=NULL)
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
       temp->next=NULL;
       //delete temp;
   }
   */////