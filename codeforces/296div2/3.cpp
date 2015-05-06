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
set<ll> hb,vb,hit,vit;
map<ll,ll> mhit,mvit;
int main()
{
	ll w,h,n,i,ans,calc,d1,d2,val;
	char ch;
	sl(w);
	sl(h);
	sl(n);
	hb.insert(0);
	hb.insert(h);
	vb.insert(0);
	vb.insert(w);
	hit.insert(h);
	vit.insert(w);
	getchar();
	std::set<ll>::iterator low,high;
	mhit[h]=1;
	mvit[w]=1;
	rep(i,n)
	{
		ch=getchar();
		sl(val);
		if(i!=n-1)
			getchar();
		if(ch=='H')
		{
			high=hb.lower_bound(val);
			high--;
			low=high;
			high++;
			d1=*high;
			d2=*low;
			calc=d1-d2;
			mhit[calc]--;
			if(mhit[calc]==0)
				hit.erase(calc);
			hb.insert(val);
			d1=val-*low;
			hit.insert(d1);
			d2=*high;
			d2-=val;
			hit.insert(d2);
			mhit[d1]++;
			mhit[d2]++;
		}
		else
		{
			high=vb.lower_bound(val);
			high--;
			low=high;
			high++;
			d1=*high;
			d2=*low;
			calc=d1-d2;
			mvit[calc]--;
			if(mvit[calc]==0)
				vit.erase(calc);
			vb.insert(val);
			d1=val-*low;
			vit.insert(d1);
			d2=*high;
			d2-=val;
			vit.insert(d2);
			mvit[d1]++;
			mvit[d2]++;
		}
		ans = *(hit.rbegin()) * *(vit.rbegin());
		pln(ans);
	}
	return 0;
}












