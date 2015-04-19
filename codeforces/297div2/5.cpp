/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/


#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
map<ll,ll> mapit[30],dp[30];
ll n,k,s,calc;
ll arr[100],ait[100],fact[100];
vector<pair<ll,ll> > strit;
//Used meet in the middle technique
void first_middle(ll pos, ll val, ll k)
{
	if(val>s)
		return;
	//printf("%lld %lld\n",val,k);
	if(pos>=calc)
	{
		mapit[k][val]++;
		return;
	}
	first_middle(pos+1, val+arr[pos], k+1);
	first_middle(pos+1, val+ait[pos], k);
	first_middle(pos+1, val, k);
}
void second_middle(ll pos, ll val, ll k)
{
	if(val>s)
		return;
	//printf("%lld %lld n=%lld\n",val,k,n);
	if(pos>=n)
	{
		strit.pb(mp(val,k));
		return;
	}
	second_middle(pos+1, val+arr[pos], k+1);
	second_middle(pos+1, val+ait[pos], k);
	second_middle(pos+1, val, k);
}
int main()
{
	ll ans=0,sz,c1,c2,j,i,cit,sit;
	fact[0]=1;
	FOR(i,1,21)
		fact[i]=i*fact[i-1];
	sl(n);
	sl(k);
	sl(s);
	calc=n/2;
	rep(i,n)
	{
		sl(arr[i]);
		ait[i]=arr[i];
		if(arr[i]<=20)
			arr[i]=fact[arr[i]];
		else
			arr[i]=(ll)((ll)mod * (ll)mod);
	}
	if(n==1)
	{
		if(arr[0]==s && k>0)
			ans++;
		if(ait[0]==s)
			ans++;
		pln(ans);
		return 0;
	}
	first_middle(1, arr[0], 1);
	first_middle(1, ait[0], 0);
	first_middle(1, 0, 0);

	second_middle(calc+1, arr[calc], 1);
	second_middle(calc+1, ait[calc], 0);
	second_middle(calc+1, 0, 0);
	sort(strit.begin(), strit.end());
	sz=strit.size();
	//pln(sz);
	i=0;
	rep(i,sz)
	{
		c1=s-strit[i].F;
		c2=k-strit[i].S;
		cit=0;
		FOR(j,0,c2+1)
		{
			if(mapit[j].find(c1)!=mapit[j].end())
				cit+=mapit[j][c1];
			/*if(c1==0 && j>0)
				continue;*/
		}
		//printf("cit=%lld dp=%lld\n",cit,dp[j-1][c1]);
		ans+=cit;
	}
	pln(ans);
	return 0;
}







