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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}

ll arr[1000006],tree[1000006],tree1[1000006],n;
void update(ll newit[1000006],ll x, ll val)
{
	while(x<=n)
	{
		newit[x]+=val;
		//printf("x=%lld val=%lld\n",x,val);
		x+=(x&(-x));
	}
}
void updatetree(ll x, ll y,ll val)
{
	update(tree,x,val);
	update(tree,y+1,-val);
	update(tree1,x,(x-1)*val);
	update(tree1,y+1,-y*val);
}
ll findsum(ll newit[1000006],ll x)
{
	ll sum=0;
	while(x>0)
	{
		sum+=newit[x];
		//printf("x=%lld tree=%lld sum=%lld\n",x,tree[x],sum);
		x-=(x&(-x));
	}
	return sum;
}
ll query(ll x)
{
	ll val1=findsum(tree,x)*x-findsum(tree1,x);
	return val1;
}
int main()
{
	ll t,i,val,p,q,v,c,ans,val1,val2;
	sl(t);
	while(t--)
	{
		sl(n);
		sl(c);
		rep(i,n+1)
		{
			tree[i]=0;
			tree1[i]=0;
		}
		rep(i,c)
		{
			sl(val);
			if(val==0)
			{
				sl(p);
				sl(q);
				sl(v);
				//printf("v=%lld\n",v);
				updatetree(p,q,v);
			}
			else
			{
				sl(p);
				sl(q);
				//printf("q=%lld\n",q);
				val1=query(q);
				//printf("p-1=%lld\n",p-1);
				if(p==1)
					val2=0;
				else
					val2=query(p-1);
				//printf("val1=%lld val2=%lld\n",val1,val2);
				ans=val1-val2;
				pln(ans);
			}
		}
		/*rep(i,n)
			printf("tree[%lld]=%lld\n",i,tree[i]);*/
	}
	return 0;
}




