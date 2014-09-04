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

int arr[1000006];
char ch[1000006];
int main()
{
	ll t,n,maxit,sizeit,j,i,one,zero,rec,flagit,ans,i1;
	sl(t);
	while(t--)
	{
		ans=0;
		maxit=1;
		sl(n);
		ss(ch);
		sizeit=strlen(ch);
		rep(i,sizeit)
		{
			if(ch[i]=='1')
				arr[i]=1;
			else
				arr[i]=0;
		}
		//printf("sizeit=%d\n",sizeit);
		i=0;
		while(i<sizeit)
		{
			one=0;
			zero=0;
			flagit=0;
			j=i;
			i1=i;
			maxit=1;
			//printf("j=%d\n",j);
			for(;j<sizeit;j++)
			{
				if(arr[j]==1)
					one++;
				else
					zero++;
				//printf("one=%d zero=%d i=%d j=%d\n",one,zero,i1,j);
				if(one>zero)
				{
					//printf("i=%d j=%d\n",i,j);
					maxit=max(maxit,j-i1+1);
					i=j+1;
					flagit=1;
				}
			}
			if(flagit)
			{
				//printf("i1=%lld i=%lld j=%lld maxit=%lld\n",i1,i,j,maxit);
				ans+=maxit;
			}
			if(flagit==0)
				i++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}










