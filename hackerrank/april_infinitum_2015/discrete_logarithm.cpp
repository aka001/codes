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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll isprime[1000006];
vector<ll> witness, primatic;
vector<ll> primeit;
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
ll modpow_new(ll a,ll n,ll temp)
{
	ll res=1,y=a;
	while(n>0)
	{
		if(n&1)
		{
			res=mulmod(res,y,temp);
			//res=(res*y)%temp;
		}
		y=mulmod(y,y,temp);
		//y=(y*y)%temp;
		n/=2;
	}
	return res%temp;
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
		modit=modpow_new(a,temp,p);
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
void sieve()
{
	ll i,j,MAX=1000006;
	FOR(i,2,MAX)
	{
		if(isprime[i]==0)
		{
			j=i*i;
			for(;j<MAX;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
	FOR(i,2,MAX)
		if(isprime[i]==0)
			primeit.pb(i);
}
ll euler(ll n)
{
	ll calc=n,sq=sqrt(n),cnt=0,n1,cit,i,sz=primeit.size();
	//trace1(sz);
	while(1)
	{
		cit=primeit[cnt];
		if(cit>sq)
			break;
		if(n%cit==0)
		{
			//trace1(cit);
			while(n%cit==0)
				n/=cit;
			calc/=cit;
			calc*=(cit-1);
		}
		cnt++;
	}
	//trace1(n);
	if(miller(n))
	{
		calc/=n;
		calc*=(n-1);
	}
	return calc;
}
int main()
{
	witness.pb(2);
	witness.pb(13);
	witness.pb(23);
	witness.pb(1662803);
	ll t,i,calc,cit,a,b,n,sqit,y,fl,m,mit,eue;
	//calc=modpow(126995, 414, 270599);
	//trace1(calc);
	sieve();
	sl(t);
	while(t--)
	{
		map<ll,ll> mapit;
		calc=1;
		sl(a);
		sl(b);
		sl(n);
		sqit=sqrt(n);
		if(sqit*sqit!=n)
			sqit++;
		calc=1;
		rep(i,sqit)
		{
			mapit[calc]=i;
			calc=calc*a;
			calc%=n;
		}
		calc=euler(n);
		eue=calc;
		//trace1(calc);
		calc=modpow(a,calc-1,n);
		//trace1(calc);
		calc=modpow(calc,sqit,n);
		//trace1(calc);
		y=b;
		fl=0;
		mit=(ll)((ll)mod*(ll)mod);
		rep(i,sqit)
		{
			if(mapit.find(y)!=mapit.end())
			{
				fl=1;
				cit=i*sqit+mapit[y];
				cit%=eue;
				mit=min(cit, mit);
			}
			y=y*calc;
			y%=n;
		}
		if(fl==0)
			printf("-1\n");
		else
		{
			//cit=mapit[y];
			//cit+=i*sqit;
			pln(mit);
		}
	}
	return 0;
}













