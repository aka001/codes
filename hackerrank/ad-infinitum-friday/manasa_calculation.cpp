/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/


#include<cstdio>
#include<iostream>
#include<cassert>
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
int brr[1000006],arr[1000006],fin[1000006],isprime[1000006];
inline ll check(ll n)
{
	if(n>=mod)
		n%=mod;
	return n;
}
inline ll checkneg(ll n)
{
	while(n<mod)
		n+=mod;
	n%=mod;
	return n;
}
void seive()
{
	ll i,MAX,j;
	MAX=100000;
	isprime[0]=1;
	isprime[1]=1;
	for(i=2;i<MAX;i++)
		isprime[i]=0;
	for(i=2;i<MAX;i++)
	{
		if(isprime[i]==0)
		{
			j=i*i;
			for(;j<MAX;j+=i)
				isprime[j]=1;
		}
	}
}
int main()
{
	ll ans=1,calc,p,b,a,n,i,cal1,cal2,cal,flag;
	seive();
	rep(i,5001)
	{
		arr[i]=brr[i]=0;
	}
	sl(n);
	while(n--)
	{
		sl(p);
		sl(b);
		sl(a);
		//assert(p<=5000);
		brr[p]=b;
		arr[p]=a;
		fin[p]=a-b;
	}
	calc=1;
	for(i=2;i<=5000;i++)
	{
		if(brr[i]>0)
		{
			//printf("i=%lld brr=%d\n",i,brr[i]);
			/*cal1=modpow(i,brr[i]+1,mod)*modpow(i-1,mod-2,mod);
			cal1=check(cal1);
			cal2=modpow(i-1,mod-2,mod);
			cal=cal1-cal2;
			cal=checkneg(cal);*/
			cal=modpow(i,brr[i],mod);
			calc*=cal;
			calc=check(calc);
		}
	}
	//pln(calc);
	flag=0;
	for(i=2;i<=5000;i++)
	{
		if(fin[i]>0)
		{
			flag=1;
			cal1=modpow(i,fin[i],mod);
			cal1+=1;
			cal1=check(cal1);
			calc*=cal1;
			calc=check(calc);
			/*cal1=modpow(i,fin[i]+1,mod)-1;
			cal1=checkneg(cal1);
			cal2=modpow(i-1,mod-2,mod);
			cal1*=cal2;
			cal1=check(cal1);
			calc*=cal1;
			calc=check(calc);*/
		}
	}
	/*cal=modpow(2,mod-2,mod);
	calc*=cal;*/
	if(flag==0)
		calc*=2;
	calc=checkneg(calc);
	pln(calc);
	return 0;
}







