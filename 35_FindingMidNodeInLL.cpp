#include<iostream>
#include <cmath>
#include<stack>

using namespace std;

struct node 
{
    int data;
    struct node *next;
}
*first=NULL;

void create(int a[],int n)
{
    struct node *t,*last;
    first=new node;
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}


int len(struct node *p)
{
    int l=0;
    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}


void mid1(struct node* p)
{
    int length =len(first);
 
    int index = (int)ceil(length/2.0);
    node* q = first;

    for (int i=0;i<index-1;i++)
    {
        q=q->next;
    }
    cout<<"Middle Element (Method-I): "<<q->data<<endl;
}
 
void mid2(struct node *p)
{
    struct node* q=p;
    while(q!=NULL)
    {
        q=q->next;
        if(q!=NULL)
        {
            q=q->next;
        }
        if(q!=NULL)
        {
            p=p->next;
        }
    }
    cout <<"Middle Element (Method-II): "<<p->data<<endl;
}
 
void mid3(struct node *p){
    stack <node*> s;
    while(p)
    {
        s.push(p);
        p=p->next;
    }

    int length=s.size();
    int popLength=(int)(floor(length/2.0));
    
    while(popLength)
    {
        s.pop();
        popLength--;
    }
    cout<<"Middle Element (Method-III): "<<s.top()->data<<endl;
}
 
 

int main()
{
    int arr[]={56,67,23,11,90,55,78};
    create(arr,7);

    cout<<"displaying Linked list :\n ";
    display(first);

    mid1(first);
    mid2(first);
    mid3(first);

    return 0;
}