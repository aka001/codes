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
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int arr[1000006],brr[1000006],crr[1000006];
int main()
{
	int t,i,n,q,l,r,ans;
	si(t);
	while(t--)
	{
		si(n);
		si(q);
		rep(i,n)
		{
			si(arr[i]);
			if(i==0)
				brr[i]=arr[i];
			else
				brr[i]=gcd(arr[i],brr[i-1]);
		}
		for(i=n-1;i>=0;i--)
		{
			if(i==n-1)
				crr[i]=arr[i];
			else
				crr[i]=gcd(arr[i],crr[i+1]);
		}
		rep(i,q)
		{
			si(l);
			si(r);
			l--;
			r--;
			if(l==0)
				ans=crr[r+1];
			else if(r==n-1)
				ans=brr[l-1];
			else
			{
				ans=gcd(brr[l-1],crr[r+1]);
			}
			pin(ans);
		}
	}
	return 0;
}








