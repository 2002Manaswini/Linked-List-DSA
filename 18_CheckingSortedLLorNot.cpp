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

    for(int i=0;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int sorted(struct node *p)
{
  int x=INT16_MIN;
  
  while(p!=NULL)
   {
     if(p->data<x)
               return 0;//not sorted

     x=p->data;
     p=p->next;
   }
   return 1; //sorted
}


int main()
{
    int arr[]={23,40,66,87,90};
    create(arr,5);
    cout<<sorted(first);
    return 0;
}