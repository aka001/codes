#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
ll MAX = 1000000000000000000ll;
ll rec(ll k, ll end, ll point){
	//ll val = (1<<(end-1));
	ll mid = (end/2);
	if(k <= 0 || k == mid){
		return 0^point;
	}
	else if(k>mid){
		return rec(end-k-1,mid,point^1);
	}
	else{
		return rec(k,mid,point);
	}
}
int main()
{
	ll ans,i,n,j,t,k;	
	//cout << n << endl;
	n = 0;
	sl(t);
	ll test = 1;
	while(t--){
		sl(k);
		cout<<"Case #"<<test<<": ";
		ll ans = 0;
		while(ans<=k){
			ans = 2*ans+1;
		}
		cout << rec(k-1,ans,0) << endl;
		test++;
	}
	return 0;
}
