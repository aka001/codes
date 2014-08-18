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

int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4,temp;
	double m,m1,dist,calc,m2,dist1,dist2;
	sd(x1);
	sd(y1);
	sd(x2);
	sd(y2);
	if(x1>1000 || x1<-1000 || y1>1000 || y1<-1000 || x2>1000 || x2<-1000 || y2>1000 || y2<-1000)
	{
		printf("-1\n");
		return 0;
	}
	if(x1>x2)
	{
		temp=x1;
		x1=x2;
		x2=temp;
		temp=y1;
		y1=y2;
		y2=temp;
	}
	if(x1==x2)
	{
		dist=y2-y1;
		x3=x1+dist;
		y3=y1;
		x4=x2+dist;
		y4=y2;
	}
	else if(y1==y2)
	{
		dist=x2-x1;
		x3=x1;
		y3=y1+dist;
		x4=x2;
		y4=y2+dist;
	}
	else
	{
		m=(y2-y1)/((x2-x1)*1.0);
		if(m==-1)
			m*=-1;
		if(m!=1)
		{
			printf("-1\n");
			return 0;
		}
		printf("%.0lf %.0lf %.0lf %.0lf\n",x1,y2,x2,y1);
		return 0;
	}
	printf("%.0lf %.0lf %.0lf %.0lf\n",x4,y4,x3,y3);
	return 0;
}







