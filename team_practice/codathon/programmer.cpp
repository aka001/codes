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
vector<int> arr[100006];
vector< pair<int,int> > brr[100006];
int color[1000006]={0},ans=0,visited[1000006]={0};
void solve(int n)
{
	if(visited[n]==0)
	{
		visited[n]=1;
	}
	else
		return;
	int sz,flg=1,i,val;
	sz=arr[n].size();
	//printf("loop n=%d\n",n);
	if(sz==1)
	{
		color[n]=1;
	}
	else
	{
		rep(i,sz)
		{
			val=arr[n][i];
			if(color[val]==0)
			{
				solve(val);
			}
			if(color[val]==1)
			{
				flg=0;
				//break;
			}
		}
		if(flg==0)
		{
			//printf("n=%d\n",n);
			color[n]=2;
			ans++;
		}
		else
			color[n]=1;
	}
}
int main()
{
	int n,q,i,val,val1,flag,j;
	si(n);
	si(q);
	rep(i,n-1)
	{
		si(val);
		si(val1);
		arr[val].pb(val1);
		arr[val1].pb(val);
	}
	n++;
	FOR(i,1,n)
	{
		solve(i);
	}
	//printf("ans=%d\n",ans);
	q-=ans;
	if(q<0)
		printf("IMPOSSIBLE\n");
	else
		pin(q);
	return 0;
}







