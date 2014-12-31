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
ll arr[100],brr[100];
int main()
{
	ll t,a,b,c,c1,c2,calc,ans,i,flag,j;
	sl(t);
	while(t--)
	{
		ans=0;
		calc=1;
		sl(a);
		sl(b);
		c1=c2=0;
		rep(i,32)
			arr[i]=brr[i]=0;
		while(a!=0)
		{
			arr[c1++]=a%2;
			a>>=1;
		}
		while(b!=0)
		{
			brr[c2++]=b%2;
			b>>=1;
		}
		c=max(c1,c2);
		rep(i,c)
		{
			if(!(arr[i]==0 || brr[i]==0))
			{
				//printf("i=%lld\n",i);
				flag=0;
				FOR(j,i+1,c)
				{
					if(arr[i]==brr[i] && arr[i]==1)
					{
						flag=1;
						break;
					}
					else if(arr[i]==0 && brr[i]==1)
					{
						flag=2;
						break;
					}
				}
				if(flag!=2)
				{
					ans+=calc;
				}
			}
			calc*=2;
		}
		pln(ans);
	}
	return 0;
}










