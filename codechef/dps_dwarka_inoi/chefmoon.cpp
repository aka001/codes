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
int dist[1000][1000];
int main()
{
	int n,m,k,i,j,K,a,b,c,q;
	si(n);
	si(m);
	si(K);
	FOR(i,1,1000)
	{
		FOR(j,1,1000)
			dist[i][j]=mod;
	}
	rep(i,m)
	{
		si(a);
		si(b);
		si(c);
		dist[a][b]=c;
		dist[b][a]=c;
	}
	//Source: http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/
	for (k = 1; k <= n; k++)
	{
		// Pick all vertices as source one by one
		for (i = 1; i <= n; i++)
		{
			// Pick all vertices as destination for the
			// above picked source
			for (j = 1; j <= n; j++)
			{
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	si(q);
	rep(i,q)
	{
		si(a);
		si(b);
		if(dist[a][b]<=K)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}









