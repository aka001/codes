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
ll isprime[MAX], arr[MAX], cntit[MAXIT];
vector<ll> primeit, fin, solved[20];
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
vector<pair<int,int> > generate(vector<int> ait)
{
	int cnt,i=0,calc,it,i1,sz,ans;
	sz=ait.size();
	calc=1<<sz;
	vector<pair<int,int> > toret;
	while(i<calc)
	{
		i1=i;
		it=cnt=ans=0;
		while(i1!=0)
		{
			if(i1&01)
			{
				ans+=ait[it];
				cnt++;
			}
			it++;
			i1>>=1;
		}
		toret.pb(mp(cnt, ans));
		i++;
	}
	return toret;
}
int main()
{
	seive();
	ll n,i,j,sz,calc,val,sqit,b,h,k,a,ans,ssz,add;
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
	h=sz/2;
	vector<int> v1,v2;
	vector<pair<int,int> > vit1, vit2;
	rep(i,h)
		v1.pb(fin[i]);
	FOR(i,h,sz)
		v2.pb(fin[i]);
	vit1=generate(v1); vit2=generate(v2);
	sz=vit1.size();
	rep(i,sz)
	{
		solved[vit1[i].F].pb(vit1[i].S);
	}
	rep(i,20)
		sort(ALL(solved[i]));
	sz=vit2.size();
	ans=0;
	rep(i,sz)
	{
		ssz=vit2[i].F;
		rep(j,k-ssz+1)
		{
			add=(upper_bound(ALL(solved[j]), b-vit2[i].S)-lower_bound(ALL(solved[j]), a-vit2[i].S));
			ans+=add;
		}
	}
	pln(ans);
	return 0;
}
