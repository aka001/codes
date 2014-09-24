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
int arr[1000006],arr1[1000006];
int main()
{
	int n,i,cnt;
	si(n);
	if(n%4!=0)
		printf("NO\n");
	else
	{
		printf("YES\n");
		printf("1 * 2 = 2\n");
		printf("3 * 4 = 12\n");
		printf("2 * 12 = 24\n");
		cnt=0;
		for(i=5;i<=n;i++)
			arr[cnt++]=i;
		rep(i,cnt)
			arr1[i]=arr[i];
		rep(i,cnt/4)
		{
			printf("%d - %d = %d\n",arr1[4*i],arr1[4*i+1],arr1[4*i]-arr[4*i+1]);
			printf("%d - %d = %d\n",arr1[4*i+3],arr1[4*i+2],arr1[4*i+3]-arr[4*i+2]);
		}
		cnt/=4;
		rep(i,cnt)
		{
			printf("1 + -1 = 0\n");
		}
		//cnt/=2;
		rep(i,cnt)
			printf("24 + 0 = 24\n");

	}
	return 0;
}








