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
ll pow2[100],cnt;
typedef struct node
{
	ll val,gap,rem;
}node;
node ans[1000006];
ll solve(ll n)
{
	ll low,high,mid;
	low=0;
	high=cnt-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(ans[mid].val<=n && (mid==cnt-1 || ans[mid+1].val>n))
		{
			return mid;
		}
		else if(n>=ans[mid].val)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main()
{
	ll i,j,calc=2,MAX,calc1,l,r,t,val1,val;
	cnt=2;
	MAX=(ll)mod*(ll)mod;
	ans[0].val=0;
	ans[0].gap=1;
	ans[0].rem=0;
	ans[1].val=10;
	ans[1].gap=2;
	ans[1].rem=10;
	while(1)
	{
		if(calc>=MAX)
			break;
		ans[cnt].val=calc*10;
		ans[cnt].gap=calc*2;
		ans[cnt].rem=ans[cnt-1].rem+5;
		cnt++;
		calc<<=1;
	}
	sl(t);
	while(t--)
	{
		sl(l);
		sl(r);
		calc=solve(l-1);
		if(calc!=-1)
			val=ans[calc].rem+(l-1-ans[calc].val)/ans[calc].gap;
		else
			val=0;
		calc1=solve(r);
		if(calc1!=-1)
			val1=ans[calc1].rem+(r-ans[calc1].val)/ans[calc1].gap;
		else
			val1=0;
		printf("val1=%lld rem1=%lld calc1=%lld valit=%lld gapit=%lld\n",val1,ans[calc1].rem,calc1,ans[calc1].val,ans[calc1].gap);
		val1-=val;
		pln(val1);
	}
	return 0;
}













