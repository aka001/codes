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
vector<pair<ll,pair<ll, ll > > > pit;
ll bit[MAX], arr[MAX];
ll read(int idx)
{
	ll ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx -= (idx & -idx);
	}
	return ans;
}
void update(ll idx, ll val)
{
	while (idx <= MAX){
		bit[idx] += val;
		idx += (idx & (-idx));
	}
	//trace1("hie");
}
ll find_kth(ll calc, ll kth)
{
	ll i,val,ret,low=1,high=MAX,mid,ret1,m1;
	while(low<=high)
	{
		mid=(low+high)/2;
		m1=read(mid);
		if(m1>kth-1)
		{
			ret=mid;
			high=mid-1;
		}
		else
			low=mid+1;
	}
	/*FOR(i,calc+1,MAX)
	{
		val = read(i);
		//trace2(i, val);
		if(val<=kth-1)
			ret1 = i;
		else
			break;
	}
	ret1++;*/
	//trace2(ret,ret1);
	return arr[ret];
}
ll query[MAX];
int main()
{
	ll i,n,l,k,q,sz,calc,vit,val;
	sl(n);
	sl(q);
	rep(i,n)
	{
		sl(arr[i+1]);
		pit.pb(mp(arr[i+1], mp(i+1, i+1)));
	}
	rep(i,q)
	{
		sl(l); sl(k);
		pit.pb(mp(l, mp(k-n, i+1)));
		//trace1(i+1);
	}
	sort(ALL(pit));
	sz=pit.size();
	for(i=sz-1; i>=0; i--)
	{
		calc=pit[i].second.first;
		vit=pit[i].second.second;
		if(calc<=0)
		{
			val = find_kth(0, calc+n);
			query[vit]=val;
		}
		else
		{
			val = pit[i].first;
			update(vit, 1);
		}
	}
	FOR(i,1,q+1)
		pln(query[i]);
	return 0;
}













