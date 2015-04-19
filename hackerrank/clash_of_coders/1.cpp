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
ll arr[501][501];
ll sv[1000];
char ch[10006];
int main()
{
	ll n,m,i,j,k,cnt,calc;
	sl(n);
	sl(m);
	rep(i,n)
	{
		ss(ch);
		rep(j,m)
			arr[i][j]=ch[j]-'0';
	}
	FOR(i,1,1010)
		sv[i]=0;
	rep(i,n)
	{
		FOR(j,i+1,n)
		{
			cnt=0;
			FOR(k,0,m)
			{
				if(arr[i][k]==1 || arr[j][k]==1)
					cnt++;
			}
			//printf("i=%lld j=%lld cnt=%lld\n",i,j,cnt);
			sv[cnt]++;
		}
	}
	for(i=1000;i>=0;i--)
	{
		//printf("i=%lld sv=%lld\n",i,sv[i]);
		if(sv[i]!=0)
		{
			printf("%lld\n%lld\n",i,sv[i]);
			return 0;
		}
	}
	calc=(n*(n-1))/2;
	printf("0\n%lld\n",calc);
	return 0;
}













