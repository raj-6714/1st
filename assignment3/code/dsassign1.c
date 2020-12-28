#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
int i;
struct Node *t,*last;
first=(struct Node *)malloc(sizeof(struct Node));
first->data=A[0];
first->next=NULL;
last=first;
for(i=1;i<n;i++)
{
t=(struct Node*)malloc(sizeof(struct Node));
t->data=A[i];
t->next=NULL;
last->next=t;
last=t;
}
}
void Display(struct Node *p)
{
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
}
//given insert function can insert at befor first node(position=0) after first node(position=1)and so on
// element: 6 7 8 9
//position:0 1 2 3 4
//you have to give position aacordingly
int count(struct Node *p){
    int c=0;
    while(p!=0){
        c++;
        p=p->next;
    }
    return c;
}
void Insert(struct Node *p,int index,int x)
{
struct Node *t;
int i;
if(index < 0 || index > count(p))
return;
t=(struct Node *)malloc(sizeof(struct Node));
t->data=x;
if(index == 0)
{
t->next=first;
first=t;
}
else
{
for(i=0;i<index-1;i++)
p=p->next;
t->next=p->next;
p->next=t;
}
}
int main()
{
int A[]={160,20,30,40,50};
create(A,5);
Insert(first,0,5);
Display(first);
//int k= count(first);

return 0;
}

