#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
}
*head;

void create(int a[],int n)
{
    struct node *last,*t;
    head=new node;
    head->data=a[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++)
    {
      t=new node;
      t->data=a[i];
      t->next=last->next;
      last->next=t;
      last=t;
    }

}

void display(struct node *p)
{
    do
    {
      cout<<p->data<<" ";
      p=p->next;
    }
    while(p!=head);
}


int len(struct node *p)
{
 int l=0;
 do
 {
   l++;
   p=p->next;
 }
  while(p!=head);
    return l;
}


int del(struct node *p,int index)
{
    struct node *q;
    int x;
    
    if(index<0 || index>len(head))
        return -1;
    
    if(index==1)
    {
        while(p->next!=head)
         {
            p=p->next;
         } 
        x=head->data; 
        if(head==p)
         {
             free(head);
             head=NULL;
         }  
         else
         {
             p->next=head->next;
             free(head);
             head=p->next;
         }                                            
    }
   else
   {
       for(int i=0;i<index-2;i++)
             p=p->next;
       q=p->next;
       p->next=q->next;
       x=q->data;
       free(q);
   }
  return x;
}


int main()
{
    int arr[]={45,66,89,12,34};
    create(arr,5);
    del(head,3);
    display(head);
    return 0;
}