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
int n,cnt[MAX],arr[MAX];
int findval(int flag)
{
	int i,ans=0,calc,cit=0,val;
	set<int> stit;
	memset(cnt, 0 ,sizeof(cnt));
	rep(i,n)
	{
		stit.insert(arr[i]);
		cnt[arr[i]]++;
	}
	trace1(stit.size());
	while(cit++<=10)
	//while(!(stit.empty()))
	{
		calc=*stit.rbegin();
		stit.erase(stit.find(calc));
		if(cnt[calc]==n)
		{
			break;
		}
		trace3(calc, cnt[calc], stit.size());
		val=cnt[calc];
		ans+=val;
		cnt[calc]=0;
		calc/=2;
		cnt[calc]+=val;
		stit.insert(calc);
	}
	return ans;
}
ll akash[MAX];
int main()
{
	int i,calc,val,cit;
	ll ans;
	si(n);
	rep(i,n)
	{
		si(arr[i]);
		val=arr[i]; cit=0;
		while(val!=0)
		{
			akash[val]+=cit;
			cit++;
			cnt[val]++;
			val/=2;
		}
		val=arr[i]*2; cit=0;
		while(val<=MAX)
		{
			cnt[val]++;
			cit++;
			akash[val]+=cit;
			val*=2;
		}
		//trace2(i, cnt[4]);
	}
	ans=mod;
	//trace1(cnt[4]);
	rep(i,MAX)
	{
		if(cnt[i]==n)
			ans=min(ans, akash[i]);
	}
	assert(ans!=mod);
	pln(ans);
	return 0;
}













