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
ll cit;
ll findabove(ll num)
{
	ll low=0,high=1000000000,mid,calc,calc1;
	high=high*high;
	while(low<=high)
	{
		mid=(low+high)/2;
		calc=cit*mid;
		calc1=cit*(mid-1);
		if(calc>=num && (calc1<num || mid==0))
		{
			return mid;
		}
		else if(num<calc)
			high=mid-1;
		else
			low=mid+1;
		//printf("low=%lld high=%lld mid=%lld num=%lld calc=%lld\n",low,high,mid,num,calc);
	}
	return -1;
}
ll findbelow(ll num)
{
	ll low=0,high=1000000000,mid,calc,calc1;
	high=high*high;
	high/=20;
	if(num<0)
		return 0;
	//high/=cit;
	//high++;
	while(low<=high)
	{
		mid=(low+high)/2;
		calc=(ll)cit*mid;
		calc1=(ll)cit*(mid+1);
		if(calc<=num && calc1>num)
		{
			//printf("mid here=%lld\n",mid);
			return mid;
		}
		else if(num<calc)
			high=mid-1;
		else
			low=mid+1;
		//printf("low=%lld high=%lld mid=%lld num=%lld calc=%lld\n",low,high,mid,num,calc);
	}
	//printf("asdflkjasdklfjaskldj\n");
	return 0;
}
int main()
{
	ll t,s,ans,calc,val,low,high,num,val1,val2;
	cit=42;
	sl(t);
	while(t--)
	{
		sl(s);
		/*s%=mod;
		calc%=mod;*/
		ans=s*2;
		low=0;
		high=ans;
		//num=findbelow(high)-findabove(low);
		//printf("high=%lld low=%lld num=%lld\n",findbelow(high),findabove(low),num);
		while(s>0)
		{
			val1=findbelow(high);
			val2=findbelow(low-1);
			num=val1-val2;
			//printf("low=%lld high=%lld val1=%lld val2=%lld num=%lld\n",low,high,val1,val2,num);
			s=num;
			low=high+1;
			high+=num*2;
		}
		high%=mod;
		pln(high);
	}
	return 0;
}









