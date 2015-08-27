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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll arr[MAX];
vector<ll> ans;
int binary_search(ll l, ll h, ll val)
{
	ll mid,sz=h;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(arr[mid]<=val && (mid==sz || arr[mid+1]>val))
			return arr[mid];
		else if(arr[mid]<=val)
			l=mid+1;
		else
			h=mid-1;
	}
	return 0;
}
int main()
{
	ll s,k,sum,i,l,h,val,sz,calc;
	sl(s); sl(k);
	if(k>=35)
	{
		arr[1]=1;
		calc=1;
		FOR(i,1,33)
		{
			arr[i+1]=calc;
			calc*=2;
		}
		l=1;
		h=32;
	}
	else
	{
		FOR(i,1,k)
			arr[i]=0;
		sum=1;
		arr[k]=1;
		FOR(i,k+1,2*k+1)
		{
			arr[i]=sum;
			sum+=arr[i];
		}
		FOR(i,2*k+1,MAX)
		{
			sum-=arr[i-k-1];
			arr[i]=sum;
			sum+=arr[i];
			if(sum>=mod)
				break;
		}
		l=1;
		h=i;
	}
	while(s>0)
	{
		val=binary_search(l, h, s);
		ans.pb(val);
		s-=val;
	}
	ans.pb(0);
	sz=ans.size();
	pln(sz);
	rep(i,sz)
	{
		cout<<ans[i];
		if(i==sz-1)
			cout<<"\n";
		else
			cout<<" ";
	}
	return 0;
}













