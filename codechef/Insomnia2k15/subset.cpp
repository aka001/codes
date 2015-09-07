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
#define sl(n) scanf("%d",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define F first
#define S second
#define mod (ll)(1e9 + 7)
#define ll long long int
#define MAX 1000006
#define MAXIT 16000006
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
//Can be implemented in a better way. For reference: https://www.codechef.com/viewplaintext/8048464
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int isprime[MAX], arr[MAX], cntit[MAXIT];
vector<int> primeit, fin, solved[9];
void seive()
{
	ll i,j;
	FOR(i,2,MAX)
	{
		if(isprime[i]==0)
		{
			j=i*i;
			for(; j<MAX; j+=i)
				isprime[j]=1;
		}
	}
	FOR(i,2,MAX)
	{
		if(isprime[i]==0)
			primeit.pb(i);
	}
}
int a1[MAXIT], a2[MAXIT];
int main()
{
	seive();
	int n,i, sz,calc,val,j,sqit,k,a,b,ans=0,j1,cnt,v,h1,off,up,l,ind1,v1,v11;
	ll finans=0;
	sl(n);
	sl(k); sl(a); sl(b);
	rep(i,n)
	{
		sl(arr[i]);
		val=arr[i];
		sqit=sqrt(val);
		calc=1;
		j=0;
		while(primeit[j]<=sqit)
		{
			if(val%primeit[j]==0)
			{
				calc*=primeit[j];
				while(val%primeit[j]==0)
					val/=primeit[j];
			}
			j++;
		}
		calc*=val;
		fin.pb(calc);
	}
	sz=fin.size();
	h1=sz/2;
	FOR(i,0,h1+1)
	{
		calc=1<<h1;
		memset(cntit, 0 ,sizeof(cntit));
		FOR(j,0,calc)
		{
			ans=0; cnt=0; v=0;
			j1=j;
			while(j1!=0)
			{
				if(j1%2==1)
				{
					ans+=fin[cnt];
					v++;
				}
				cnt++;
				j1/=2;
			}
			if(v==i)
			{
				solved[i].pb(ans);
			}
		}
		sort(solved[i].begin(), solved[i].end());
	}
	off=h1;
	h1=n-h1;
	FOR(i,0,h1+1)
	{
		calc=1<<h1;
		FOR(j,0,calc)
		{
			ans=0; cnt=0; v=0;
			j1=j;
			while(j1!=0)
			{
				if(j1%2==1)
				{
					ans+=fin[cnt+off];
					v++;
				}
				cnt++;
				j1/=2;
			}
			if(v==i)
			{
				up=k-i;
				FOR(l, 0, up+1)
				{
					finans+=upper_bound(ALL(solved[l]), b-ans) - lower_bound(ALL(solved[l]), a-ans);
				}
			}
		}	
	}
	pln(finans);
	return 0;
}
