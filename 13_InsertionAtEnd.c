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
  int i;
  struct node *t,*last;
  
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


void insert(int x)
{
  struct node *v,*last;
  v=(struct node *)malloc(sizeof(struct node));
  v->data=x;
  v->next=NULL;
  last->next=v;
  last=v;
}

/*

void insert(int x)
{
  struct node *;
  v=(struct node *)malloc(sizeof(struct node));
  v->data=x;
  v->next=NULL;
  
  if(first==NULL)
    {
       first=last=v;
    } 
    else
     {
       last->next=v;
       last=v;
     } 
}

*/


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
    int arr[]={34,56,22,97,80};
    create(arr,5);
    insert(10);
    display(first);
  return 0;
}