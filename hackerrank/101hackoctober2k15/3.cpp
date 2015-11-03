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
ll arr[MAX], brr[MAX], k,n;
set<pair<ll,ll> > sit;
void findit(pair<ll,ll> cit)
{
	ll low=0,high;
	ll ind = cit.S, i, ait = arr[ind], bit = brr[ind], mid,calc,val,cnt,ans,manu;
	high = ait;
	while(low<=high)
	{
		mid = (low+high)/2;
		calc = ait - mid;
		cnt=0;
		for(i=0; i<n; i++)
		{
			if(arr[i]*brr[i]>calc*brr[ind] || (arr[i]*brr[i] == calc*brr[ind] && i<ind))
			{
				val = (calc*brr[ind]);
				if(arr[i]*brr[i]==val && i<ind)
				{
					val = val/brr[i]-1;
				}
				else
				{
					if(val%brr[i]!=0)
						val = val/brr[i]+1;
					else
						val = val/brr[i];
				}
				cnt += arr[i]-val;
			}
		}
		if(cnt<=k)
		{
			ans = mid;
			manu = cnt;
			low = mid+1;
		}
		else
			high = mid -1;
	}
	calc = ait-ans;
	k-=manu;
	rep(i,n)
	{
		val = calc*brr[ind];
		if(arr[i]*brr[i] > val || (arr[i]*brr[i]==val && i<ind))
		{
			if(arr[i]*brr[i]==val && i<ind)
			{
				val = val/brr[i]-1;
			}
			else
			{
				if(val%brr[i]==0)
					val = val/brr[i];
				else
					val = val/brr[i]+1;
			}
			pair<ll,ll> aka;
			aka = mp(-1*arr[i]*brr[i], i);
			if(sit.find(aka) != sit.end())
			{
				sit.erase(aka);
				arr[i] = val;
				if(arr[i]*brr[i]!=0)
					sit.insert(mp(arr[i]*brr[i]*-1, i));
			}
		}
	}
}
int main()
{
	ll i,cnt=0,calc,sz;
	pair<ll,ll> cit;
	sl(n);
	sl(k);
	rep(i,n)
		sl(arr[i]);
	rep(i,n)
		sl(brr[i]);
	rep(i,n)
	{
		calc = arr[i]*brr[i];
		sit.insert(mp(-calc, i));
	}
	findit(*sit.begin());
	while(!(sit.empty()))
	{
		if(k<=0)
			break;
		k--;
		cit = *sit.begin();
		sit.erase(cit);
		ll ind = cit.S;
		arr[ind]--;
		if(arr[ind]>0)
		{
			calc = arr[ind]*brr[ind];
			sit.insert(mp(-calc, ind));
		}
	}
	rep(i,n)
	{
		cout<<arr[i];
		if(i!=n-1)
			cout<<" ";
		else
			cout<<endl;
	}
	return 0;
}













