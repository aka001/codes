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
 
vector<int> primeit;
void seive()
{
	int i,j;
	int MAX=1000006;
	int isprime[1000006]; 
	isprime[0] = isprime[1] = 1; 
	primeit.pb(2);
	for (i = 4; i < MAX; i += 2)
		isprime[i] = 1; 
	for (i = 3; i * i < MAX; i += 2) 
	{
		if (!isprime[i]) 
		{
			for (j = i * i; j < MAX; j += 2 * i)
				{
					isprime[j] = 1; 
				}
			primeit.pb(i);
		}
	}
}
ll arr[1000009],flagit[1000009],temp[1000009],val[1000009],ans[1000009];
ll powerit(ll a, ll b)
{
	ll x=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			x*=a;
			if(x>=mod)
				x%=mod;
		}
		a=a*a;
		if(a>=mod)
			a%=mod;
		b>>=1;
	}
	if(x>=mod)
		x%=mod;
	return x;
}
int main()
{
	ll t,n,i,x,y,j;
	ll calcit,i1,sqrtit,calc,cnt,cnt1;
	seive();
	sl(t);
	while(t--)
	{
		calcit=1;
		cnt=0;
		cnt1=0;
		sl(n);
		rep(i,n+1)
			flagit[i]=0;
		FOR(i,1,n+1)
		{
			sl(arr[i]);
		}
		FOR(i,1,n+1)
		{
			cnt=0;
			if(flagit[arr[i]]==0)
			{
				flagit[arr[i]]=1;
				x=arr[i];
				y=arr[x];
				cnt=1;
				while(y!=x)
				{
					flagit[y]=1;
					y=arr[y];
					cnt++;
				}
				val[cnt1++]=cnt;
			}
		}
		sort(val,val+cnt1);
		cnt=0;
		rep(i,cnt1)
		{
			if(i==n-1 || val[i]!=val[i+1])
			{
				temp[cnt++]=val[i];
			}
		}
		rep(i,10000)
			ans[i]=0;
		rep(i,cnt)
		{
			//printf("temp=%d\n",temp[i]);
			sqrtit=sqrt(temp[i]);
			calc=temp[i];
			j=0;
			while(primeit[j]<=sqrtit)
			{
				if(calc%primeit[j]==0)
				{
					cnt1=1;
					calc/=primeit[j];
					while(calc%primeit[j]==0 && calc>=primeit[j])
					{
						calc/=primeit[j];
						cnt1++;
					}
					ans[primeit[j]]=max(ans[primeit[j]],cnt1);
				}
				j++;
			}
			if(calc!=1)
			{
				if(1>ans[calc])
				{
					ans[calc]=1;
				}
			}
		}
		rep(i,168)
		{
			i1=primeit[i];
			if(ans[i1]!=0)
			{
				if(calcit>=mod)
					calcit%=mod;
				calcit=(ll)calcit*(ll)powerit(i1,ans[i1]);
				if(calcit>=mod)
					calcit%=mod;
				//printf("ans[i1]=%lld i1=%lld calcit=%lld\n",ans[i1],i1,calcit);
			}
		}
		calcit%=mod;
		pln(calcit);
	}
	return 0;
}
