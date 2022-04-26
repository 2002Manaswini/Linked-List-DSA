//writing both together in one code


#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    struct node *next;
}
*first=NULL;


void create(int a[],int n)
{
  struct node *t,*last;

  first=(struct node *)malloc(sizeof(struct node));
  first->data=a[0];
  first->next=NULL;
  last=first;

  for(int i=1;i<n;i++)
  {
      t=(struct node *)malloc(sizeof(struct node));
      t->data=a[i];
      t->next=NULL;
      last->next=t;
      last=t;
  }
}


void delpos(struct node *p,int pos)
{

    struct node *q=NULL;
    int x; //to store the value that we want to delete.
    if(pos==1)
    {
        x=first->data;
        p=first;
        first=first->next;
        delete p;
    }
    else
    {
      for(int i=0;i<pos-1 && p;i++)
      {
        q=p;
        p=p->next;
      }
       q->next=p->next;
       x=p->data;
       delete p;
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

int main()
{
    int arr[]={23,45,67,11,89};
    create(arr,5);
    delpos(first,1); //first node deletion
    delpos(first,4); //4-->position we want to delete.
    display(first);
    return 0;
}



