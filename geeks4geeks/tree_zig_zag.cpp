#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
stack<node*> s1,s2;
queue<node*> s3;
node* insert(node *stit,int val)
{
	if(stit==NULL)
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->data=val;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else
	{
		if(val<stit->data)
			stit->left=insert(stit->left,val);
		else
			stit->right=insert(stit->right,val);
		return stit;
	}
}
node* max(node *stit)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	while(stit!=NULL)
	{
		temp=stit;
		stit=stit->right;
	}
	return temp;
}
node* min(node *stit)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	while(stit!=NULL)
	{
		temp=stit;
		stit=stit->left;
	}
	return temp;
}
node* search(node *stit, int value)
{
	if(stit->data==value)
		return stit;
	else if(stit->right!=NULL && value>stit->data)
		search(stit->right,value);
	else if(stit->left!=NULL && value<stit->data)
		search(stit->left,value);
	else
		return NULL;
}
void inorder(node *stit)
{
	if(stit==NULL)
		return;
	inorder(stit->left);
	printf("%d ",stit->data);
	inorder(stit->right);
}
node* delit(node *stit, int value)
{
	if(stit==NULL)
		return stit;
	if(value>stit->data)
	{
		stit->right=delit(stit->right,value);
		return stit;
	}
	else if(value<stit->data)
	{
		//printf("%d\n",stit->data);
		stit->left=delit(stit->left,value);
		return stit;
		/*if(stit->data==4)
			printf("%d\n",stit->left->data);*/
	}
	else
	{
		if(stit->left==NULL)
		{
			node *temp=stit->right;
			free(stit);
			return temp;
		}
		else if(stit->right==NULL)
		{
			node *temp=stit->left;
			free(stit);
			return temp;
		}
		else
		{
			node *doit;
			doit=(node*)malloc(sizeof(node));
			doit=max(stit->left);
			stit->data=doit->data;
			stit->left=delit(stit->left,doit->data);
			return stit;
		}
	}
}
void zigzag(int level)
{
	if(s1.empty() && s2.empty())
		return;
	if(level==1)
	{
		while(!(s1.empty()))
		{
			node *tree;
			tree=s1.top();
			printf("%d ",tree->data);
			if(tree->left!=NULL)
				s2.push(tree->left);
			if(tree->right!=NULL)
				s2.push(tree->right);
			s1.pop();
		}
	}
	else
	{
		while(!(s1.empty()))
		{
			node *tree;
			tree=s1.top();
			printf("%d ",tree->data);
			if(tree->right!=NULL)
				s1.push(tree->right);
			if(tree->left!=NULL)
				s1.push(tree->left);
			s1.pop();
		}
	}
	zigzag(1-level);
}
void levelorder()
{
	while(!(s3.empty()))
	{
		node *tree;
		tree=s3.front();
		printf("%d ",tree->data);
		s3.pop();
		if(tree->left!=NULL)
			s3.push(tree->left);
		if(tree->right!=NULL)
			s3.push(tree->right);
	}
}
int main()
{
	int n,i,val,inst,valit,q;
	node *head;
	head=(node*)malloc(sizeof(node));
	head=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		head=insert(head,val);
	}
	/*s1.push(head);
	  while(1)
	  {
	  if(s1.empty() && s2.empty())
	  break;
	  if(!(s1.empty()))
	  {
	  while(!(s1.empty()))
	  {
	  node *tree;
	  tree=s1.top();
	  s1.pop();
	  printf("%d ",tree->data);
	  if(tree->left!=NULL)
	  s2.push(tree->left);
	  if(tree->right!=NULL)
	  s2.push(tree->right);
	  }
	  }
	  else
	  {
	  while(!(s2.empty()))
	  {
	  node *tree;
	  tree=s2.top();
	  s2.pop();
	  printf("%d ",tree->data);
	  if(tree->right!=NULL)
	  s1.push(tree->right);
	  if(tree->left!=NULL)
	  s1.push(tree->left);
	  }
	  }
	  }
	  printf("\n");*/
	//printf("%d\n",s1.top()->data);
	//s1.push(head);
	scanf("%d",&q);
	//printf("%d\n",q);
	while(q--)
	{
		scanf("%d",&inst);
		//printf("inst=%d\n",inst);
		if(inst==1)
		{
			scanf("%d",&valit);
			delit(head,valit);
		}
		else if(inst==2)
		{
			/*while(!(s3.empty()))
			  s3.pop();
			  s3.push(head);
			  levelorder();*/
			inorder(head);
			printf("\n");
		}
		else
			break;
	}
	return 0;
}















