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
	int odd;
	int even;
	int sum;
}node;
node arr[1000006];
int val[1000006];
void initialize(int node, int l, int e)
{
	if(l==e)
	{
		arr[node].sum=val[l];
		if(val[l]%2==1)
		{
			arr[node].odd=1;
			arr[node].even=0;
		}
		else
		{
			arr[node].odd=0;
			arr[node].even=1;
		}
	}
	else
	{
		initialize(2*node,l,(l+e)/2);
		initialize(2*node+1,(l+e)/2+1,e);
		arr[node].odd=arr[2*node].odd+arr[2*node+1].odd;
		arr[node].even=arr[2*node].even+arr[2*node+1].even;
		arr[node].sum=arr[2*node].sum+arr[2*node+1].sum;
	}
}
void update(int node, int b, int e)
{
	if(b==e)
	{
		if(b>=x && b<=y)
		{
		if(q==1)
		{
			arr[node].odd+=arr[node].even;
			arr[node].sum+=arr[node].even;
			arr[node].even=0;
		}
		else if(q==2)
		{
			arr[node].even+=arr[node].odd;
			arr[node].sum+=arr[node].odd;
			arr[node].odd=0;	
		}
		else if(q==3)
		{
			int temp;
			temp=arr[node].even;
			arr[node].even=arr[node].odd;
			arr[node].odd=temp;
			arr[node].sum+=arr[node].even+arr[node].odd;
		}
		}
	}
	else 
	{
		update(2*node,b,(b+e)/2,x,y,q);
		update(2*node+1,(b+e)/2+1,e,x,y,q);
		arr[node].odd=arr[2*node].odd+arr[2*node+1].odd;
		arr[node].even=arr[2*node].even+arr[2*node+1].even;
		arr[node].sum=arr[2*node].sum+arr[2*node+1].sum;
	}
}
int sum(int node,int b,int e,int x,int y)
{
	if(b>y || e<x)
		return 0;
	else if(b>=x && e<=y)
		return arr[node].sum;
	else
	{
		int p1,p2;
		p1=sum(2*node,b,(b+e)/2,x,y);
		p2=sum(2*node+1,(b+e)/2+1,e,x,y);
		return p1+p2;
	}
}
int main()
{
	int n,i,q,calc,l,r,qit;
	char ch;
	si(n);
	rep(i,n)
	{
		si(val[i]);
	}
	initialize(1,0,n-1);
	si(q);
	rep(i,q)
	{
		cin>>ch;
		cin>>l;
		cin>>r;
		l--;
		r--;
		getchar();
		if(ch=='O' || ch=='E' || ch=='I')
		{
			if(ch=='O')
			{
				qit=1;
			}
			else if(ch=='E')
			{
				qit=2;
			}
			else if(ch=='I')
			{
				qit=3;
			}
			//printf("ch=%c l=%d r=%d n=%d\n",ch,l,r,n);
			update(1,0,n-1,l,r,qit);
		}
		else
		{
			calc=sum(1,0,n-1,l,r);
			pin(calc);
		}
	}
	return 0;
}

















