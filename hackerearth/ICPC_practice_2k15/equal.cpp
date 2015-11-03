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
//#define MAX 21
#define MAX 500001
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
int arr[MAX], n, cntit[MAX];
vector<int> ans;
int count(int val)
{
	int i, cnt=0, sum=0, low=0;
	rep(i,n)
	{
		sum+=arr[i];
		if(sum==val)
		{
			cnt++;
			sum=0;
			low=i+1;
		}
		if(sum>val)
		{
			while(sum>val && low<=i)
			{
				sum-=arr[low];
				low++;
			}
			if(sum==val)
			{
				sum=0;
				low=i+1;
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	int i,val,mx=1,sz;
	si(n);
	assert(n>=1 && n<=1000);
	rep(i,n)
	{
		si(arr[i]);
		assert(arr[i]>=1 && arr[i]<=1000);
	}
	FOR(i,1,MAX)
	{
		val = count(i);
		cntit[i]=val;
		mx=max(val, mx);
	}
	FOR(i,1,MAX)
	{
		val=cntit[i];
		//val=count(i);
		if(val==mx)
			ans.pb(i);
	}
	sort(ALL(ans));
	sz=ans.size();
	pin(mx);
	rep(i,sz)
	{
		printf("%d", ans[i]);
		if(i!=sz-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}













