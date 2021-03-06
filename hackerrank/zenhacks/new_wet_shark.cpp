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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
vector<int> arr;
int m,r,s,c1,c2,m1;
ll a[101][2];
void recursion(int num, int ways, int ind,int flag)
{
	if(num<=0 || ind>=m || ways>=m1)
	{
		if(num==0)
		{
			a[ways][flag]++;
		}
		return;
	}
	recursion(num-arr[ind], ways+1, ind+1, flag);
	recursion(num,ways,ind+1,flag);
}
int main()
{
	int i,val;
	ll ans=0;
	si(m);
	si(r);
	si(s);
	m1=m/2;
	rep(i,m)
	{
		si(val);
		arr.pb(val);
	}
	sort(arr.rbegin(),arr.rend());
	if((r+s)%2!=0 || (r-s)%2!=0)
	{
		printf("0\n");
		return 0;
	}
	c1=(r+s)/2;
	c2=(r-s)/2;
	recursion(c1,0,0,0);
	if(c1!=c2)
		recursion(c2,0,0,1);
	if(c1==c2)
	{
		rep(i,m1)
		{
			ans+=(a[i][0]*(a[i][0]-1))/2;
			ans%=mod;
		}
	}
	else
	{
		rep(i,m1)
		{
			ans+=a[i][0]*a[i][1];
			ans%=mod;
		}
	}
	pln(ans);
	return 0;
}











