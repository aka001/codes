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
int a[40][40];
int main()
{
	int i,j,max=-1,val1,val2,val3,val4,val5,val6,posl,posr,flg;
	rep(i,20)
	{
		rep(j,20)
		{
			si(a[i][j]);
		}
	}
	rep(i,20)
	{
		rep(j,20)
		{
			if(i>2)
				val1=a[i-3][j]*a[i-2][j]*a[i-1][j]*a[i][j];
			if(i<17)
				val2=a[i+1][j]*a[i+2][j]*a[i+3][j]*a[i][j];
			if(j>2)
				val3=a[i][j-3]*a[i][j-2]*a[i][j-1]*a[i][j];
			if(j<17)
				val4=a[i][j+1]*a[i][j+2]*a[i][j+3]*a[i][j];
			if(i<17 && j<17)
				val5=a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
			if(i>2 && j<17)
				val6=a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3];
			/*if(val1>max)
			  {
			  max=val1;
			  flg=1;
			  }
			  if(val2>max)
			  {
			  max=val2;
			  flg=2;
			  }
			  if(val3>max)
			  {
			  max=val3;
			  flg=3;
			  }
			  if(val4>max)
			  {
			  max=val4;
			  flg=4;
			  }*/
			if(val5>max)
			{
				max=val5;
				flg=5;
			}
			if(val6>max)
			{
				max=val6;
				flg=6;
			}
		}
	}
	pin(max);
	return 0;
}










