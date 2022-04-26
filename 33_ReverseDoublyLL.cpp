#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}
*first=NULL;


void create(int a[],int n)
{
  struct node *t,*last;
  first=new node;
  first->data=a[0];
  first->next=first->prev=NULL;
  last=first;

  for(int i=1;i<n;i++)
  {
      t=new node;
      t->data=a[i];
      t->next=last->next;
      t->prev=last;
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

void rev(struct node *p)
{
    struct node *temp;
  while(p!=NULL)
  {
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;

        p=p->prev;

      if(p!=NULL && p->next==NULL)
         first=p;
  }
}

int main()
{
    int arr[]={56,12,78,89,44};
    create(arr,5);

    cout<<"Before reverse :";
    dis(first);

    cout<<"\nAfter reverse :";
    rev(first);
    dis(first);

    return 0;
}