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
map<int,int> mapit,pos,freeit;
vector<ll> arr,brr;
ll freecount,k,ans=0;
int stablemarriage()
{
	int i,sz,lp,rp,c1,c2,cnt,pref;
	sz=arr.size();
	trace1(sz);
	if(sz%2)
		sz--;
	freecount=sz;
	trace1(sz);
	while(freecount>0)
	{
		for(i=0;i<sz;i++)
			if(freeit[i]==-1)
				break;
		cnt=0;
		lp=i-1;
		rp=i+1;
		//trace2(i, freeit[i]);
		while(cnt<k)
		{
			if(lp<0)
				c1=mod;
			else
				c1=abs(arr[i]-arr[lp]);
			if(rp>=sz)
				c2=mod;
			else
				c2=abs(arr[i]-arr[rp]);
			if(c1>c2)
			{
				pref=rp;
				rp++;
			}
			else
			{
				pref=lp;
				lp++;
			}
			if(freeit[pref]==-1)
			{
				//trace4(i,freecount,pref,freeit[pref]);
				k-=2;
				freeit[pref]=i;
				freeit[i]=pref;
				freecount-=2;
				ans+=abs(arr[pref]-arr[i]);
				break;
			}
			else
			{
				c1=abs(arr[pref]-arr[freeit[pref]]);
				c2=abs(arr[pref]-arr[i]);
				if(c2<c1)
				{
					ans-=abs(arr[pref]-arr[freeit[pref]]);
					freeit[pref]=i;
					freeit[i]=pref;
					ans+=abs(arr[pref]-arr[i]);
				}
			}
			cnt++;
		}
	}
}
int main()
{
	ll n,i,sz,val;
	sl(n); sl(k);
	rep(i,n)
	{
		sl(val);
		arr.pb(val);
		mapit[arr[i]]++;
	}
	sort(arr.begin(), arr.end());
	arr.erase( unique( arr.begin(), arr.end() ), arr.end() );
	sz=arr.size();
	rep(i,sz)
	{
		pos[arr[i]]=i;
		freeit[i]=-1;
		if(mapit[arr[i]]>1)
		{
			if(mapit[arr[i]]%2==0)
			{
				k-=mapit[arr[i]]/2;
				mapit[arr[i]]=0;
			}
			else
			{
				k-=(mapit[arr[i]]-1)/2;
				mapit[arr[i]]=1;
			}
		}
		if(mapit[arr[i]]==1)
			brr.pb(arr[i]);
	}
	sort(brr.begin(), brr.end());
	brr.erase( unique( brr.begin(), brr.end() ), brr.end() );
	arr.clear();
	sz=brr.size();
	rep(i,sz)
		arr.pb(brr[i]);
	sz=arr.size();
	rep(i,sz)
	{
		freeit[i]=-1;
	}
	if(k<=0)
		pin(0);
	else
	{
		freecount=sz;
		stablemarriage();
		pln(ans);
	}
	return 0;
}













