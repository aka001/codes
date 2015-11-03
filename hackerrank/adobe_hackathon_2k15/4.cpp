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
#define MAX 1000005
#define F first
#define S second
pair<ll,ll> seg[MAX],enode;
ll pow10it[MAX];
string arr[MAX];
ll string_to_integer(string val)
{
	stringstream ss;
	ss<<val;
	ll vit;
	ss>>vit;
	vit%=mod;
	return vit;
}
void precompute()
{
	int i;
	pow10it[0] = 1;
	FOR(i,1,MAX)
	{
		pow10it[i] = 10*pow10it[i-1];
		pow10it[i] %= mod;
	}
}
void initialize(ll node, ll l, ll r)
{
	if(l==r)
	{
		seg[node].F = string_to_integer(arr[l]);
		seg[node].S = arr[l].size();
		return;
	}
	ll mid, len, calc;
	mid = (l+r)/2;
	initialize(2*node, l, mid);
	initialize(2*node+1, mid+1, r);
	seg[node].S = seg[2*node].S + seg[2*node+1].S;
	seg[node].F = seg[2*node].F*pow10it[seg[2*node+1].S] + seg[2*node+1].F;
	seg[node].F %= mod;
}

pair<ll,ll> query(ll node, ll a, ll b, ll l, ll r)
{
	if(a>r || b<l || a>b)
		return enode;
	if(a>=l && b<=r)
		return seg[node];
	pair<ll,ll> q1, q2;
	ll mid;
	mid = (a+b)/2;
	q1=query(2*node, a, mid, l, r);
	q2=query(2*node+1, mid+1, b, l, r);
	ll dig = q1.S + q2.S;
	ll num = q1.F*pow10it[q2.S] + q2.F;
	num%=mod;
	return mp(num, dig);
}

void update(ll node, ll a, ll b, ll l, pair<ll,ll> val)
{
	if(a>l || b<l || a>b)
		return;
	if(a==l && b==l)
	{
		seg[node] = val;
		return;
	}
	ll mid, len, calc;
	mid = (a+b)/2;
	update(2*node, a, mid, l, val);
	update(2*node+1, mid+1, b, l, val);
	seg[node].S = seg[2*node].S + seg[2*node+1].S;
	seg[node].F = seg[2*node].F*pow10it[seg[2*node+1].S] + seg[2*node+1].F;
	seg[node].F %= mod;
}
int main()
{
	ll m,i,x,y,fl,calc,ans=0,val,v1,cnt,sz,vit,n;
	precompute();
	string v2;
	sl(n);
	rep(i,n)
	{
		cin>>arr[i];
	}
	initialize(1, 0, n-1);
	sl(m);
	rep(i,m)
	{
		sl(fl); sl(v1); 
		cin>>v2;
		v1--;
		if(fl==1)
		{
			ll sz = v2.size();
			ll dig = string_to_integer(v2);
			update(1, 0, n-1, v1, mp(dig, sz));
		}
		else
		{
			ll vit = string_to_integer(v2);
			vit--;
			pair<ll,ll> aka = query(1, 0, n-1, v1, vit);
			printf("%lld\n", aka.F);
		}
	}
	return 0;
}

