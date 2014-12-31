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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int pr[10000];
int findparent(int node)
{
	if(pr[node]==node)
		return node;
	findparent(pr[node]);
	pr[node]=pr[pr[node]];
}
int main()
{
	int t,p,n,m,a,b,c,i,ans,c2,c1,cnt;
	si(t);
	while(t--)
	{
		cnt=0;
		pair<int,int> calc;
		ans=0;
		si(p);
		si(n);
		si(m);
		vector<pair<int,pair<int,int> > > arr;
		rep(i,n+1)
			pr[i]=i;
		rep(i,m)
		{
			si(a);
			si(b);
			si(c);
			arr.pb(mp(c,mp(a,b)));
		}
		sort(arr.begin(),arr.end());
		i=0;
		while(1)
		{
			calc=arr[i].S;
			c1=findparent(calc.F);
			c2=findparent(calc.S);
			//printf("c1=%d c2=%d  %d %d\n",c1,c2,calc.F,calc.S);
			if(c1!=c2)
			{
				pr[c2]=c1;
				ans+=arr[i].F;
				cnt++;
			}
			if(cnt==n-1)
				break;
			i++;
		}
		ans*=p;
		pin(ans);
	}
	return 0;
}


















