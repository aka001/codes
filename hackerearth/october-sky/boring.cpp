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
#define MAX 1000006
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int isprime[1000006];
vector<int> primeit;
ll ansit[1000006];
void seive()
{
	ll i,j;
	isprime[0]=1;
	isprime[1]=1;
	for(i=2;i<MAX;i++)
	{
		if(isprime[i]==0)
		{
			for(j=i*i;j<MAX;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
	for(i=2;i<MAX;i++)
	{
		if(isprime[i]==0)
			primeit.pb(i);
	}
}
ll ans[1000006];
int main()
{
	int i,sizeit,calc,calc1,t,akash,A,B,cnt;
	ll ansit;
	seive();
	sizeit=primeit.size();
	ans[0]=0;
	for(i=1;i<=1000000;i++)
	{
		calc=i;
		calc1=sqrt(i);
		cnt=0;
		akash=0;
		while(primeit[cnt]<=calc1 && cnt<sizeit)
		{
			if(calc%primeit[cnt]==0)
			{
				while(calc%primeit[cnt]==0)
				{
					akash++;
					calc/=primeit[cnt];
				}
			}
			cnt++;
		}
		if(isprime[calc]==0)
			akash++;
		ans[i]=ans[i-1]+akash;
	}
	si(t);
	while(t--)
	{
		si(A);
		si(B);
		ansit=ans[B]-ans[A-1];
		pln(ansit);
	}
	return 0;
}

















