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
ll arr[1000][1000];
int main()
{
	int t;
	ll n,m,i,j,k,l,calc;
	FOR(j,1,102)
		arr[1][j]=1;
	for(i=2;i<=102;i++)
	{
		for(j=1;j<=102;j++)
		{
			calc=i;
			for(k=j-1;k>=1;k--)
			{
				for(l=i-1;l>=1;l--)
				{
					calc+=arr[l][k];
					if(calc>=mod)
						calc%=mod;
				}
			}
			arr[i][j]=calc;
			if(arr[i][j]>=mod)
				arr[i][j]%=mod;
		}
	}
	/*for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			printf("%lld ",arr[i][j]);
		}
		printf("\n");
	}*/
	si(t);
	while(t--)
	{
		sl(n);
		sl(m);
		pln(arr[n+1][m]);
	}
	return 0;
}








