//Reverse a linked list

#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head;
void insert(int val)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=val;
	if(head==NULL)
	{
		temp->next=NULL;
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}
void reverse(node *calc, node *calc1)
{
	if(calc1==NULL)
		return;
	reverse(calc1,calc1->next);
	//printf("%d %d\n",calc1->data, calc->data);
	if(calc1==calc)
		calc1->next=NULL;
	else
		calc1->next=calc;
}
int main()
{
	int n,val,i;
	head=(node*)malloc(sizeof(node));
	head=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		insert(val);
	}
	node *temp,*last;
	temp=(node*)malloc(sizeof(node));
	last=(node*)malloc(sizeof(node));
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		last=temp;
		temp=temp->next;
	}
	printf("\n");
	reverse(head,head);
	while(last!=NULL)
	{
		printf("%d ",last->data);
		last=last->next;
	}
	printf("\n");
}









