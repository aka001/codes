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
#define F first
#define S second
ll arr[MAX],m;
vector<ll> pit;
pair<ll,ll> calc(ll h, ll a,ll x, ll y)
{
	pit.clear();
	ll calc=h,i,cnt=0,k=0,pos=-1,sz;
	rep(i,MAX)
		arr[i]=-1;
	//trace2(calc,m);
	calc%=m;
	while(1)
	{
		//trace4(h,a,cnt,calc);
		if(arr[calc]!=-1)
		{
			k=0;
			//trace1(cnt);
			rep(i,cnt)
			{
				if(pit[i]==a)
				{
					//trace2("==============",i);
					pos=i;
					if(i>=arr[calc])
					{
						k=cnt-arr[calc];
					}
					break;
				}
			}
			break;
		}
		pit.pb(calc);
		arr[calc]=cnt;
		cnt++;
		calc=(calc*x+y);
		calc%=m;
	}
	sz=pit.size();
	//trace3(pos,k,arr[a]);
	return mp(pos,k);
}
pair<int,int> d1,d2;
map<ll,int> mapit;
int main()
{
	pair<ll,ll> h,a,x,y;
	sl(m);
	sl(h.F);sl(a.F);sl(x.F);sl(y.F);
	sl(h.S);sl(a.S);sl(x.S);sl(y.S);
	d1=calc(h.F,a.F,x.F,y.F);
	d2=calc(h.S,a.S,x.S,y.S);
	trace2(d1.F,d1.S);
	trace2(d2.F,d2.S);
	if(d1.F==-1 || d2.F==-1)
	{
		pin(-1);
		return 0;
	}
	else
	{
		ll flag=0,i,c1,c2;
		rep(i,MAX)
		{
			c1=d1.F+d1.S*i;
			mapit[c1]=1;
		}
		rep(i,MAX)
		{
			c2=d2.F+d2.S*i;
			if(mapit.find(c2)!=mapit.end())
			{
				flag=1;
				break;
			}
		}
		if(flag)
			pln(c2);
		else
			pin(-1);
	}
	return 0;
}













