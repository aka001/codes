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
ll big;
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll find_length(ll n)
{
	int cnt=0;
	while(n!=0)
	{
		n/=10;
		cnt++;
	}
	return cnt;
}
ll arr[200];
ll calculate(ll a, ll sz, ll n, ll m)
{
	ll v1,v2,c=0,calc=a,cnt=0,ans=0,cit,n1,pit,cc;
	n1=n;
	arr[0]=0;
	while(n!=0)
	{
		v1=n%2;
		if(cnt==0)
			cit=a;
		else
			cit=(arr[cnt]*modpow(10,c,m))%m+arr[cnt];
		//printf("cnt=%lld c=%lld %lld\n",cnt,c,modpow(10,c,m));
		cit%=m;
		n/=2;
		c=sz*modpow(2,cnt,big);
		cnt++;
		arr[cnt]=cit;
	}
	n=n1;
	cnt=1;
	pit=0;
	calc=1;
	//printf("%lld %lld %lld\n",arr[1],arr[2],arr[3]);
	while(n!=0)
	{
		v1=n%2;
		if(v1==1)
		{
			cc=sz*pit;
			//pln(cc);
			//printf("cnt=%lld arr[cnt]=%lld modpow=%lld  %lld\n",cnt,arr[cnt],modpow(10,cc,m),arr[cnt]*modpow(10,cc,m));
			ans+=arr[cnt]*modpow(10,cc,m);
			ans%=m;
			pit+=calc;
		}
		calc*=2;
		cnt++;
		n/=2;
	}
	ans%=m;
	return ans;
}
int main()
{
	big=(ll)((ll)mod*(ll)mod);
	int t;
	ll a,n,m,sz,ans;
	si(t);
	while(t--)
	{
		sl(a);
		sl(n);
		sl(m);
		if(a==0)
			sz=1;
		else
			sz=find_length(a);
		ans=calculate(a,sz,n,m);
		pln(ans);
	}
	return 0;
}















