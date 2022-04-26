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

void dis(struct node *p)
{
  while(p!=NULL)
  {
     cout<<p->data<<" ";
     p=p->next; 
  }
}

//finding length of the doubly LL

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

int main()
{
    int a[]={23,44,67,89,90};
    create(a,5);
    dis(first);
    cout<<"\nLength : "<<len(first);
    return 0;
}