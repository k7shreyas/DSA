#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;
    friend class bst;
};
class bst
{
    node* root;
    public:
    bst()
    {
        root=NULL;
    }
    void create();
    void insert(int);
    node* recInsert(node*,int);
    node* del(int);
    void inorder();
    void inorder(node*);
};

void bst::create()
{
    root = new node();
    cout<<"Enter data for root: ";
    cin>>root->data;
    root->left=root->right=NULL;
    node* temp;
    node *newnode;
    int ch;
    do
    {
        newnode = new node();
        cout<<"Enter value for next node: ";
        cin>>newnode->data;
        newnode->left=newnode->right=NULL;
        int flag=1;
        //placement of temp is important here i.e. inside the do-while loop
        temp = root;
        while(flag)
        {
            if(newnode->data<temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left = newnode;
                    flag=0;
                }
                else
                    temp=temp->left;
            }
            else if(newnode->data>temp->data)
            {
                if(temp->right==NULL)
                {
                    temp->right = newnode;
                    flag=0;
                }
                else
                    temp=temp->right;
            }
            else
            {
                cout<<"Invalid Input";
                delete newnode;
                break;
            }
        }
        cout<<"Want to add?(0/1)";
        cin>>ch;
    }while(ch);
}
void bst::insert(int item)
{   
    node *newnode, *temp;
    temp = root;
    newnode = new node();
    newnode->data=item;
    while(1)
    {
        if(newnode->data<temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left=newnode;
                break;
            }
            else
                temp=temp->left;
        }
        if(newnode->data>temp->data)
        {
            if(temp->right==NULL)
            {
                temp->right=newnode;
                break;
            }
            else
                temp=temp->right;
        }
    }
}
node* bst::recInsert(node* temp, int item)
{
    node* newnode;
    if(temp==NULL)
    {
        newnode = new node();
        newnode->data=item;
        newnode->right=newnode->left=NULL;
        return newnode;
    }
    if(item<temp->data)
        temp->left=recInsert(temp->left,item);
    else if(item>temp->data)
        temp->right=recInsert(temp->right,item);
    return temp;
}
node* bst::del(int key)
{
    node *temp,*parent;
    temp=root;
    while(temp->data!=key)
    {
        if(key<temp->data)
        {
            parent=temp;
            temp=temp->left;
        }
        else if(key>temp->data)
        {
            parent=temp;
            temp=temp->right;
        }
    }
    //if node to be deleted has 0 children
    if(!temp->left and !temp->right)
    {
        if(parent->left==temp)
            parent->left=NULL;
        else
            parent->right=NULL;
        return temp;
        delete temp;
    }
    //if node to be deleted has 1 child
    else if(temp->left==NULL xor temp->right==NULL)
    {
        if(parent->right==temp)
        {
            if(temp->left!=NULL)
                parent->right=temp->left;
            else
                parent->right=temp->right;
        }
        else
        {
            if(temp->left!=NULL)
                parent->left=temp->left;
            else
                parent->left=temp->right;
        }
        return temp;
        delete temp;
    }
    //node to be deleted has 2 children(replace to be deleted node by its inorder successor or predecessor)
    else
    {
        //search for inorder successor
        node *replace,*replacePar;
        replacePar=temp;
        replace=temp->right;
        while(replace->left!=NULL)
        {
            replacePar=replace;
            replace=replace->left;
        }
        if(parent->left==temp)
        {
            replace->left=temp->left;
            parent->left=replace;
            if(temp->right==replace)
                temp->right=NULL;
            else
                replacePar->left=NULL;
        }
        else
        {
            replace->left=temp->left;
            parent->right=replace;
            if(temp->right==replace)
                temp->right=NULL;
            else
                replacePar->left=NULL;
        }
        return temp;
        delete temp;
    }
}
void bst::inorder()
{
    inorder(root);
}
void bst::inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<"|"<<temp->data<<"|";
        inorder(temp->right);
    }
}
int main()
{
    bst seed;
    seed.create();
    //seed.del(20);
    //seed.del(8);
    //seed.del(3);
    seed.inorder();
}