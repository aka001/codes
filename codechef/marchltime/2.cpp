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
vector<pair<ll,pair<ll,ll> > > arr;
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
ll possible(ll val)
{
	ll i,sz,flag=1,calc;
	calc=val;
	sz=arr.size();
	rep(i,sz)
	{
		if(arr[i].S.S==-1)
		{
			calc-=arr[i].S.F;
			if(calc<=0)
			{
				flag=0;
				break;
			}
		}
		else
		{
			if(calc>=arr[i].S.F)
				calc+=arr[i].S.S;
		}
	}
	if(calc<=0)
		flag=0;
	//pln(flag);
	return flag;
}
ll find_val()
{
	ll low=1,high=(ll)((ll)mod * (ll)mod),mid,mit,v1,v2;
	while(low<=high)
	{
		mid=(low+high)/2;
		mit=mid-1;
		v1=possible(mid);
		v2=possible(mit);
		//printf("mid=%lld v1=%lld  mit=%lld v2=%lld\n",mid,v1,mit,v2);
		if((v1 && mid==1) || (v1 && v2==0))
			return mid;
		else if(v1==0)
			low=mid+1;
		else
			high=mid-1;
	}
}
int main()
{
	ll t,x,b,ans=0,c,l,i,p,q,r,e,f,sz;
	pair<ll, pair<ll,ll> > calc;
	sl(t);
	while(t--)
	{
		arr.clear();
		sl(x);
		sl(b);
		rep(i,b)
		{
			sl(e);
			sl(f);
			calc.F=e;
			calc.S=mp(f,-1);
			arr.pb(calc);
		}
		sl(c);
		rep(i,c)
		{
			sl(p);
			sl(q);
			sl(r);
			calc.F=p;
			calc.S=mp(q,r);
			arr.pb(calc);
		//	nit[i]=mp(q,r);
		}
		sz=arr.size();
		sort(arr.begin(),arr.end());
		ans=find_val();
		pln(ans);
	}
	return 0;
}





