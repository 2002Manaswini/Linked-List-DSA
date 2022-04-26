#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}
*head;

void create(int arr[],int n)
{
  struct node *t,*last;
  head=(struct node *)malloc(sizeof(struct node));
  head->data=arr[0];
  head->next=head;
  last=head;

  for(int i=1;i<n;i++)
  {
      t=(struct node *)malloc(sizeof(struct node));
      t->data=arr[i];
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

void insert(int pos,int x)  //insert at any position
{
  struct node *t;
  struct node *p=head;

  for(int i=0;i<pos-1;i++)
  {
    p=p->next;
  }
  t=new node;
  t->data=x;
  t->next=p->next;
  p->next=t;
}

void insert2(int pos,int x)  //inserting before head
{
  struct node *t;
  struct node *p=head;

  t=new node;
  t->data=x;
  t->next=head;

  while(p->next!=head)
  {
    p=p->next;
  }
  p->next=t;
  head=t;
}


int length(struct node *p)
{
  int len=0;
  do
  {
    len++;
    p=p->next;
  }
  while(p!=head);

  return len;
}


//single insert function for the above both cases
void insert3(int pos,int x)
{
  struct node *t;
  struct node *p=head;

  if(pos<0 || pos>length(head))
     return ;

  if(pos==0)
  {
    t=new node;
    t->data=x;
      if(head==NULL)
      {
        head=t;
        head->next=head;
      }
       else
      {
        while(p->next!=head)
           {
            p=p->next;
           }
           p->next=t;
           head=t;
       }
     }
  else
  {   
    for(int i=0;i<pos-1;i++)
     {
        p=p->next;
     }
      t=new node;
      t->data=x;
      t->next=p->next;
      p->next=t;
   }
}


int main()
{
    int a[]={23,45,67,89,90};
    create(a,5);

    //inserting at any position
     insert3(3,55);
     display(head);
      cout<<"\n";
    
    //inserting before head 
    insert3(0,11);
    display(head);

    return 0;
}