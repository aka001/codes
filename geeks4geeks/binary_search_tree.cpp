/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	***********************/


#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 

typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
}node;

node* insert(node *tree_node,int val)
{
	if(tree_node==NULL)
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->value=val;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else if(val>tree_node->value)
	{
		tree_node->right=insert(tree_node->right,val);
		return tree_node;
	}
	else
	{
		tree_node->left=insert(tree_node->left,val);
		return tree_node;
	}
}
int ans=0;
void output(node *head, int value)
{
	if(head->left==NULL && head->right==NULL)
	{
		value=value*10+head->value;
		pin(value);
		ans+=value;
	}
	if(head->left!=NULL)
	{
		output(head->left,value*10+head->value);
	}
	if(head->right!=NULL)
	{
		output(head->right,value*10+head->value);
	}
}
void inorder(node *tree_node)
{
	if(tree_node==NULL)
		return;
	inorder(tree_node->left);
	pin(tree_node->value);
	inorder(tree_node->right);
}
int main()
{
	int n,i,val;
	node *head;
	head=(node*)malloc(sizeof(node));
	head=NULL;
	si(n);
	rep(i,n)
	{
		si(val);
		head=insert(head,val);
	}
	//inorder(head);
	output(head,0);
	pin(ans);
	return 0;
}











