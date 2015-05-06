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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
map<ll,ll> mapit,mpit;
vector<pair<ll,ll> > arr;
vector<ll> vec;
ll sg[1000006];
//Initializing the segment tree
void initialize(int node,int b, int e)
{
	if(b==e)
	{
		sg[node]=0;
	}
	else
	{
		initialize(2*node,b,(b+e)/2);
		initialize(2*node+1,(b+e)/2+1,e);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
//Updating the segment tree for the values which are to be deleted/inserted
inline void update(int node, int b, int e, int ch)
{
	if(b==e && b==ch)
		sg[node]=1;
	else if(b!=e)
	{
		update(2*node, b, (b+e)/2, ch);
		update(2*node+1, (b+e)/2+1, e, ch);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
//Finding the count of the numbers lesser than a given number
inline int sumit(int node, int b, int e, int x, int y)
{
	if(b>y || e<x)
		return 0;
	else if(b>=x && e<=y)
		return sg[node];
	else
	{
		int p1,p2;
		p1=sumit(2*node, b, (b+e)/2, x, y);
		p2=sumit(2*node+1, (b+e)/2+1, e, x, y);
		return p1+p2;
	}
}

int main()
{
	ll n,i,v1,v2,c1,c2,sz,temp,cit1,cit2,calc;
	ll ans=0;
	sl(n);
	rep(i,n)
	{
		sl(v1);sl(v2);
		arr.pb(mp(v1,v2));
		vec.pb(v1);
		vec.pb(v2);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(),vec.end()), vec.end());
	sort(vec.begin(), vec.end());
	sz=vec.size();
	rep(i,sz)
	{
		mapit[vec[i]]=i;
		mpit[vec[i]]=i;
	}
	rep(i,n)
	{
		c1=arr[i].F;
		c2=arr[i].S;
		cit1=c1;cit2=c2;
		c1=mapit[c1];
		c2=mapit[c2];
		temp=vec[c1];
		vec[c1]=vec[c2];
		vec[c2]=temp;
		mapit[cit1]=c2;
		mapit[cit2]=c1;
	}
	initialize(1,0,sz-1);
	rep(i,sz)
	{
		calc=vec[i]-sumit(1,0,sz-1,1,vec[i]-1)-1;
		ans+=calc;
		trace3(i,calc,vec[i]);
		update(1,0,sz-1,vec[i]);
	}
	pln(ans);
	return 0;
}













