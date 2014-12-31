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
char ch[50];
ll arr[50][50],brr[50][50];
int main()
{
	int t,i,j,p,q,n,sz;
	ll ans;
	si(t);
	while(t--)
	{
		ans=(ll)((ll)mod*(ll)mod);
		si(n);
		rep(i,n)
		{
			ss(ch);
			sz=strlen(ch);
			rep(j,sz)
			{
				if(ch[j]=='.')
					arr[i][j]=1;
				else
					arr[i][j]=0;
			}
		}
		/*rep(i,n)
		  rep(j,n)
		  brr[i][j]=arr[i][j];
		  FOR(i,1,n)
		  {
		  FOR(j,1,n)
		  {
		  if(arr[i][j]!=0)
		  {
		  arr[i][j]=arr[i-1][j]+arr[i][j-1];
		  }
		//printf("%lld ",arr[i][j]);
		}
		}
		//printf("p=%d q=%d arr=%lld\n",p,q,arr[n-1][n-1]);
		ans=min(ans,arr[n-1][n-1]);
		rep(i,n)
		rep(j,n)
		arr[i][j]=brr[i][j];*/
		rep(p,n)
		{
			rep(q,n)
			{
				if(arr[p][q]==0 || (p==n-1 && q==n-1) || (p==0 && q==0))
					continue;
				rep(i,n)
					rep(j,n)
					brr[i][j]=arr[i][j];
				arr[p][q]=0;
				arr[0][0]=1;
				FOR(i,1,n)
				{
					if(arr[0][i]!=0)
						arr[0][i]=arr[0][i-1];
					if(arr[i][0]!=0)
						arr[i][0]=arr[i-1][0];
				}
				FOR(i,1,n)
				{
					FOR(j,1,n)
					{
						if(arr[i][j]!=0)
						{
							arr[i][j]=arr[i-1][j]+arr[i][j-1];
						}
						//printf("%lld ",arr[i][j]);
					}
				}
				printf("p=%d q=%d arr=%lld\n",p,q,arr[n-1][n-1]);
				ans=min(ans,arr[n-1][n-1]);
				if(ans==0)
					break;
				rep(i,n)
					rep(j,n)
					arr[i][j]=brr[i][j];
				//arr[p][q]=1;
			}
			if(ans==0)
				break;
		}
		pln(ans);
	}
	return 0;
}












