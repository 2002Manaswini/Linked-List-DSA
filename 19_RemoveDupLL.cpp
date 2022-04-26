#include<iostream>
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

    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(int i=0;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
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

void RemDup(struct node *p)
{
  struct node *q=p->next;
  while(q!=NULL)
   {
     if(p->data!=q->data)
     {
        p=q;
        q=q->next;
      }
      else
      {
       p->next=q->next;
       free(q);
       q=p->next;
      }
   }
 
}


int main()
{
 
   int A[]={10,20,20,40,50,50,50,60};
    create(A,8);
    RemDup(first); 
    dis(first); 
   return 0;
}