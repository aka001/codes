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
vector<int> arr[10];
int vis[100];
int main()
{
	int n,calc,i,j,sz,k,sz1;
	char ch[200];
	vector<int> ans;
	arr[4].pb(2);
	arr[4].pb(2);
	arr[6].pb(2);
	arr[6].pb(3);
	arr[8].pb(2);
	arr[8].pb(2);
	arr[8].pb(2);
	arr[9].pb(3);
	arr[9].pb(3);
	si(n);
	ss(ch);
	sz=strlen(ch);
	rep(i,sz)
	{
		calc=ch[i]-'0';
		//printf("calc=%d\n",calc);
		for(j=2;j<=calc;j++)
		{
			if(arr[j].size()==0)
				vis[j]++;
			else
			{
				sz1=arr[j].size();
				//printf("j=%d sz=%d\n",j,sz);
				rep(k,sz1)
					vis[arr[j][k]]++;
			}
		}
	}
	/*rep(i,10)
		printf("i=%d vis=%d\n",i,vis[i]);*/
	for(i=9;i>=2;i--)
	{
		if(vis[i]>0)
		{
			rep(j,vis[i])
				ans.pb(i);
			for(j=i-1;j>=2;j--)
			{
				if(vis[j]-vis[i]<0)
				{
					vis[j]=0;
					calc=vis[i]-vis[j];
					if(j==4)
						vis[2]-=2*calc;
					else if(j==6)
					{
						vis[3]-=calc;
						vis[2]-=calc;
					}
					else if(j==8)
					{
						vis[2]-=3*calc;
					}
					else if(j==9)
						vis[3]-=2*calc;
				}
				else
					vis[j]-=vis[i];
			}
		}
	}
	sz=ans.size();
	rep(i,sz)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}











