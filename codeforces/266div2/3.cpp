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
#define FOR(i,a,b) for(int i= a ; i < b ; ++i)
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
ll arr[1000006],cum[1000006];
vector<ll> fir,sec;
int main()
{
	int n;
	ll sum=0,cnt=0,cnt1=0,ans,low,high,mid,sizeit,sizeit1,val;
	si(n);
	rep(i,n)
	{
		sl(arr[i]);
		sum+=arr[i];
		cum[i]=sum;
	}
	if(sum%3!=0)
	{
		printf("0\n");
	}
	else if(sum==0)
	{
		rep(i,n)
		{
			if(cum[i]==0)
				cnt++;
		}
		cnt=((cnt-1)*(cnt-2))/2;
		printf("%lld\n",cnt);
	}
	else
	{
		rep(i,n-1)
		{
			if(cum[i]==sum/3)
			{
				fir.pb(i);
			}
			if(cum[i]==2*sum/3)
			{
				sec.pb(i);
			}
		}
		sort(fir.begin(),fir.end());
		sort(sec.begin(),sec.end());
		sizeit=fir.size();
		sizeit1=sec.size();
		//printf("sizeit=%lld sizeit1=%lld\n",sizeit,sizeit1);
		ans=0;
		rep(i,sizeit)
		{
			val=fir[i];
			//printf("val=%lld\n",val);
			low=0;
			high=sizeit1;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(mid==0 || (sec[mid]>=fir[i] && sec[mid-1]<fir[i]))
				{
					if(sec[mid]>=fir[i])
						ans+=sizeit1-mid;
					break;
				}
				else if(sec[mid]>fir[i])
					high=mid-1;
				else
					low=mid+1;
			}
		}
		pln(ans);
	}
	return 0;
}








