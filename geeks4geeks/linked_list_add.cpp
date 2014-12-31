//Reverse a linked list

#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}node;
node* insert(node *nodeit,int val)
{
	if(nodeit==NULL)
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->data=val;
		temp->next=NULL;
		return temp;
	}
	else
	{
		nodeit->next=insert(nodeit->next,val);
		return nodeit;
	}
}
void reverse_first_k(node *nodeit,node *nodeit1,int cnt,node *last)
{
	if(nodeit1==NULL || cnt==0)
	{
		return;
	}
	reverse_first_k(nodeit1,nodeit1->next,cnt-1,last);
	if(nodeit==nodeit1)
	{
		nodeit->next=last;
		printf("here %d\n",last->data);
	}
	else
	{
		printf("itit %d %d\n",nodeit1->data,nodeit->data);
		nodeit1->next=nodeit;
	}
}
int carry;
void add_linked_list(node *node1,node *node1_next,node *node2, node *node2_next)
{
	if(node1_next==NULL || node2_next==NULL)
		return;
	add_linked_list(node1_next,node1_next->next,node2_next,node2_next->next);
	node1_next->data=node1_next->data + node2_next->data+carry;
	if(node1!=node1_next)
	{
		carry=node1_next->data/10;
		node1_next->data%=10;
	}
}
int main()
{
	int n1,val,i,n2,k;
	node *head1,*head;
	head=(node*)malloc(sizeof(node));
	head1=(node*)malloc(sizeof(node));
	head=NULL;
	head1=NULL;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		scanf("%d",&val);
		head=insert(head,val);
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

	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
		scanf("%d",&val);
		head1=insert(head1,val);
	}
	temp=head1;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		last=temp;
		temp=temp->next;
	}
	printf("\n");
	carry=0;
	add_linked_list(head,head,head1,head1);
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
	return 0;
	/*scanf("%d",&k);
	node *newhead;
	temp=head;
	for(i=1;i<=k;i++)
	{
		newhead=temp;
		temp=temp->next;
	}
	//printf("value=%d %d\n",temp->data,head->data);
	node *temp1;
	temp1=head;
	reverse_first_k(head,head,k,temp);
	temp1->next=temp;
	temp=newhead;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");*/
}









