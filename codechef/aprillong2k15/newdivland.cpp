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
#include<cassert>
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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
//vector<pair<ll,ll> > arr[1000006];
vector<int> fin;
vector<pair<int, pair<int, int> > > pit;
int ass[1000006];
set<pair<ll,ll> > stit;
int main()
{
	ll n,m,cnt=0,i,a,b,c,j,sz,n1,node,ans,wt,cit,n2,c1,c2,val;
	pair<ll,ll> calc;
	srand (time(NULL));
	sl(n);
	sl(m);
	rep(i,m)
	{
		sl(a);
		sl(b);
		sl(c);
		pit.pb(mp(c, mp(a,b)));
		//arr[a].pb(mp(b,c));
		//arr[b].pb(mp(a,c));
	}
	sort(pit.rbegin(), pit.rend());
	srand(time(NULL));
	rep(i,m)
	{
		n1=pit[i].S.F;
		n2=pit[i].S.S;
		if(ass[n1]==0 && ass[n2]!=0)
			ass[n1]=3-ass[n2];
		else if(ass[n1]!=0 && ass[n2]==0)
			ass[n2]=3-ass[n1];
		else
		{
			ass[n1]=rand()%2+1;
			ass[n2]=3-ass[n1];
		}
	}
	srand(1);
	c1=c2=0;
	rep(i,n)
	{
		//trace2(i, ass[i]);
		if(ass[i]==1)
			c1++;
		else if(ass[i]==2)
			c2++;
	}
	//trace2(c1,c2);
	//assert((c1+c2)==n);
	if(c1>c2)
		val=1;
	else
		val=2;
	rep(i,n)
	{
		if(ass[i]==0)
			ass[i]=val;
	}
	cnt=0;
	rep(i,n)
	{
		if(ass[i]==val)
		{
			printf("%lld",i);
			cnt++;
			if(cnt!=n/2)
				printf(" ");
			else
			{
				printf("\n");
				break;
			}
		}
	}
	//assert(cnt<=n/2);
	return 0;
}













