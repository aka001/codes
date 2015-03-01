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
#include<cassert>
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
int sg[1000006],arr[1000006];
void init(int node,int a,int b)
{
	if(a==b)
	{
		sg[node]=arr[a];
	}
	else
	{
		int c1,c2,ans;
		init(2*node,a,(a+b)/2);
		init(2*node+1,(a+b)/2+1,b);
		c1=sg[2*node];
		c2=sg[2*node+1];
		sg[node]=max(c1,c2);
	}
}
int query(int node,int a,int b,int x,int y)
{
	if(x>=a && y<=b)
		return sg[node];
	else if(y<a || x>b || x>y)
		return -mod;
	else
	{
		int c1,c2,ans;
		c1=query(2*node,a,b,x,(x+y)/2);
		c2=query(2*node+1,a,b,(x+y)/2+1,y);
		ans=max(c1,c2);
		return ans;
	}
}
int main()
{
	int n,i,q,a,b,val;
	si(n);
	rep(i,n)
		si(arr[i]);
	init(1,0,n-1);
	si(q);
	rep(i,q)
	{
		si(a);
		si(b);
		a--;
		b--;
		assert(a!=n-1);
		assert(b>a);
		if(b==a+1)
			printf("YES\n");
		else
		{
			val=query(1,a+1,b-1,0,n-1);
			//printf("a=%d b=%d val=%d\n",a+1,b-1,val);
			if(val>arr[a])
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}












