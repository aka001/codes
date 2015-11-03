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
ll dp[4003][4003], arr[MAX],n,k,t;
map<pair<ll,ll>, int> dp1;
ll compute(ll ind, ll mit)
{
	if(mit<0)
		return 0;
	/*ll &ret = dp[ind][mit];
	if(ret!=-1)
		return ret;*/
	if(dp1.find(mp(ind, mit))!=dp1.end())
		return dp1[mp(ind,mit)];
	else
	{
		ll i, sum=0;
		FOR(i,0,2001)
		{
			if(ind==n+1)
			{
				if(arr[ind-1]<i)
					break;
				else
				{
					//trace4(ind, mit, arr[ind-1], i);
					arr[ind-1]-=i;
					if(mit-i*ind>=0)
					{
						sum += compute(ind-1, mit-i*ind);
						sum%=mod;
					}
					arr[ind-1]+=i;
				}
			}
			else if(ind==0)
			{
				if(arr[ind+1]<i)
					break;
				else
				{
					//trace4(ind, mit, arr[ind-1], i);
					arr[ind+1]-=i;
					if(arr[ind+1]==0 && arr[ind]==0 && mit==0)
					{
						//trace4(ind, mit, arr[ind+1], i);
						sum++;
						sum%=mod;
					}
					arr[ind+1]+=i;
				}
			}
			else
			{
				ll val, calc;
				calc = arr[ind+1] + arr[ind-1];
				if(i>=arr[ind+1] && i<=calc)
				{
					//trace6(ind, mit, arr[ind-1], arr[ind+1], arr[ind], i);
					val = arr[ind+1];
					arr[ind+1]=0;
					arr[ind-1]-=(i-val);
					if(mit-i*ind>=0)
						sum += compute(ind-1, mit-i*ind);
					//trace5(sum, ind, mit, arr[ind-1], arr[ind+1]);
					sum%=mod;
					arr[ind-1]+=(i-val);
					arr[ind+1]=val;
				}
			}
		}
		sum%=mod;
		//return ret = sum;
		dp1[mp(ind,mit)]=sum;
		return sum;
	}
}
int main()
{
	fill(dp, -1);
	ll i, ans, val;
	sl(n); sl(k); sl(t);
	rep(i,k)
	{
		sl(val);
		arr[val]++;
	}
	ans = compute(n+1, t);
	ans%=mod;
	pln(ans);
	return 0;
}













