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
char ch[1000000];
int main()
{
	int i,lengthit,lenit,init=0,final=1,init1,k,flag=0;
	ll calc,max=-1,cnt=0;
	ss(ch);
	si(k);
	lengthit=strlen(ch);
	lenit=lengthit/2;
	if(k>=lengthit)
	{
		max=2*lengthit;
		if(k>max)
			max=k;
		if((k+lengthit)%2==0 && (k+lengthit)>max)
			max=k+lengthit;
		if((k+lengthit)%2==1)
		{
			calc=k+lengthit-1;
			if(calc>max)
				max=calc;
		}
		pln(max);
		return 0;
	}
	max=2*k;
	for(init=0;init<lengthit;init++)
	{
		init1=init;
		cnt=0;
		final=init+1;
		flag=0;
		while(1)
		{
			if(final>=lengthit)
				break;
			if(ch[init]==ch[final])
			{
				cnt++;
				init++;
				final++;
			}
			else
			{
				if(init!=init1)
				{
					flag=0;
					break;
				}
				final++;
			}
		}
		if(2*cnt>max)
		{
			//printf("hie cnt=%lld\n",cnt);
			max=2*cnt;
		}
		init=init1;
	}
	rep(i,lengthit)
	{
		init=i;
		calc=(lengthit-i+k);
		if(calc&01==1)
			continue;
		calc>>=1;
		cnt=0;
		while(1)
		{
			if(i+calc>=lengthit)
				break;
			if(ch[i]==ch[i+calc])
			{
				cnt++;
			}
			else
				break;
			i++;
		}
		if(cnt==lengthit-init-calc && calc*2>max)
		{
			//printf("calc=%lld init=%d\n",calc,init);
			max=calc*2;
		}
		i=init;
	}
	pln(max);
	return 0;
}











