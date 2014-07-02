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
ll powerit(ll a, ll b)
{
	ll x=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			x*=a;
			if(x>=mod)
				x%=mod;
		}
		a=a*a;
		if(a>=mod)
			a%=mod;
		b>>=1;
	}
	return x;
}
int num,sum=0;
int luckynumber(ll n)
{
	int flagit=1;
	if(n==0)
		return n;
	while(n!=0)
	{
		if(n%10!=4 && n%10!=7)
		{
			//printf("nmod10 %d\n",n%10);
			flagit=0;
			break;
		}
		n/=10;
	}
	//printf("flagit=%d\n",flagit);
	return flagit;
}
int findit(ll sum_so_far,int i,int lo,ll y[])
{
	//printf("sum_so_far=%d i=%d lo=%d\n",sum_so_far,i,lo);
	//intf("i=%d val=%d\n",i,i>num);
	int d;
	if(i==num+1)
	{
		return luckynumber(sum_so_far);
	}
	else if(luckynumber(sum_so_far)==0)
		return 0;
	for(d=0;d<=(lo?1:y[i]);d++)
	{
		//printf("D=%d i=%d\n",d,i);
		sum+=findit(sum_so_far+d,i+1,lo | d<y[i],y);
	}
}
int main()
{
	int t,i,j,temp,num1,calc=0;
	ll x[1000],y[1000],a,b;
	si(t);
	while(t--)
	{
		sum=0;
		sl(a);sl(b);
		a--;
		i=0;
		while(a!=0)
		{
			x[i++]=a&01;
			a>>=1;
		}
		num1=i;
		rep(j,num1/2)
		{
			temp=x[j];
			x[j]=x[i-j-1];
			x[i-j-1]=temp;
		}
		i=0;
		while(b!=0)
		{
			y[i++]=b&01;
			b>>=1;
		}
		num=i;
		rep(j,num/2)
		{
			temp=y[j];
			y[j]=y[i-j-1];
			y[i-j-1]=temp;
		}

		rep(j,num1)
			printf("%lld",x[j]);
		printf("\n");
		rep(j,num)
			printf("%lld",y[j]);
		printf("\n");
		num--;
		findit(0,0,0,y);
		printf("sum=%d\n",sum);
		calc=sum;sum=0;
		num=num1;
		num--;
		findit(0,0,0,x);
		//printf("sum=%d\n",sum);
		calc=calc-sum;
		printf("%d\n",calc);
	}
	return 0;
}












