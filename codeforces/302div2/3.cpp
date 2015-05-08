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
ll n,m,b,v,arr[501],mem[501][501]={-1};
//map<pair<int,pair<int,int> >, int> mapit;
//map<pair<int,int>, int> mapit;
ll recursion(ll ind, ll val, ll tot)
{
	if(tot>m || val<0)
		return 0;
	if(ind==n || tot==m)
	{
		//trace3(ind,val,tot);
		if(val>=0 && tot==m)
			return 1;
		else
			return 0;
	}
	if(mem[ind][val]!=-1)
		return mem[ind][val];

	//if(mapit.find(mp(ind,mp(val,tot)))!=mapit.end())
		//return mapit[mp(ind,mp(val,tot))];

	/*if(mapit.find(mp(ind,val))!=mapit.end())
	{
		trace3(ind,val,tot);
		return mapit[mp(ind,val)];
	}*/
	ll ans=0;int i;
	if(val<0)
		ans=0;
	else
	{
		rep(i,m+1)
		{
			ans+=recursion(ind+1,val-i*arr[ind],tot+i);
			ans%=v;
		}
	}
	ans%=v;
	//mapit[mp(ind,mp(val,tot))]=ans;
	mem[ind][val]=ans;
	//mapit[mp(ind,val)]=ans;
	return ans;
}
int main()
{
	ll ans,i,j;
	rep(i,501)
		rep(j,501)
			mem[i][j]=-1;
	sl(n);
	sl(m);
	sl(b);
	sl(v);
	rep(i,n)
		sl(arr[i]);
	ans=recursion(0,b,0);
	//trace1(cnt);
	pln(ans);
	return 0;
}













