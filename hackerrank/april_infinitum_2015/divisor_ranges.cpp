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
set<int> stit;
int isprime[1000006],arr[1000006];
vector<int> primeit, vit, sit;
void seive()
{
	ll i,j,MAX=100005;
	FOR(i,2,MAX)
	{
		j=i*i;
		if(isprime[i]==0)
			for(;j<MAX;j+=i)
				isprime[j]=1;
	}
	FOR(i,2,MAX)
		if(isprime[i]==0)
			primeit.pb(i);
}
void div(int n)
{
	int i,sqit;
	sqit=sqrt(n);
	FOR(i,1,sqit+1)
	{
		if(n%i==0)
		{
			stit.insert(i);
			stit.insert(n/i);
		}
	}
}
ll ans[1000006],cnt[1000006];
vector<int> temp;
int main()
{
	int n,i,sz,calc,j1,i1,q,k,k1;
	si(n);
	rep(i,n)
	{
		stit.clear();
		si(arr[i]);
		div(arr[i]);
		std::set<int>::iterator j;
		//cout<<"factors"<<endl;
		for(j=stit.begin(); j!=stit.end(); j++)
		{
			j1=*j;
			//trace1(j1);
			cnt[j1]++;
		}
		//cout<<"temp"<<endl;
		sz=temp.size();
		rep(k,sz)
		{
			k1=temp[k];
			//trace1(k1);
			if(stit.find(k1)==stit.end())
			{
				ans[k1]+=(cnt[k1]*(cnt[k1]+1))/2;
				cnt[k1]=0;
			}
		}
		temp.clear();
		for(j=stit.begin(); j!=stit.end(); j++)
		{
			j1=*j;
			temp.pb(j1);
		}
	}
	
	set<int>::iterator j;
	for(j=stit.begin(); j!=stit.end(); j++)
	{
		j1=*j;
		ans[j1]+=(cnt[j1]*(cnt[j1]+1))/2;
		cnt[j1]=0;
	}
	//rep(i,sz)
	//	trace1(vit[i]);
	si(q);
	while(q--)
	{
		si(calc);
		pln(ans[calc]);
	}
	return 0;
}













