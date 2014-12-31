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
pair<int,int> arr[1004];
int visited[1001],vis[1001],v1[1001],v2[1001],ans=1,ass[1001][2],ait[1001][2];
void dfs(int node,int flag)
{
	int i,sz,c1,c2;
	//printf("node=%d\n",node);
	if(visited[node]==1)
	{
		if(ass[node][flag]==0)
			ans=ans&0;
		return;
	}
	ass[node][flag]=1;
	visited[node]=1;
	c1=arr[node].F;
	c2=arr[node].S;
	if(flag==0)
	{
		c2=1-c2;
	}
	//printf("%d %d\n",c1,c2);
	dfs(c1,c2);
}
char ch[10006];
int main()
{
	int n,flag,i,a,b,fl,val,cnt=1,j,ans1,ans2;
	while(1)
	{
		flag=1;
		si(n);
		if(n==0)
			break;
		FOR(i,1,n+1)
		{
			visited[i]=0;
			ass[i][0]=ass[i][1]=0;
		}
		rep(i,n)
		{
			si(a);
			ss(ch);
			if(ch[0]=='f')
				fl=0;
			else
				fl=1;
			arr[i+1]=mp(a,fl);
		}
		FOR(i,1,n+1)
		{
			/*FOR(j,1,n+1)
			  {
			  visited[j]=0;
			  }*/
			ans=1;
			if(visited[i]==0)
			{
				//printf("i=%d\n",i);
				ans=1;
				FOR(j,1,n+1)
				{
					ait[j][0]=ass[j][0];
					ait[j][1]=ass[j][1];
					vis[j]=visited[j];
				}
				dfs(i,1);
				
				ans1=ans;
				if(ans1==0)
				{
					FOR(j,1,n+1)
					{
						ass[j][0]=ait[j][0];
						ass[j][1]=ait[j][1];
					}
				}
				FOR(j,1,n+1)
				{
					ait[j][0]=ass[j][0];
					ait[j][1]=ass[j][1];
					v1[j]=visited[j];
					visited[j]=vis[j];
				}
				ans=1;
				/*FOR(j,1,n+1)
				{
					printf("j=%d ass0=%d ass1=%d\n",j,ass[j][0],ass[j][1]);
				}*/
				dfs(i,0);
				ans2=ans;
				FOR(j,1,n+1)
				{
					v2[j]=visited[j];
				}
				if(ans2==0)
				{
					FOR(j,1,n+1)
					{
						ass[j][0]=ait[j][0];
						ass[j][1]=ait[j][1];
					}
				}
				//printf("node=%d ans1=%d ans2=%d\n",i,ans1,ans);
				if(ans1==1)
				{
					FOR(j,1,n+1)
						visited[j]=v1[j];
				}
				else if(ans2==1)
				{
					FOR(j,1,n+1)
						visited[j]=v2[j];
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		if(flag==0)
			printf("PARADOX\n");
		else
			printf("NOT PARADOX\n");
	}
	return 0;
}














