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
int arr[1000006],brr[1000006],ans[1000006];
int main()
{
	int p,q,l,r,calc=0,val,val1,i,j;
	si(p);
	si(q);
	si(l);
	si(r);
	rep(i,p)
	{
		si(val);
		si(val1);
		FOR(j,val,val1+1)
		{
			arr[j]=1;
		}
	}
	rep(i,q)
	{
		si(val);
		si(val1);
		FOR(j,val,val1+1)
		{
			brr[j]=1;
		}
	}
	FOR(i,1,1001)
	{
		if(arr[i]==1)
		{
			FOR(j,l,r+1)
			{
				if(i-j<0)
					break;
				if(brr[i-j]==1)
					ans[j]++;
			}
		}
	}
	FOR(i,l,r+1)
		if(ans[i]>0)
			calc++;
	pin(calc);
	return 0;
}













