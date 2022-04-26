//reversing LL using recursion

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
  struct node *last,*t;

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

void reverse(struct node *q,struct node *p)
{
  if(p!=NULL)
   {
     reverse(p,p->next);
     p->next=q;
   }
   else
        first=q;
  
}

int main()
{
    int a[]={45,22,89,12,67};
    create(a,5);
    reverse(NULL,first);
    dis(first);

    return 0;
}