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
int brr[MAX], srr[MAX];
vector<pair<ll, ll> > ab,as;
int main()
{
	ll n,s,i,s1,s2,v1,v2,sz;
	char ch;
	sl(n); sl(s);
	s1=s2=s;
	rep(i,n)
	{
		cin>>ch>>v1>>v2;
		if(ch=='B')
			brr[v1]+=v2;
		else
			srr[v1]+=v2;
	}
	for(i=MAX-1;i>=0;i--)
	{
		if(brr[i]>0 && s1>0)
		{
			ab.pb(mp(i,brr[i]));
			//ab.pb(mp(i*brr[i],mp(i,brr[i])));
			s1--;
		}
	}
	sort(ab.rbegin(), ab.rend());

	for(i=0;i<MAX;i++)
	{
		if(srr[i]>0 && s2>0)
		{
			as.pb(mp(i,srr[i]));
			//as.pb(mp(i*srr[i],mp(i,srr[i])));
			s2--;
		}
	}
	sort(as.rbegin(), as.rend());

	sz=as.size();
	rep(i,sz)
	{
		printf("S %lld %lld\n",as[i].F,as[i].S);
	}

	sz=ab.size();
	rep(i,sz)
	{
		printf("B %lld %lld\n",ab[i].F, ab[i].S);
	}
	return 0;
}













