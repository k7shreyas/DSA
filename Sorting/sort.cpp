#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble(int A[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
                swap(&A[j],&A[j+1]);
        }
    }
}
void insertion(int A[], int n)
{
    for(int i=1; i<n;i++)
    {
        int j=i-1;
        int x=A[i];
        while(j>-1 && A[j]>x)
        {
            swap(&A[j],&A[j+1]);
            j--;
        }
        A[j+1] = x;
    }
}
void selection(int A[], int n)
{
    for(int i=0; i<n-1;i++)
    {
        for(int j,k=i; j<n; j++)
        {
            if(A[j] < A[k])
                k = j;
            if(j==n-1)
                swap(&A[i], &A[k]);
        }
        
    }
}

int main()
{
    int a[5] = {10, 5, 2, 52, 36};
    int n = 5;
    //bubble(a, n);
    //insertion(a, n);
    selection(a, n);
    for(auto i=0;i<n;i++)
        cout<<'|'<<a[i]<<'|';
    cout<<endl;
}