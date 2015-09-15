/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/

#include<bits/stdc++.h>
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
#define F first
#define S second
#define mod (ll)(1e9 + 7)
#define ll long long int
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
map<ll, ll> mapit;
set<ll> st;
vector<pair<ll,ll> > arr[MAX], crr;
int main()
{
	ll n,i,j,v1,v2,c1,c2,calc,ans=0,dist,cnt=1,val,p1,p2,sz,aka;
	sl(n);
	rep(i,n)
	{
		sl(v1); sl(v2);
		crr.pb(mp(v1,v2));
	}
	rep(i,n)
	{
		FOR(j,i+1,n)
		{
			c1=crr[j].F-crr[i].F;
			c2=crr[j].S-crr[i].S;
			dist = c1*c1+c2*c2;
			if(mapit[dist]==0)
			{
				val=cnt;
				mapit[dist]=cnt++;
			}
			else
				val=mapit[dist];
			st.insert(val);
			arr[val].pb(mp(i,j));
			//trace3(i,j,val);
		}
	}
	map<pair<ll, ll> ,ll> mit;
	set<pair<ll,ll> > sit;
	while(!(st.empty()))
	{
		val = *st.begin();
		st.erase(val);
		sz=arr[val].size();
		//trace2(val, sz);
		mit.clear();
		sit.clear();
		rep(i,sz)
		{
			p1=arr[val][i].F; p2=arr[val][i].S;
			c1=crr[p1].F+crr[p2].F;
			c2=crr[p1].S+crr[p2].S;
			sit.insert(mp(c1,c2));
			mit[mp(c1,c2)]++;
			aka=mit[mp(c1,c2)];
			//trace5(p1, p2, c1, c2, aka);
		}
		pair<ll,ll> cit;
		while(!(sit.empty()))
		{
			cit=*sit.begin();
			sit.erase(sit.begin());
			aka=mit[cit];
			ans+=(aka*(aka-1))/2;
		}
	}
	pln(ans);
	return 0;
}













