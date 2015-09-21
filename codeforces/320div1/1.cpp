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
double compute(double val, double a, double b)
{
	double vit,threshold,m1,m2,d1,d2;
	//trace1(threshold);
	//trace1(calc);
	ll low,high,mid;
	low=2;high=2305843009213693952L;
	while(low<=high)
	{
		mid=(low+high)/2.0;
		m1=mid; m2=mid+2;
		m1=val/(m1*1.0); m2=val/(m2*1.0);
		//trace6(low,high,mid,m1,m2,b);
		//printf("%.14f %.14f %.14f\n",m1,m2,b);
		//trace2(d1,d2);
		//if(d1>=threshold && d2<=threshold)
		if(m1>=b && m2<b)
		{
			return mid;
		}
		else if(m1>=b)
			low=mid+2;
		else
			high=mid-2;
		//trace2(vit, calc);
	}
	vit=mod*mod;
	return vit;
}
int main()
{
	double a,b,val,ans,vit,mit,threshold;
	threshold=1/(10000*1000000.0);
	sd(a); sd(b);
	/*if(a==b)
	{
		printf("%.12f\n",a);
		return 0;
	}*/
	/*if(a<b)
	{
		printf("-1\n");
		return 0;
	}*/
	ans = mod*mod; mit=ans;
	val=a+b;
	vit = compute(val,a,b);
	if(vit==mit)
		val=vit;
	else
		val = val/(vit*1.0);
	ans = val;
	//trace1(ans);
	val=a-b;
	vit=compute(val, a, b);
	//trace1(vit);
	if(vit==mit)
		val=mit;
	else
		val=val/(vit*1.0);
	//trace1(val);
	ans=min(ans, val);
	//if(a==b)
	//	ans=0;
	if(ans==mit)
		pin(-1);
	else
		printf("%.12lf\n",ans);
	return 0;
}













