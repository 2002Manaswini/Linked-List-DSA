//minimum time taken---->o(1)
//maximum time taken---->o(n)


#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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


void insert(int index,int x)
{
    struct node *t;
    struct node *p=first;

    if(index<0 || index>len(first))
       return ;

    t=new node;
    t->data=x;  

  if(index==0)
    { 
      t->prev=NULL;
      t->next=first;
      first->prev=t;
      first=t;  
    }
   else
   {
      for(int i=0;i<index-1;i++)
      {
        p=p->next;
      }
     t->next=p->next;
     t->prev=p;
    
     if(p->next !=NULL)
              p->next->prev=t;
      p->next=t;
   } 
    
}


int main()
{
    int a[]={45,11,24,78,89};
    create(a,5);

    //insert before head
    cout<<"Inserting before head :";
    insert(0,20);
    dis(first);

    //insert at any position
    cout<<"\nInserting at any position :";
    insert(3,70);
    dis(first);

    return 0;
}