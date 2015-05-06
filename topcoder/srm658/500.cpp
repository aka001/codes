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

class MutaliskEasy
{
	public:
		map<pair<pair<int,int>,int>, int> mapit;
	public:
	int answer(int a, int b, int c,int cnt)
	{
		ll i,sz,flag=0,ans;
		if(a<=0 && b<=0 && c<=0)
		{
			return cnt;
		}
		//trace4(a,b,c,cnt);
		if(mapit.find(mp(mp(a,b),c))!=mapit.end())
			return mapit[mp(mp(a,b),c)];
		ans=mod;
		ans=min(ans, answer(a-9,b-3,c-1,cnt+1));
		ans=min(ans, answer(a-9,b-1,c-3,cnt+1));
		ans=min(ans, answer(a-3,b-9,c-1,cnt+1));
		ans=min(ans, answer(a-3,b-1,c-9,cnt+1));
		ans=min(ans, answer(a-1,b-9,c-3,cnt+1));
		ans=min(ans, answer(a-1,b-3,c-9,cnt+1));
		mapit[mp(mp(a,b),c)]=ans;
		return ans;
	}
	public:
	int minimalAttacks(vector <int> x)
	{
		int sz,i,cnt=0,flag,ans,j,k;
		vector<int> arr,brr;
		brr.pb(9);brr.pb(3);brr.pb(1);
		sz=x.size();
		for(i=sz;i<3;i++)
			x.pb(0);
		sort(x.begin(), x.end());
		ans=answer(x[0],x[1],x[2],0);
		return ans;
	}
};
int main()
{
	int ans;
	vector<int> arr;
	arr.pb(60);
	MutaliskEasy mut;
	ans=mut.minimalAttacks(arr);
	return 0;
}












