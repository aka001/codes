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
#define MAX 5000006
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
int isprime[MAX],prime[MAX],palin[MAX];
vector<pair<double, int> > arr;
void seive()
{
	ll i=2,j,cnt=0;
	for(;i<=MAX;i++)
	{
		if(isprime[i]==0)
		{
			j=i*i;
			for(;j<=MAX;j+=i)
				isprime[j]=1;
		}
	}
	prime[0]=0;prime[1]=0;
	FOR(i,2,MAX)
	{
		if(isprime[i]==0)
			cnt++;
		prime[i]=cnt;
	}
}
int checkpalin(int n)
{
	int n1=n,n2=0;
	while(n!=0)
	{
		n2=n2*10+n%10;
		n/=10;
	}
	if(n1==n2)
		return 1;
	return 0;
}
int findvalue(double p, double q)
{
	double calc=p/(q*1.0),m1,m2,v1,v2;
	int low=0,high=arr.size(),mid,ans;
	while(low<=high)
	{
		if(prime[low]*q<=palin[low]*p)
			ans=low;
		low++;
	}
	return ans;
}
int main()
{
	int i,calc,ans=0;
	double p,q,cit;
	seive();
	palin[0]=0;
	FOR(i,1,MAX)
	{
		calc=checkpalin(i);
		if(calc)
			ans++;
		palin[i]=ans;
	}
	//trace1(MAX);
	FOR(i,1,MAX)
	{
		cit=prime[i]/(palin[i]*1.0);
		if(i==251116 || i==251262)
			trace4(i, prime[i], palin[i], cit);
		arr.pb(mp(cit,i));
	}
	sort(arr.begin(), arr.end());
	/*trace2(palin[MAX-1], prime[MAX-1]);
	trace2(palin[156], prime[156]);
	trace2(palin[172], prime[172]);*/
	sd(p); sd(q);
	ans = findvalue(p,q);
	trace2(prime[ans], palin[ans]);
	trace2(prime[ans+1], palin[ans+1]);
	pin(ans);
	return 0;
}













