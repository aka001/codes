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
#define ll long long
#define MAX 1000006
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
#define mit 1000006
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
int isprime[MAX];
vector<int> primeit;
void seive()
{
	ll i,j;
	isprime[0]=1; isprime[1]=1;
	FOR(i,2,MAX)
	{
		if(isprime[i]==0)
		{
			j=i*i;
			for(;j<MAX;j+=i)
				isprime[j]=1;
		}
	}
	rep(i,1000)
		if(isprime[i]==0)
			primeit.pb(i);
}
int arr[MAX],fin[MAX];
vector<int> str;
int main()
{
	int n,i,ans,cnt,mx,sq,j,sz;
	seive();
	si(n);
	rep(i,n)
		si(arr[i]);
	for(i=n-1;i>=0;i--)
	{
		sq=sqrt(arr[i]);
		cnt=0;
		str.clear();
		while(primeit[cnt]<=sq)
		{
			if(arr[i]%primeit[cnt]==0)
			{
				str.pb(primeit[cnt]);
				//trace3(i,arr[i], primeit[cnt]);
				while(arr[i]%primeit[cnt]==0)
					arr[i]/=primeit[cnt];
			}
			cnt++;
		}
		if(arr[i]!=1)
		{
			str.pb(arr[i]);
		}
		mx=-mod;
		sz=str.size();
		rep(j,sz)
		{
			fin[str[j]]++;
		}
		rep(j,sz)
		{
			mx=max(mx, fin[str[j]]);
			//trace3(i,j,str[j]);
		}
		rep(j,sz)
			fin[str[j]]=mx;
		//trace4(i, fin[2], fin[5101], mx);
	}
	ans=1;
	rep(i,MAX)
	{
		if(isprime[i]==0)
			ans=max(ans, fin[i]);
	}
	ans=max(ans, 0);
	pin(ans);
	return 0;
}













