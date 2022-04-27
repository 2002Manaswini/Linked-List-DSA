#include<iostream>
using namespace std;

struct node 
{
  int data;
  struct node *prev;
  struct node *next;
}
*first;

void create(int a[],int n)
{
    struct node *t,*last;
    first=new node;
    first->data=a[0];
    first->next=first->prev=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display(struct node *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    while(p!=first);
}

int main()
{
  int arr[]={89,45,67,12,18};
  create(arr,5);
  display(first);
  return 0;
}

//insertion----->procedure same as doubly LL
 