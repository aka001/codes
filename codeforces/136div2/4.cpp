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
map<int,int> mapit;
vector<pair<int, pair<int,pair<int,int> > > > query;
vector<int> arr,brr,crr;
int countit[MAX],n,currentL, currentR,ans=0,ansit[MAX];
void initial_computation()
{
	int i;
	rep(i,n)
	{
		countit[arr[i]]++;
		if(countit[arr[i]]==crr[i]+1)
			ans--;
		else if(countit[arr[i]]==crr[i])
			ans++;
	}
	currentL=0;
	currentR=n-1;
}
void compute(int l, int r)
{
	while(currentL<l)
	{
		countit[arr[currentL]]--;
		if(countit[arr[currentL]]==crr[currentL])
			ans++;
		if(countit[arr[currentL]]==crr[currentL]-1)
			ans--;
		currentL++;
	}
	while(currentL>l)
	{
		countit[arr[currentL-1]]++;
		if(countit[arr[currentL-1]]==crr[currentL-1])
			ans++;
		if(countit[arr[currentL-1]]==crr[currentL-1]+1)
			ans--;
		currentL--;
	}
	while(currentR<r)
	{
		countit[arr[currentR+1]]++;
		if(countit[arr[currentR+1]]==crr[currentR+1])
			ans++;
		if(countit[arr[currentR+1]]==crr[currentR+1]+1)
			ans--;
		currentR++;
	}
	while(currentR>r)
	{
		countit[arr[currentR]]--;
		if(countit[arr[currentR]]==crr[currentR])
			ans++;
		if(countit[arr[currentR]]==crr[currentR]-1)
			ans--;
		currentR--;
	}
}
int main()
{
	int m,i,val,cnt=1,bsz,l,r;
	si(n); si(m);
	rep(i,n)
	{
		si(val);
		arr.pb(val);
		brr.pb(val);
		crr.pb(val);
	}
	bsz=sqrt(n);
	rep(i,m)
	{
		si(l);
		si(r);
		query.pb(mp(l/bsz, mp(i, mp(l, r))));
	}
	sort(query.begin(), query.end());
	sort(brr.begin(), brr.end());
	rep(i,n)
	{
		if(mapit.find(brr[i])==mapit.end())
		{
			mapit[brr[i]]=cnt++;
		}
	}
	rep(i,n)
	{
		arr[i]=mapit[arr[i]];
	}
	initial_computation();
	pair<int, pair<int,int> > temp;
	rep(i, m)
	{
		temp=query[i].S;
		compute(temp.S.F-1, temp.S.S-1);
		ansit[temp.F]=ans;
	}
	rep(i,m)
	{
		pin(ansit[i]);
	}
	return 0;
}













