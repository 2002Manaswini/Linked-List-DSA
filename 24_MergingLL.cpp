//merging two sorted list into one single sorted list

#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
}
*first=NULL,*second=NULL,*third=NULL;

void create1(int arr[],int n)
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

void create2(int arr[],int n)
{
    struct node *t,*last;
  
    second=(struct node *)malloc(sizeof(struct node));
    second->data=arr[0];
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=arr[i];
        t->next=NULL;
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

void merge(struct node *p,struct node *q)
{
    struct node *last;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }

    while(p&&q)
    {
       if(p->data<q->data)
       {
           last->next=p;
           last=p;
           p=p->next;
           last->next=NULL;
       }
       else
       {
           last->next=q;
           last=q;
           q=q->next;
           last->next=NULL;
       }
    }
    if(p)
      last->next=p;
    if(q)
      last->next=q;  
}


int main()
{
    int a1[]={23,45,67,88};
    int a2[]={33,89,90};


    create1(a1,4);
    cout<<"a1 :";
    display(first);

    create2(a2,3);
    cout<<"\na2 :";
    display(second); 

    merge(first,second);
    cout<<"\nAfter merging a1 and a2 :";
    display(third);
   
  return 0;
}