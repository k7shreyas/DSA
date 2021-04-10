#include<iostream>
using namespace std;

class node
{
    int data;
    node* prev;
    node* next;
    friend class link;
};
class link
{
    node* head;
    public:
    void create();
    void display();
    int len();
    void insert(int, int);
    void del(int);
    void reverse();
};

void link::create()
{
    node *temp, *newnode;
    head = new node();
    head->prev=NULL;
    head->next=NULL;
    temp = head;
    int choice=1;
    while(choice)
    {
        newnode = new node();
        cout<<"Enter data for NewNode: ";
        cin>>newnode->data;
        newnode->prev=temp;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
        cout<<"Want to continue?(1/0): ";
        cin>>choice;
    }
}
void link::display()
{
    node *temp;
    temp = head->next;
    while(temp!=NULL)
    {
        cout<<temp->next;
        temp=temp->next;
        if(temp)
            cout<<"->";
    }
}
int link::len()
{
    node* temp;
    temp=head;
    int len=0;
    while(temp!=NULL)
    {
        len++;
    }
    return len;
}
void link::insert(int pos, int elem)
{
    int p=1;
    node *temp, *newnode;
    temp=head;
    while(p<pos)
    {
        temp=temp->next;
        p++;
    }
    newnode = new node();
    newnode->data=elem;
    newnode->prev=temp;
    newnode->next=temp->next;
    if(temp->next)
        newnode->next->prev=newnode;
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
    if(temp->next->next)
        temp->next->next->prev=temp;
    temp->next=temp->next->next;
}
void link::reverse()
{
    node *p,*temp,*temp1;
    p=head;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        if(p->prev==NULL)
        {
            head=p;
            break;
        }
        p=p->prev;
    }
    temp1 = head;
    while(temp1!=NULL)
    {
        cout<<temp1->data;
        temp1=temp1->next;
        if(temp1)
            cout<<"->";
    }
}
int main()
{
    link l;
    l.create();
    /*
    l.insert(2,4);
    l.insert(1,3);
    l.insert(6,2);
    l.del(2);
    l.del(1);
    */
    l.reverse();
    //l.display();
}