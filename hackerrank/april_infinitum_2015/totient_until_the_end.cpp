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
ll arr[3000006],isprime[3000006];
vector<ll> pit;
vector<pair<ll, ll> > fac;
void seive()
{
	ll i,j,MAX;
	isprime[0]=isprime[1]=1;
	MAX=3000006;
	FOR(i,2,MAX)
	{
		if(isprime[i]==0)
		{
			j=i*i;
			for(;j<MAX;j+=i)
				isprime[j]=1;
		}
	}
	FOR(i,2,MAX)
		if(isprime[i]==0)
			pit.pb(i);
}
void primefactors(ll n)
{
	ll sqit,cnt=0,cit=0;
	sqit=sqrt(n);
	while(pit[cnt]<=sqit)
	{
		if(n%pit[cnt]==0)
		{
			cit=0;
			while(n%pit[cnt]==0)
			{
				cit++;
				n/=pit[cnt];
			}
			fac.pb(mp(pit[cnt],cit));
		}
		cnt++;
	}
	if(isprime[n]==0)
		fac.pb(mp(n,1));
}
map<ll,ll> mapit;
int main()
{
	ll t,i,j,j1,a,b,ans,sz,val;
	pair<ll,ll> calc;
	seive();
	sl(t);
	while(t--)
	{
		mapit.clear();
		ans=0;
		rep(i,4)
		{
			fac.clear();
			sl(a);
			sl(b);
			if(b==0)
				continue;
			primefactors(a);
			sz=fac.size();
			//trace1(a);
			rep(j,sz)
			{
				j1=fac[j].F;
				//trace2(j1,fac[j].S);
				mapit[j1]+=fac[j].S*b;
			}
		}
		//trace2(mapit[2], mapit[3]);
		std::map<ll,ll>::reverse_iterator iter=mapit.rbegin();
		for(; iter!=mapit.rend(); ++iter)
		{
			calc=*iter;
			if(calc.S==0)
				continue;
			ans=max(ans, calc.S);
			if(calc.F==2)
				break;
			val=calc.F-1;
			fac.clear();
			primefactors(val);
			//trace2(calc.F, calc.S);
			//trace1(val);
			sz=fac.size();
			rep(j,sz)
			{
				j1=fac[j].F;
				//trace2(j1,fac[j].S);
				mapit[j1]+=fac[j].S*calc.S;
			}
			//cout<<*iter<<endl;
		}
		pln(ans);
	}
	return 0;
}













