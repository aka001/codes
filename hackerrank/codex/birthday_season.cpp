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
int n,mem[1000][1000],dp[1000][1000];
char ch[1000006],cum[1000006];
int recursion(int l, int r)
{
	int val1,val2,maxit=-mod,val,i;
	if(l>r)
		return 0;
	else if(l==r)
		return ch[l]=='1';
	if(mem[l][r]==1)
		return dp[l][r];
	mem[l][r]=1;
	//printf("l=%d r=%d\n",l,r);
	val1=cum[r];
	if(l==0)
		val2=0;
	else
		val2=cum[l-1];
	if((val1-val2)>(r-l+1)/2)
	{
		//printf("val1=%d val2=%d l=%d r=%d\n",val1,val2,l,r);
		dp[l][r]=r-l+1;
		return r-l+1;
	}
	for(i=l;i<r;i++)
	{
		val1=recursion(l,i);
		val2=recursion(i+1,r);
		/*if(l==0 && r==n-1)
			printf("val1=%d val2=%d l=%d i=%d r=%d\n",val1,val2,l,i,r);*/
		val=val1+val2;
		maxit=max(val,maxit);
	}
	dp[l][r]=maxit;
	return maxit;
}
int main()
{
	int t,val,i,j;
	si(t);
	while(t--)
	{
		si(n);
		//printf("n=%d\n",n);
		rep(i,n+1)
			cum[i]=0;
		rep(i,n+1)
			rep(j,n+1)
				mem[i][j]=0;
		ss(ch);
		rep(i,n)
		{
			val=ch[i]-'0';
			if(i!=0)
				cum[i]=cum[i-1]+val;
			else
				cum[i]=val;
		}
		//printf("n=%d\n",n);
		printf("%d\n",recursion(0,n-1));
	}
	return 0;
}











