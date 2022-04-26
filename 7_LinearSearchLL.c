//binary search is not suitable because we cannot go the mid value directly.


#include<stdio.h>
#include<stdlib.h>

struct node 
{
 int data;
 struct node *next;

}

*first=NULL;

void create(int arr[],int n)
{
  int i;
  struct node *t,*last;
  
  first=(struct node *)malloc(sizeof(struct node));

  first->data=arr[0];
  first->next=NULL;
  last=first;

  for(i=1;i<n;i++)
  {
      t=(struct node *)malloc(sizeof(struct node));
      t->data=arr[i];
      t->next=NULL;
      last->next=t;
       last=t;
  }

}

struct node * search(struct node *p,int key)
{
  while(p!=NULL)
  {
    if(key==p->data)
        return p;

      p=p->next;
  }
  return 0;
}

/*
RECURSIVE FUNCTION :

struct node * search(struct node *p,int key)
{
    if(p==NULL)
          return NULL;
   else
       if(key==p->data)
                   return p;
   
        return search(p->next,key);
}


*/


int main()
{
    int a[]={33,45,87,99,11};
    
    struct node *temp;

    create(a,5);

    temp=search(first,85);

    if(temp!=NULL)
      printf("key is found.\n",temp->data);
    else
        printf("key is not found.\n");

    return 0;
}