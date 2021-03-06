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
#define MAX 100006
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
int isprime[MAX];
vector<int> primeit,witness,primatic;
void seive()
{
	ll i,j;
	for(i=2;i<MAX;i++)
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
			primeit.pb(i);
}
ll mulmod(ll a, ll b, ll c)
{
	ll x = 0, y = a%c;
	while(b>0)
	{
		if(b&1) {
			x = (x+y);
			if ( x >= c ) x -= c;
		}
		y = (y<<1);
		if ( y >= c ) y -= c;
		b = b>>1;
	}
	return x;
}
int miller(ll p)
{
	if(p<2)
		return 0;
	if(p!=2 && p%2==0)
		return 0;
	ll s=p-1,sz=witness.size(),i,a,temp,modit;
	while(s%2==0)
		s/=2;
	rep(i,sz)
	{
		a=witness[i];
		if(a>=p)
			break;
		temp=s;
		modit=modpow(a,temp,p);
		while(temp!=p-1 && modit!=1 && modit!=p-1)
		{
			modit=mulmod(modit,modit,p);
			temp*=2;
		}
		if(modit!=p-1 && temp%2==0)
			return 0;
	}
	return 1;
}
/*void prepopulate()
{
	ll i,calc, vh, mx=(ll)(1e14),sz,j,i1,j1;
	vh=(ll)mod*(ll)mod;
	primatic.pb(2);
	primatic.pb(3);
	primatic.pb(5);
	primatic.pb(7);
	primatic.pb(11);
	primatic.pb(13);
	sz=primatic.size();
	rep(i,sz)
	{
		i1=primatic[i];
		calc=modpow(i1,i1,vh);
		if(calc>mx)
			break;
		pit.insert(calc);
	}
}*/
int checkprimatic(ll n)
{
	if(miller(n))
		return 1;
	return 0;
}

int main()
{
	//prepopulate();
	witness.pb(2);
	witness.pb(13);
	witness.pb(23);
	witness.pb(1662803);
	seive();
	int n,i,sz,j,calc,val;
	si(n);
	if(checkprimatic(n))
	{
		pin(1);
		pin(n);
		return 0;
	}
	sz=primeit.size();
	//trace1(sz);
	while(1)
	{
		rep(i,sz)
		{
			val = n - primeit[i];
			if(checkprimatic(val))
			{
				pin(2);
				printf("%d %d\n",primeit[i],val);
				return 0;
			}
			rep(j,sz)
			{
				calc = val - primeit[j];
				if(calc>0 && checkprimatic(calc))
				{
					pin(3);
					printf("%d %d %d\n",primeit[i], primeit[j], calc);
					return 0;
				}
			}
		}
	}
	return 0;
}













