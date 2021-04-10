#include<iostream>
using namespace std;

class Stack
{
    int top;
    int size;
    char *p;
    public:
    Stack(int sz)
    {
        top=-1;
        size=sz;
        p = new char[size];
    }
    //void create();
    bool isEmpty();
    bool isFull();
    void push(char);
    char pop();
    void display();
    bool parenthesesMatch();
    bool isOperator(char);
    int out(char);
    int in(char);
    string inpost();
    int evalPost();
};

bool Stack::isEmpty()
{
    return(top<0);
}
bool Stack::isFull()
{
    return(top>=size-1);
}
void Stack::push(char elem)
{
    if(!isFull())
    {
        top++;
        p[top]=elem;
    }
    else
    {
            cout<<"Stack Overflow\n";
    }
}
char Stack::pop()
{
    if(!isEmpty())
    {
        char ele=p[top];
        top--;
        return ele;
    }
    else
    {
        cout<<"Stack Empty!!\n";
        return 0;
    }
}
void Stack::display()
{
    while(top!=-1)
    {
        cout<<"|"<<p[top]<<"|\n";
        top--;
    }
    cout<<"---\n";
}
//important
bool Stack::parenthesesMatch()
{
    int i=0;
    //char s[20];
    cout<<"Enter String: ";
    cin>>p;
    //p=s;
    while(p[i]!='\0')
    {   
        if(p[i]=='(' || p[i]=='[' || p[i]=='{')
        {
            push(p[i]);
        }
        else if(p[i]==')' || p[i]==']' || p[i]=='}' && !isEmpty())
        {
            //chech if element to be popped out is match for current parentheses
            if( (p[i]==')' && pop()!='(') || (p[i]=='}' && pop()!='{') || (p[i]==']' && pop()!='[') )
                break;
        }
        else if(p[i]==')' && isEmpty())
        {
            break;
        }
        i++;
    }
    return(p[i]=='\0' && isEmpty());
}
bool Stack::isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='^')
        return 1;
    else 
        return 0;
}
int Stack::in(char c)
{
    if(c=='+' || c=='-')
        return 2;
    else if(c=='*' || c=='/')
        return 4;
    else if(c=='^')
        return 5;
    else
        return 0;
}
int Stack::out(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 3;
    else if(c=='^')
        return 6;
    else if(c=='(')
        return 7;
    else
        return 0;
}
string Stack::inpost()
{
    cout<<"Enter an expression: ";
    cin>>p;
    string postfix="";
    int i=0;
    while(p[i]!='\0')
    {
        if(isEmpty() && isOperator(p[i]))
            push(p[i]);
        else if(!isEmpty() && isOperator(p[i]))
        {
            if( in(p[top])<out(p[i]) )
                push(p[i]);
            else if( in(p[top])>=out(p[i]) )
            {
                while((in(p[top]) > out(p[i])) && !isEmpty() )
                {
                    if(p[top]=='(')
                        pop();
                    else
                        postfix += pop();
                }
                if(p[i]!=')')
                    push(p[i]);
            }
        }
        else
        {
            postfix += p[i];
        }
        i++;
    }
    while(!isEmpty())
    {
        if(p[top]=='(')
            pop();
        else
            postfix += pop();
    }
    postfix[i]='\0';
    //cout<<"Postfix expression is: "<<postfix<<endl;
    return postfix;
}
int Stack::evalPost()
{
    string exp=inpost();
    int x1,x2,res,i=0;
    char c;
    while(exp[i]!='\0')
    {
        if(!isOperator(exp[i]))
            //very important: converting character to int i.e 51-48=3 for 3; type casting won't help
            push(exp[i]-'0');
        else
        {
            x1=pop();
            x2=pop();
            switch(exp[i])
            {
                case '+':
                    res = x2 + x1;
                    break;
                case '-':
                    res = x2 - x1;
                    break;
                case '*':
                    res = x2 * x1;
                    break;
                case '/':
                    res = x2 / x1;
                    break;
                case '^':
                    res = x2^x1;
                    break;
            }
            push(res);   
        }
        i++;
    }
    return pop();
}

int main()
{
    int sz;
    cout<<"Enter size for stack: ";
    cin>>sz;
    Stack s(sz);
    //s.isFull();
    //s.isEmpty();
    //cout<<s.parenthesesMatch()<<"\n";
    //cout<<"Postfix: "<<s.inpost()<<endl;
    cout<<s.evalPost()<<endl;
    //s.display();
}