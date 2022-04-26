//min time --> o(1)
//max time --> o(n)

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}
*first=NULL;


void create(int a[],int n)
{
    struct node *t,*last;
    int i;

    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
      t=(struct node *)malloc(sizeof(struct node));
      t->data=a[i];
      t->next=NULL;
      last->next=t;
      last=t;
    }
}


void insert(struct node *p,int x)
{
   struct node *t,*q = NULL;
   t = (struct node*)malloc(sizeof(struct node));
   t->data = x;
   t->next = NULL;

	if (first==NULL)
	{
	  first=t;
	}
	else
    {
       while(p && p->data<x)
       {
          q=p;
          p=p->next;
        }
     
     if(p==first)
     {
       t->next=first;
       first=t;
     }
   else
    {
      t->next=q->next;
      q->next=t;
     }
   }
}


void display(struct node *p)
{
  while(p!=NULL)
  {
      printf("%d ",p->data);
      p=p->next;
  }
}


int main()
{
    int arr[]={11,22,33,67,88};
    create(arr,5);
    insert(first,15);
    display(first);
    return 0;
}