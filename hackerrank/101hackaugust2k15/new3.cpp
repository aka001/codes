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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
vector<pair<pair<int,int>,int> > query;
vector<pair<int,int> > arr;
vector<int> garb;
map<int,int> mapit;
int bit[MAX];
int lower_bound(int val)
{
	int l=0,h=arr.size()-1,m,sz=arr.size();
	while(l<=h)
	{
		m=(l+h)/2;
		//trace3(l,m,h);
		if(arr[m].F<= val && (m==sz-1 || arr[m+1].F>val))
			return m;
		else if(arr[m].F>val)
			h=m-1;
		else
			l=m+1;
	}
	return -1;
}
void update(int ind, int val)
{
	while(ind<MAX)
	{
		bit[ind]+=val;
		ind+=(ind&(-ind));
	}
}
int queryit(int ind)
{
	int ans=0;
	while(ind>0)
	{
		ans+=bit[ind];
		ind-=(ind&(-ind));
	}
	return ans;
}
void initialize(int l, int h)
{
	int i,calc;
	for(i=l; i<=h; i++)
	{
		calc=mapit[arr[i].S];
		update(calc,1);
	}
}
int main()
{
	int n,m,l,i,v1,v2,u1,u2,sz,y1,y2,ans;
	si(n);
	si(m);
	si(l);
	rep(i,n)
	{
		si(v1); si(v2);
		query.pb(mp(mp(v1,v2), i));
		garb.pb(v2);
	}
	sort(query.begin(), query.end());
	rep(i,m)
	{
		si(v1); si(v2);
		arr.pb(mp(v1,v2));
		garb.pb(v2);
	}
	sort(arr.begin(), arr.end());
	sort(garb.begin(), garb.end());
	garb.erase(unique(garb.begin(), garb.end()), garb.end());
	sz=garb.size();
	rep(i,sz)
		mapit[garb[i]]=i+1;
	rep(i,n)
	{
		v1=query[i].F.F;
		v2=query[i].F.S;
		u2=lower_bound(v1+l); u1=lower_bound(v1-1);
		if(i==0)
			initialize(u1+1, u2);
		y1=v2;
		y2=v2+l;
		ans = queryit(y2)-queryit(y2-1);
		trace5(v1,v2,u1,u2,ans);
	}
	return 0;
}













