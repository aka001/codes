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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
vector<pair<int,int> > vec[3];
int arr[MAX],cnt[3],fin[MAX];
int main()
{
	int n,i,flag,v1,v0;
	si(n);
	rep(i,n)
	{
		si(arr[i]);
		vec[arr[i]%3].pb(mp(arr[i],i));
		//trace2(arr[i], arr[i]%3);
	}
	rep(i,3)
		sort(vec[i].begin(), vec[i].end());
	//trace2(vec[0][0].F, vec[0][1].F);
	//trace2(vec[0][0].S, vec[0][1].S);
	//trace1(vec[0].size());
	flag=1;
	rep(i,n)
	{
		if(cnt[i%3]>=vec[i%3].size())
		{
			flag=0;
			break;
		}
		fin[i]=vec[i%3][cnt[i%3]].S;
		cnt[i%3]++;
		trace3(cnt[i%3], i, fin[i]+1);
	}
	if(flag)
	FOR(i,1,n)
	{
		v1=arr[fin[i]];
		v0=arr[fin[i-1]];
		trace2(v1, v0);
		if(!(v1<=v0+1 && v1%3==(v0+1)%3))
		{
			trace1("hie");
			flag=0;
			break;
		}
	}
	if(flag)
	{
		printf("Possible\n");
		rep(i,n)
		{
			cout<<fin[i]+1;
			if(i!=n-1)
				cout<<" ";
			else
				cout<<endl;
		}
	}
	else
		printf("Impossible\n");
	return 0;
}













