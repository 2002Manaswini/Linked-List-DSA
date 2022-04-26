//time---> o(1) --->constant time
//we need extra pointer for deletion.
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

void deletefirst(struct node *p)
{
  first=first->next;  //p works as the extra pointer .
  int x=p->data;
  delete p;  // free(p) in c
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
    deletefirst(first);
    display(first);
    return 0;
}

