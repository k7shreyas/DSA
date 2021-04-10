#include<iostream>
using namespace std;
int count=0;
class node
{
    char data;
    node* next;
    friend class stack;
};
class stack
{
    node* top;
    public:
    bool isEmpty();
    void push(char);
    char pop();
    bool parenthesesMatch();
    void display();
};

bool stack::isEmpty()
{
    return(top==NULL);
}
void stack::push(char elem)
{
    if(count==0)
    {
        top=new node();
        top->next=NULL;
        top->data=elem;
        count++;
    }
    else
    {
        node *newnode;
        newnode = new node();
        newnode->data = elem;
        ////very very very important
        newnode->next=top;
        top=newnode;
    }
}
char stack::pop()
{
    if(!isEmpty())
    {   
        node* p;
        p=top;
        char elem = top->data;
        top=top->next;
        return elem;
        //delete p;
    }
    else
    {
        cout<<"Stack Empty!!";
        return 0;
    }
}
bool stack::parenthesesMatch()
{
    int i=0;
    char s[20];
    cout<<"Enter String: ";
    cin>>s;
    while(s[i]!='\0')
    {   
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
        {
            push(s[i]);
        }
        else if(s[i]==')' || s[i]==']' || s[i]=='}' && !isEmpty())
        {
            //chech if element to be popped out is match for current parentheses
            if( (s[i]==')' && pop()!='(') || (s[i]=='}' && pop()!='{') || (s[i]==']' && pop()!='[') )
                break;
        }
        else if(s[i]==')' && isEmpty())
        {
            break;
        }
        i++;
    }
    return(s[i]=='\0' && isEmpty());
}
void stack::display()
{
    node *temp;
    temp = top;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|\n";
        temp=temp->next;
    }
}

int main()
{
    stack s;
    cout<<s.parenthesesMatch()<<endl;
    //s.display();
}