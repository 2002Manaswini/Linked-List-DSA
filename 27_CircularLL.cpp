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

/*
display function using recursion :

void display(struct node *p)
{
  static int flag=0;
    if(p!=head || flag=0)
    {
        flag=1;
        cout<<p->data<<" ";
        display(p->next);
    }
}

*/

int main()
{
    int a[]={23,45,12,78,90};
    create(a,5);
    display(head);
    return 0;
}