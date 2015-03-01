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
ll arr[1000006];
int main()
{
	ll n,i,sum=0,s=0,c1,c2,c3,ans,s1,s2;
	sl(n);
	rep(i,n)
	{
		sl(arr[i]);
		arr[i]+=mod-2;
		sum+=arr[i];
	}
	assert(n>2);
	if(n<=2 || sum%3!=0)
	{
		printf("0\n");
	}
	else
	{
		c1=c2=c3=0;
		rep(i,n)
		{
			s+=arr[i];
			s1=sum/3;
			s2=2*s1;
			if(s==s1)
				c1++;
			else if(s==s2)
				c2++;
			else if(s==sum)
				c3++;
		}
		if(sum==0)
		{
			c1--;
			ans=(c1*(c1-1))/2;
		}
		else
		{
			if(c3!=0)
				ans=c1*c2;
			else
				ans=0;
		}
		pln(ans);
	}
	return 0;
}














