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
ll arr[1000006],sg[1000006];
void initialize(ll node, ll u, ll v)
{
	if(u==v)
	{
		arr[u]=0;
	}
	else
	{
		initialize(2*node, u, (u+v)/2);
		initialize(2*node+1, (u+v)/2+1, v);
	}
}
void update(ll node, ll p, ll q, ll a, ll b,ll v)
{
	if(p>b || q<a || p>q)
		return;
	if(p==q)
	{
		if(p>=a && q<=b)
			arr[node]+=v;
		//printf("here top p=%d q=%d arr[node]=%lld\n",p,q,arr[node]);
		arr[node]+=sg[node];
		sg[node]=0;
		return;
	}
	if(p>=a && q<=b)
	{
		arr[node]+=v*(q-p+1);
		//printf("here 1 p=%d q=%d arr[node]=%lld\n",p,q,arr[node]);
		sg[2*node]+=v;
		sg[2*node+1]+=v;
		return;
	}
	else if(p<a && q>=a && q<=b)
	{
		arr[node]+=v*(q-a+1);
		//printf("here 2 p=%d q=%d arr[node]=%lld\n",p,q,arr[node]);
	}
	else if(p>=a && p<=b && q>b)
	{
		arr[node]+=v*(b-p+1);
		//printf("here 3 p=%d q=%d arr[node]=%lld\n",p,q,arr[node]);
	}
	else if(p<=a && q>=b)
	{
		arr[node]+=v*(b-a+1);
		//printf("here 4 p=%d q=%d arr[node]=%lld\n",p,q,arr[node]);
	}
	update(2*node,p,(p+q)/2,a,b,v);
	update(2*node+1,(p+q)/2+1,q,a,b,v);
}
ll query(ll node, ll p, ll q, ll a, ll b)
{
	if(sg[node]!=0)
	{
		arr[node]+=sg[node]*(q-p+1);
		if(p!=q)
		{
			sg[2*node]+=sg[node];
			sg[2*node+1]+=sg[node];
		}
		sg[node]=0;
	}
	if(p>b || q<a)
		return 0;
	else if(p>=a && q<=b)
	{
		return arr[node];
	}
	else
	{
		ll p1,p2;
		p1=query(2*node, p, (p+q)/2, a, b);
		p2=query(2*node+1, (p+q)/2+1, q, a, b);
		return p1+p2;
	}
}
inline int returnit(ll n)
{
	return (!(n&(n-1)));
}
int main()
{
	std::ios_base::sync_with_stdio( false );
	ll n,i,t,c,val,val1,val2,val3,n1;
	ll calc;
	sl(t);
	while(t--)
	{
		sl(n);
		n1=n;
		rep(i,1000000)
		{
			sg[i]=0;
			arr[i]=0;
		}
		sl(c);
		initialize(1,0,n-1);
		rep(i,c)
		{
			sl(val);
			sl(val1);
			sl(val2);
			val1--;
			val2--;
			//printf("%d %d %d\n",val,val1,val2);
			if(val==0)
			{
				sl(val3);
				update(1,0,n-1,val1,val2,val3);
			}
			else
			{
				calc=query(1,0,n-1,val1,val2);
				pln(calc);
			}
		}
	}
	return 0;
}









