//time---->o(n)

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

int count(struct node *p)
{
     int c=0;
    while(p!=NULL)
    {
        c++;
       p=p->next;
    }
    return c;
}

void reverse(struct node *p)
{
   int i=0;
   struct node *q=p;

//creating array    
   int *a;
   a=(int *)malloc(sizeof(int)*count(p));


//copied elements of LL to array
   while(q!=NULL)
   {
       a[i]=q->data;
       q=q->next;
       i++;
   }
   q=p;
   i--;

//copied elements of array to LL
   while(q!=NULL)
   {
       q->data=a[i];
       q=q->next;
       i--;
   }
}

int main()
{
    int A[]={10,20,40,50,60};
    create(A,5);
    reverse(first); 
    dis(first); 
   return 0;
}

