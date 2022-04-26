#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node *prev;
  struct node *next;
}
*first=NULL;

void create(int arr[],int n)
{
   struct node *t,*last;
   first=new node;
   first->data=arr[0];
   first->next=first->prev=NULL;
   last=first;

   for(int i=1;i<n;i++)
   {
       t=new node;
       t->data=arr[i];
       t->next=last->next;
       t->prev=last;
       last->next=t;
       last=t;
   }
}

void display(struct node *p)
{
   while(p!=NULL)
   {
       cout<<p->data<<" ";
       p=p->next;
   } 
}

int len(struct node *p)
{
    int l=0;
    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}

int del(int index,struct node *p)
{
    int x;

  if(index<1 || index>len(p))
       return -1;
  
  if(index==1)
  {
      first=first->next;
      if(first != NULL)
             first->prev=NULL;
      
      x=p->data;
      free(p);
  }
  else
  {
    for(int i=1;i<index-1;i++)
    {
        p=p->next;
    }  
    p->prev->next=p->next;
    
    if(p->next)
         p->next->prev=p->prev;
    
    x=p->data;
    free(p);
  }
  return x;
}

int main()
{
    int a[]={56,12,34,89,90};
    create(a,5);
    
    cout<<"deleting first node :";
    del(1,first);
    display(first);

    cout<<"\ndeleting from any position :";
    del(3,first);
    display(first);

    return 0;
}