//reversing using sliding pointers

//Taking 3 pointers - p,q,r.
//and assigning null to q and r , 
//and p is pointing to first.

#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
}

*first=NULL;

void create(int arr[],int n)
{
    struct node *t,*last;

    first=(struct node *)malloc(sizeof(struct node));
    first->data=arr[0];
    first->next=NULL;
    last=first;

 
    for(int i=1;i<n;i++)
    {
     t=(struct node *)malloc(sizeof(struct node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void dis(struct node *p)
{
  while(p!=NULL)
  {
      cout<<p->data<<" ";
      p=p->next;
  }
}

void reverse(struct node *p)
{
  struct node *q=NULL;
  struct node *r=NULL;
  
  while(p!=NULL)
  {
      r=q;
      q=p;
      p=p->next;
      q->next=r;
  }
  first=q;
}

int main()
{
    int A[]={10,20,40,50,60};
    create(A,5);
    reverse(first); 
    dis(first); 
   return 0;
}

