//time ---> 0(n)

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}

*first=NULL;

void create(int arr[],int n)
{
    struct node *t,*last;
    int i;

    first=(struct node *)malloc(sizeof(struct node));

    first->data=arr[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
    t=(struct node *)malloc(sizeof(struct node));
       
       t->data=arr[i];
       t->next=NULL;
       last->next=t;
       last=t;
    }
}

    
int add(struct node *p)
{
  int sum=0;

  while(p!=NULL)
  {
      sum=sum+p->data;
      p=p->next;
  }
   return sum;
}

/*

RECURSIVE FUNCTION :
time,space --> o(n)

int add(struct node *p)
{
  if(p==0)
          return 0;
  else
      return add(p->next)+p->data;
}

*/

int main()
{
   int a[]={1,2,3,4,5};
   
   create(a,5);

   printf("sum of elements in LL : %d",add(first));
    return 0;
}