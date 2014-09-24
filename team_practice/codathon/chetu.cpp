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
int maxit=0;
int solveit(int n, int ch,int val,int sum)
{
	int calc,calc1;
	if(val==32 && ch==1)
	{
		maxit=1;
		return sum;
	}
	else if(val>32)
	{
		return -1;
	}
	if(ch==1)
	{
		calc=solveit(n,2,val+1,sum+1);
		calc1=solveit(n,2,val+2,sum+1);
		if(calc==-1 || calc1==-1)
			return -1;
		else
			return calc;
	}
	else
	{
		calc=solveit(n,1,val+1,sum+1);
		calc1=solveit(n,1,val+2,sum+1);
		if(calc!=-1)
			return calc;
		else if(calc1!=-1)
			return calc1;
		else
			return -1;
	}
}
int main()
{
	int t,ans,n;
	si(t);
	while(t--)
	{
		maxit=0;
		si(n);
		ans=solveit(n,1,n+1,1);
		if(ans!=-1)
		{
			printf("CHETU %d\n",ans);
			continue;
		}
		maxit=0;
		ans=solveit(n,1,n+2,1);
		if(ans!=-1)
		{
			printf("CHETU %d\n",ans);
			continue;
		}
		maxit=0;
		ans=solveit(n,2,n+1,1);
		if(ans!=-1)
		{
			printf("NISHU %d\n",ans);
			continue;
		}
		maxit=0;
		ans=solveit(n,2,n+2,1);
		if(ans!=-1)
		{
			printf("NISHU %d\n",ans);
			continue;
		}
		//printf("\n");
	}
	return 0;
}












