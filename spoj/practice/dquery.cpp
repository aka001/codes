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
#define gc getchar_unlocked
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
struct node
{
	int block, start, last, query;
	/*bool operator > (const node* &n1) const
	  {
	  if(block == n1->block)
	  return last<n1->last;
	  else
	  return block<n1->block;
	  }*/
};
bool compare(const node &n1, const node &n2)
{
	if(n1.block == n2.block)
		return n1.last<n2.last;
	else
		return n1.block<n2.block;

}
vector<node> ndit;
vector<int> arr, brr;
int currentL=-1, currentR=-1, ans=0;
int mapit[MAX];
void scanint(ll &x)
{
	register ll c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
void remove(int pos)
{
	if(mapit[arr[pos]]==1)
		ans--;
	mapit[arr[pos]]--;
}
void add(ll pos)
{
	if(mapit[arr[pos]]==0)
		ans++;
	mapit[arr[pos]]++;
}
void initial_increament(ll l, ll r)
{
	ll i;
	for(i=l; i<=r; i++)
		add(i);
	currentL=l; currentR=r;
}
void findans(ll l, ll r)
{
	while(currentL<l)
	{
		remove(currentL);
		currentL++;
	}
	while(currentL>l)
	{
		add(currentL-1);
		currentL--;
	}
	while(currentR<r)
	{
		add(currentR+1);
		currentR++;
	}
	while(currentR>r)
	{
		remove(currentR);
		currentR--;
	}
}
ll fin[MAX];
map<ll,ll> mapnumbers;
int main()
{
	ll cnt=1,i,sz,n,bl,val,q,l,r;
	scanint(n);
	bl = sqrt(n);
	rep(i,n)
	{
		scanint(val);
		arr.pb(val);
		brr.pb(val);
	}
	sort(brr.begin(), brr.end());
	cnt=1;
	rep(i,n)
	{
		if(i==0 || brr[i]!=brr[i-1])
			mapnumbers[brr[i]]=cnt++;
	}
	rep(i,n)
		arr[i]=mapnumbers[arr[i]];
	initial_increament(0,n-1);
	scanint(q);
	rep(i,q)
	{
		scanint(l); scanint(r);
		l--; r--;
		node temp;
		temp.block = (l/bl);
		temp.start = l;
		temp.last = r;
		temp.query = i;
		ndit.pb(temp);
	}
	sort(ndit.begin(), ndit.end(), compare);
	sz=ndit.size();
	rep(i,sz)
	{
		findans(ndit[i].start, ndit[i].last);
		//trace2(currentL, currentR);
		//trace4(ndit[i].block, ndit[i].start, ndit[i].last, ans);
		fin[ndit[i].query]=ans;
	}
	rep(i,q)
		pln(fin[i]);
	return 0;
}













