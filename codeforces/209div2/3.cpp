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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 

ll arr[MAX];
map<int,int> freq;
set<int> sit, fit;
int main()
{
	ll i,n,x,ans,c,num,den,sum,cnt,calc,val;
	sl(n); sl(x);
	sum=0;
	rep(i,n)
	{
		sl(arr[i]);
		sum+=arr[i];
	}
	sum-=arr[n-1];
	ans=modpow(x, sum, mod);
	rep(i,n)
	{
		freq[arr[n-1]-arr[i]]++;
		fit.insert(arr[n-1]-arr[i]);
		sit.insert(arr[n-1]-arr[i]);
	}
	while(!(sit.empty()))
	{
		val=*(sit.begin());
		//if(val>=11)
		//	break;
		sit.erase(sit.begin());
		calc=freq[val];
		cnt=0;
		while(calc%x==0)
		{
			cnt++;
			calc/=x;
		}
		if(cnt==0)
			break;
		else
		{
			//trace4(val,freq[val],cnt,calc);
			freq[val+cnt]+=calc;
			freq[val]=0;
			sit.insert(val+cnt);
			fit.insert(val+cnt);
		}
	}
	while(!(fit.empty()))
	{
		val=*(fit.begin());
		fit.erase(fit.begin());
		if(freq[val]!=0)
		{
			//trace2(val,freq[val]);
			c=min(val, arr[n-1]);
			ans*=modpow(x,c,mod); ans%=mod;
			break;
		}
	}
	pln(ans);
	return 0;
}













