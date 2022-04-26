#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}

*first=NULL ;  //global pointer


void create(int A[],int n)
{
   int i;
   struct node *t,*last;

   first=(struct node *)malloc(sizeof(struct node)); //created at heap

   first->data=A[0];
   first->next=NULL;
   last=first;

   for(i=1;i<n;i++)
   {
       t=(struct node *)malloc(sizeof(struct node));
       t->data=A[i];
       t->next=NULL;
       last->next=t;
       last=t;
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
    int A[]={30,55,76,10,15};

    create(A,5);
    display(first);

    return 0;
}