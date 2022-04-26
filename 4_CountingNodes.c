//time --> o(n)
//space --> o(1)

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

   first=(struct node *)malloc(sizeof(struct node));

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

int cnodes(struct node *p)
{
    int c=0;

    while(p!=NULL)
    {
        c++;
       p=p->next;
    }
    return c;
}

/*
recursive function:
time and space ---------> o(n)

int cnodes(struct node *p)
{
    if(p==0)
      return 0;
    else
       return cnodes(p->next)+1;
}
*/



int main()
{
    int A[]={30,55,76,10,15};

    create(A,5);
    
    printf("Length of nodes : %d",cnodes(first));

    return 0;
}