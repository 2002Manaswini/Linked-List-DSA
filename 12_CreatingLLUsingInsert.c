#include<stdio.h>
#include<stdlib.h>

struct node 
{
  struct node *next;
  int data;
}
*first=NULL;

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


void insert(struct node *p,int index,int x)
{
  struct node *t;
  int i;

  if(index<0 || index>count(p))
       return ;
  
  t=(struct node *)malloc(sizeof(struct node));
  t->data=x;

  if(index==0)
      {
        t->next=first;
        first=t;
      }
  else
     {
       for(i=0;i<index-1;i++)
       {
         p=p->next;
       }
       t->next=p->next;
       p->next=t;
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
  insert(first,0,12);
  insert(first,0,89);
  insert(first,1,23);
  display(first);
  return 0;
}