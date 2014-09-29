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
map<ll,ll> mpit;
ll arr[1000006];
int main()
{
	ll n,i,val=0,val1,val2;
	sl(n);
	rep(i,n)
	{
		sl(arr[i]);
		mpit[arr[i]]++;
	}
	sort(arr,arr+n);
	rep(i,n)
	{
		if(mpit[arr[i]]==1)
		{
			val1=arr[i+1]-arr[i];
			val2=arr[i]-arr[i-1];
			if(val1<0)
				val1*=-1;
			if(val2<0)
				val2*=-1;
			//printf("arr[i]=%lld val1=%lld val2=%lld i=%lld\n",arr[i],val1,val2,i);
			if(i==0)
				val2=mod;
			else if(i==n-1)
				val1=mod;
			val+=min(val1,val2);
			if(val1<val2)
			{
				mpit[arr[i]]--;
				arr[i]=arr[i+1];
				mpit[arr[i+1]]++;
			}
			else
			{
				mpit[arr[i]]--;
				arr[i]=arr[i-1];
				mpit[arr[i-1]]++;
			}
		}
	}
	val+=arr[n-1]-arr[n-2];
	pln(val);
	return 0;
}






