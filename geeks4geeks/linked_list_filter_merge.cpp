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
	struct node *next;
}node;
node* insert(node *head, int val)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->value=val;
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
	return head;
}
node* print(node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->value);
		head=head->next;
	}
	printf("\n");
}
node *first1,*first2,*first3;
void merge(node *head,node *filter1, node *filter2, node *filter3)
{
	while(head!=NULL)
	{
		if(head->value>=0 && head->value<10)
		{
			if(filter==
		}
	}
}
int main()
{
	int n,i,val;
	si(n);
	node *head;
	head=(node*)malloc(sizeof(node));
	head=NULL;
	rep(i,n)
	{
		si(val);
		head=insert(head,val);
	}
	print(head);
	node *filter1,*filter2,*filter3;
	filter1=(node*)malloc(sizeof(node));
	filter2=(node*)malloc(sizeof(node));
	filter3=(node*)malloc(sizeof(node));
	filter1=filter2=filter3=NULL;
	merge(head,filter1,filter2,filter3);
	return 0;
}












