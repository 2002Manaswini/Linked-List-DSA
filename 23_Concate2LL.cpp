//time taken ----> o(n)


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

void concat(struct node *p,struct node *q)
{
    third=p;
   while(p->next!=NULL)
   {
     p=p->next;
   }
  p->next=q;
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

    concat(first,second);
    cout<<"\nAfter concating a1 and a2 :";
    display(third);
   
  return 0;
}