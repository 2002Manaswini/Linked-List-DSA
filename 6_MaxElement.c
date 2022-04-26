#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node 
{
  int data;
  struct node *next;
}

*first = NULL;

void create(int arr[],int n)
{
    int i;
    struct node *t,*last;

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

int max(struct node *p)
{
    int m=INT_MIN;  //INT MIN = -32768
 
    while(p!=NULL)
     {
       if(p->data>m)
                m=p->data;
         p=p->next;
     }
  return m;
}


/*

RECURSIVE FUNCTION :

int max(struct node *p)
{
  int x=0;

  if(p==0)
       return INT_MIN;
  x=max(p->next);

  if(x>p->data)
      return x;
  else
    return p->data;
}

*/

int main()
{
    int a[]={89,22,45,90,11};
    create(a,5);

    printf("Maximum element : %d",max(first));

    return 0;
}