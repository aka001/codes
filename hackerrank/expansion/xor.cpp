/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	akash.agrawall094@gmail.com
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
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
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
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n)
#define pdl(n) printf("%lf\n",n)
#define pin(n) printf("%d\n",n)
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define bits 60 

long long int gcd(long long int a,long long int b)
{
	long long int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

void seive()
{
	int i,j;
	int MAX=1000006;
	int isprime[1000006]; 
	isprime[0] = isprime[1] = 1; 
	for (i = 4; i < MAX; i += 2)
		isprime[i] = 1; 
	for (i = 3; i * i < MAX; i += 2) 
	{
		if (!isprime[i]) 
		{
			for (j = i * i; j < MAX; j += 2 * i)
				{
					isprime[j] = 1; 
				}
		}
	}
}
ll powerit(ll a, ll b)
{
	ll x=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			x*=a;
			if(x>=mod)
				x%=mod;
		}
		a=a*a;
		if(a>=mod)
			a%=mod;
		b>>=1;
	}
	printf("\n");
	return x;
}
typedef struct node
{
	ll val;
	ll bit;
	struct node *left;
	struct node *right;
}node;
int binary[bits];
void generatetrie(ll n, node *root)
{
	int i;
	rep(i,bits)
	{
		binary[bits-i-1]=n&01;
		n>>=1;
	}
	node *p=root;
	rep(i,bits)
	{
		if(binary[i]==0)
		{
			if(!p->left)
			{
				node *q=(node*)malloc(sizeof(node));
				q->val=0;
				q->bit=bits-i-1;
				//if(i==0)
				//	printf("q->bit =%lld\n",q->bit);
				p->left=(node*)malloc(sizeof(node));
				p->left=q;
			}
			//printf("left %lld %lld\n",p->left->val,p->left->bit);
			p=p->left;
		}
		else
		{
			if(!p->right)
			{
				node *q=(node*)malloc(sizeof(node));
				q->val=1;
				q->bit=bits-i-1;
				p->right=(node*)malloc(sizeof(node));
				p->right=q;
			}
			//printf("right %lld %lld\n",p->right->val,p->right->bit);
			p=p->right;
		}
	}
}
ll generatemax(node *p, node *q, node *head)
{
	ll value;
	if(p==head)
	{
		if(p->left && p->right)
		{
			//printf("hie\n");
			return (generatemax(p->left,p->right,head));
		}
		else if(p->left)
		{
			return (generatemax(p->left,p->left,head));
		}
		else
		{
			return (generatemax(p->right,q->right,head));
		}
	}
	//printf("bitit=%lld\n",p->bit);
	if(p->bit == 0)
	{
		//printf("%lld\n",p->val);
		return p->val^q->val;
	}
	ll x=1<<(p->bit);
	value=x*(p->val^q->val);
	//printf("value=%lld\n",value);
	if((p->left && q->right) || (p->right && q->left))
	{
		ll x1=0,x2=0;
		if(p->left && q->right)
		{
			x1=value+generatemax(p->left,q->right,head);
		}
		if(p->right && q->left)
			x2=value+generatemax(p->right,q->left,head);
		return max(x1,x2);
	}
	if(!(p->left) && !(q->left))
		return value+generatemax(p->right,q->right,head);
	return value+generatemax(p->left,q->left,head);
}
int main()
{
	int t,n,i,a,b;
	ll answer;
	{
		si(a);si(b);
		node *head;
		head=(node*)malloc(sizeof(node));
		b++;
		FOR(i,a,b)
		{
			generatetrie(i,head);
		}
		answer=0;
		answer=generatemax(head,head,head);
		//printf("bit value=%d\n",head->left->bit);
		pln(answer);
	}
	return 0;
}







