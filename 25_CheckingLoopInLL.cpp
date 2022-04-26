//checking whether the LL is linear or in loop

//if last node is NULL -----> linear
//if last node is pointing to any other node of LL -----> loop

#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
}
*first=NULL;

void create(int arr[],int n)
{
    struct node *t,*last;
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

int isloop(struct node *f)
{
    struct node *q,*p;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;

        q=q ? q->next : q;
    }
    while(p&&q && p!=q);

    if(p==q)
         return 1;//is loop
    else
         return 0;//is linear
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
  struct node *t1,*t2;
  int a[]={34,56,78,90,11};

  create(a,5);
  display(first);

  //t1=first->next->next;
 // t2=first->next->next->next->next;
  //t2->next=t1;

  cout<<"\n"<<isloop(first);
    return 0;
}