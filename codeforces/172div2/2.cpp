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
double val;
ll n;
pair<ll,ll> binary()
{
	ll num,dit,i,den;
	double vit,c1,c2,it=mod;
	FOR(i,1,n+1)
	{
		den=i;
		ll low=1,high=100000000000,mid;
		double calc,ans=mod;
		ll fin=100000000000;
		while(low<=high)
		{
			mid=(low+high)/2.0;
			c1=mid/(den*1.0)-val;
			c2=(mid-1)/(den*1.0)-val;
			c1=fabs(c1); c2=fabs(c2);
			//trace3(c1,c2,mid);
			if(c1<=ans)
			{
				if(c2<ans)
				{
					fin=mid;
					ans=c1;
				}
				else if(mid<fin)
					fin=mid;
			}
			if(c2<=ans)
			{
				if(c2<ans)
				{
					fin=mid-1;
					ans=c2;
				}
				else if(mid-1<fin)
					fin=mid-1;
			}
			if(c1>c2)
				high=mid-1;
			else
				low=mid+1;
		}
		vit=fin/(den*1.0) - val;
		vit=fabs(vit);
		trace2(fin, den);
		if(vit<it)
		{
			it=vit;
			num=fin;
			dit=den;
		}
	}
	return mp(num,dit);
}
int main()
{
	double x,y;
	pair<ll,ll> ans;
	sd(x); sd(y); sl(n);
	val=x/(y*1.0);
	ans = binary();
	cout<<ans.F<<"/"<<ans.S<<endl;
	return 0;
}













