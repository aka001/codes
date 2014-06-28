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
vector<int> storeit[10];
vector<int> arr;
vector<int> maxit;
int flag[10],sizeofarr[10];
int ans[100005];
int temp[100005];
int main()
{
	int i,n=0,sizeit,pos,j,cntit=0,k;
	char ch[100005];
	ss(ch);
	n=strlen(ch);
	rep(i,n)
	{
		arr.pb(ch[i]-'0');
		storeit[ch[i]-'0'].pb(i);
	}
	rep(i,10)
	{
		sizeofarr[i]=storeit[i].size();
	}
	rep(i,n)
		ans[i]=-1;
	ans[0]=0;
	for(i=1;i<=20;i++)
	{
		cntit=0;
		rep(j,n)
		{
			if(ans[j]==(i-1))
			{
				temp[cntit++]=j;
			}
		}
		//printf("i=%d cntit=%d\n",i,cntit);
		rep(j,cntit)
		{
			//printf("j=%d temp[j]=%d\n",j,temp[j]);
			if(ans[n-1]!=-1)
				break;
			if(temp[j]!=0 && ans[temp[j]-1]==-1)
			{
				//printf("1st conditional\n");
				ans[temp[j]-1]=i;
			}
			if(temp[j]!=(n-1) && ans[temp[j]+1]==-1)
			{
				//printf("2nd conditional temp[j=%d]=%d ans[temp[j]+1]=%d\n",j,temp[j],ans[temp[j]+1]);
				ans[temp[j]+1]=i;
			}
			if(ans[n-1]!=-1)
				break;
			if(flag[arr[temp[j]]]==0)
			{
				//printf("temp[j]=%d Sizeofarr=%d\n",temp[j],sizeofarr[arr[temp[j]]]);
				for(k=0;k<sizeofarr[arr[temp[j]]];k++)
				{
					if(storeit[arr[temp[j]]][k]!=temp[j] && ans[storeit[arr[temp[j]]][k]]==-1)
					{
						//printf("3rd conditional\n");
						ans[storeit[arr[temp[j]]][k]]=i;
					}
				}
			}
			if(ans[n-1]!=-1)
				break;
			flag[arr[temp[j]]]=1;
		}
	}
	pin(ans[n-1]);
	return 0;
}




