/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	akash.agrawall094@gmail.com
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
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
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
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n)
#define pdl(n) printf("%lf\n",n)
#define pin(n) printf("%d\n",n)
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}

ll dp[12][100];
ll count(ll val)
{
	ll buffer[20],sizeit=0,i,j,temp,flagit,k;
	ll ans=0;
	while(val!=0)
	{
		buffer[sizeit++]=val%10;
		val/=10;
	}
	rep(i,sizeit/2)
	{
		temp=buffer[i];
		buffer[i]=buffer[sizeit-i-1];
		buffer[sizeit-i-1]=temp;
	}
	//ans+=1;
	if(sizeit==1)
		return 1;
	//printf("sizeit=%d\n",sizeit);
	flagit=0;
	rep(i,sizeit)
	{
		val=buffer[i];
		if(val==0)
			val=1;
		for(j=1;j<10;j++)
		{
			for(k=0;k<val;k++)
			{
				ans+=dp[sizeit-i-1][j];
				//printf("%lld\n",dp[sizeit-i-1][j]);
			}
		}
		/*if(flagit==1)
			ans++;*/
		flagit=1;
		//printf("ans=%lld\n",ans);
	}
	//if(buffer[sizeit-1]==0)
	//	ans++;
	return ans;
}
int main()
{
	ll i,j;
	ll a,b,t,val,val1,val2;
	dp[0][0]=1;
	dp[1][0]=9;
	dp[1][1]=1;
	for(i=2;i<=10;i++)
	{
		for(j=1;j<10;j++)
		{
			dp[i][j]=9*dp[i-1][j]+dp[i-1][j-1];
			//dp[i][j]+=9*dp[i-1][j];
			/*if(j==0)
			{
				dp[i][j]+=9*dp[i-1][j];
			}
			else
			{
			}*/
		}
		dp[i][i]=1;
	}
	//printf("%lld\n",dp[3][2]);
	sl(t);
	while(t--)
	{
		sl(a);
		sl(b);
		val1=count(a);
		val2=count(b+1);
		printf("val2=%lld val1=%lld\n",val2,val1);
		val=val2-val1;
		pln(val);
	}
	return 0;
}











