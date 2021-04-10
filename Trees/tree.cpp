#include<iostream>
#include<queue>
using namespace std;

class node
{
    int data;
    node *left; //acts as front for Q
    node *right; //acts as rear for Q
    friend class tree;
    friend class stack;
};
class stack
{
    int top=-1;
    node* arr[30];
    public:
    stack()
    {
        top=-1;
    }
    bool isEmpty();
    bool isFull();
    void push(node*);
    node* pop();
    friend class tree;
};
bool stack::isEmpty()
{
    return(top==-1);
}
bool stack::isFull()
{
    return(top==29);
}
void stack::push(node* temp)
{
    if(!isFull())
    {
        top++;
        arr[top]=temp;
    }
}
node* stack::pop()
{
    if(!isEmpty())
    {
        node* temp;
        temp = arr[top];
        return temp;
    }
    else 
        return NULL;
}
class tree
{
    node* root;
    public:
    tree()
    {
        root=NULL;
    }
    void create();
    void recCreate();
    void recCreate(node*);
    void preorder();
    void preorder(node*);
    void inorder();
    void inorder(node*);
    void itrIn();
    void itrPre();
    void itrPost();
    void postorder();
    void postorder(node*);
    void bfs();
};

void tree::create()
{
    node* temp;
    if(root==NULL)
    {
        root = new node();
        cout<<"Enter data for root: ";
        cin>>root->data;
        root->left=NULL;
        root->right=NULL;
    }
    int choice;
    do
    {
        temp=root;
        int flag=1;
        char c;
        node *newnode;
        while(flag)
        {
            cout<<"Want child at left or right for "<<temp->data<<"?(l/r)";
            cin>>c;
            if(c=='l')
            {
                if(temp->left==NULL)
                {
                    newnode = new node();
                    cout<<"Enter data: ";
                    cin>>newnode->data;
                    temp->left=newnode;
                    newnode->left=NULL;
                    newnode->right=NULL;
                    flag=0;
                }
                temp=temp->left;
            }
            else if(c=='r')
            {
                if(temp->right==NULL)
                {
                    newnode= new node();
                    cout<<"Enter data: ";
                    cin>>newnode->data;
                    temp->right=newnode;
                    newnode->left=NULL;
                    newnode->right=NULL;
                    flag=0;
                }
                temp=temp->right;
            }
        }
        cout<<"Continue?(1/0)?";
        cin>>choice;
    }while(choice==1);
}
void tree::recCreate()
{
    root = new node();
    cout<<"Enter data for root: ";
    cin>>root->data;
    root->right=root->left=NULL;
    recCreate(root);
}
void tree::recCreate(node *temp)
{
    char c;
    node* newnode;
    cout<<"Want data at left of "<<temp->data<<"?(y/n)";
    cin>>c;
    if(c=='y')
    {
        newnode = new node();
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->left=newnode->right=NULL;
        temp->left=newnode;
        recCreate(newnode);
    }
    cout<<"Want data at right of "<<temp->data<<"?(y/n)";
    if(c=='y')
    {
        newnode = new node();
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->left=newnode->right=NULL;
        temp->right=newnode;
        recCreate(newnode); 
    }
}
void tree::preorder()
{
    preorder(root);
}
void tree::preorder(node* temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}
void tree::itrPre()
{
    node* temp;
    stack s;
    temp = root;
    while(1)
    {
        while(temp!=NULL)
        {
            cout<<temp->data;
            s.push(temp);
            temp=temp->left;
        }
        if(s.isEmpty())
            break;
        temp = s.pop();
        temp=temp->right;
    }
}
void tree::inorder()
{
    inorder(root);
}
void tree::inorder(node* temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->data;
        inorder(temp->right);
    }
}
void tree::itrIn()
{
    node* temp;
    stack s;
    temp = root;
    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        if(s.isEmpty())
            break;
        temp = s.pop();
        cout<<temp->data;
        temp=temp->right;
    }
}
void tree::postorder()
{
    postorder(root);
}
void tree::postorder(node* temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data;
    }
}
void tree::itrPost()
{
    stack s;
    node *temp;
    temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        if(s.arr[s.top]->right==NULL)
        {   
            s.pop();
            cout<<temp->data;
        }
        while(s.arr[s.top]!=NULL && s.arr[s.top]->right)
        {
            s.pop();
            cout<<temp->data;
        }
        if(s.isEmpty())
            break;
        temp=s.arr[s.top]->right;
    }
}
void tree::bfs()
{
    queue<node*> q;
    node *temp;
    temp=root;
    q.push(temp);
    while(!q.empty())
    {
        //in stl queue pop does not return any value so use front then pop
        temp = q.front();
        q.pop();
        cout<<temp->data;
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=nullptr)
            q.push(temp->right);
    }
}

int main()
{
    queue<node*> q;
    tree seed;
    seed.create();
    //seed.preorder();
    //seed.inorder();
    //seed.postorder();
    seed.itrPre();
    cout<<endl;
    seed.itrIn();
    cout<<endl;
    seed.itrPost();
    cout<<endl;
    seed.bfs();
}




















































/***********
void tree::recCreate()
{
    cout<<"Enter data for root: ";
    root = new node();
    cin>>root->data;
    root->left=NULL;
    root->right=NULL;
    recCreate(root);
}
*************/