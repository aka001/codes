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
int a[100001][5];
vector<int> q1;
vector<int> q2;
int q3[1000000];
int main()
{
	int n,val,calc,foo=1,carry=0,i,val1,cnt=4;
	char ch;
	si(n);
	ch=getchar();
	rep(i,n)
	{
		cnt=0;
		foo=1;
		ch=getchar();
		if(ch>='A' && ch<='F')
			val=ch-'A'+10;
		else
			val=ch-'0';
		val1=val;
		while(val!=0 || cnt!=4)
		{
			calc=val%2;
			a[i][cnt]=calc;
			foo=foo*10+calc;
			val>>=1;
			cnt++;
		}
		//printf("%d%d%d%d %d %d\n",a[i][0],a[i][1],a[i][2],a[i][3],val1,foo);
	}
	for(i=n-1;i>=0;i--)
	{
		q1.pb(a[i][2]);
		q1.pb(a[i][3]);
		q2.pb(a[i][0]);
		q2.pb(a[i][1]);
		//printf("%d%d %d%d\n",q1[2*i],q1[2*i+1],q2[2*i],q2[2*i+1]);
	}
	rep(i,2*n)
	{
		if(q1[i]==0 && q2[i]==0)
		{
			q3[i]=carry;
			carry=0;
		}
		else if((q1[i]==0 && q2[i]==1) || (q1[i]==1 && q2[i]==0))
		{
			if(carry==1)
			{
				q3[i]=0;
				carry=1;
			}
			else
			{
				q3[i]=1;
				carry=0;
			}
		}
		else if(q1[i]==1 && q2[i]==1)
		{
			if(carry==1)
			{
				q3[i]=1;
				carry=1;
			}
			else
			{
				q3[i]=0;
				carry=1;
			}
		}
		//printf("%d %d %d %d\n",q1[i],q2[i],q3[i],carry);
	}
	for(i=2*n-1;i>=0;i--)
		printf("%d",q3[i]);
	return 0;
}











