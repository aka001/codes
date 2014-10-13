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
int arr[1001][1001],up[1001][1001],down[1001][1001],up1[1001][1001];
int main()
{
	int t;
	si(t);
	while(t--)
	{
		si(m);
		si(n);
		rep(i,m)
		{
			rep(j,n)
			{
				si(arr[i][j]);
			}
		}
		//up[0][1]=arr[0][0]+arr[1][1];
		for(i=0;i<m-1;i++)
		{
			up[i][1]=arr[i][0]+arr[i+1][i+1];
		}
		for(k=0;k<m;k++)
		{
			FOR(i,k+1,m-1)
			{
				FOR(j,i+1,n)
				{
					up[i][j]+=up[i-1][j-1]+arr[i][j];
				}
			}
		}
		for(i=0;i<n-1;i++)
		{
			up1[i][1]=arr[0][i]+arr[i+1][i+1];
		}
		for(k=0;k<n;k++)
		{
			FOR(i,k+1,n-1)
			{
				FOR(j,i+1,m)
				{
					up1[i][j]+=up1[i-1][j-1]+arr[i][j];
				}
			}
		}
		
	}
	return 0;
}








