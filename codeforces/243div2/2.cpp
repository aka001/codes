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

long long int gcd(long long int a,long long int b)
{
	long long int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

void seive()
{
	int i,j;
	int MAX=1000006;
	int isprime[1000006]; 
	isprime[0] = isprime[1] = 1; 
	for (i = 4; i < MAX; i += 2)
		isprime[i] = 1; 
	for (i = 3; i * i < MAX; i += 2) 
	{
		if (!isprime[i]) 
		{
			for (j = i * i; j < MAX; j += 2 * i)
			{
				isprime[j] = 1; 
			}
		}
	}
}
int arr[1000][1000];
int n,m;
int checksymmetric(int calc)
{
	int i,flag=1,j;
	rep(i,calc)
	{
		rep(j,m)
		{
			if(arr[i][j]!=arr[2*calc-i-1][j])
			{
				//printf("%d %d  %d %d  %d %d\n",i,j,2*calc-i-1,j,arr[i][j],arr[2*calc-i-1][j]);
				flag=0;
				break;
			}
		}
		if(flag==0)
			break;
	}
	return flag;
}
int main()
{
	int val,calc,ans,flag=0,i,j,calc1,calc2;
	si(n);
	si(m);
	rep(i,n)
	{
		rep(j,m)
		{
			si(arr[i][j]);
		}
	}
	calc=n/2;
	if(2*calc==n)
	{
		while(calc!=0)
		{
			calc1=checksymmetric(calc);
			if(calc1)
			{
				flag=1;
				ans=calc;
			}
			else
				break;
			calc2=calc;
			calc/=2;
			if(2*calc!=calc2)
				break;
		}
	}
	if(flag==0)
	{
		printf("%d\n",n);
	}
	else
		printf("%d\n",ans);
	return 0;
}












