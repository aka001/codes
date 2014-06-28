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
int isprime[100001]; 
void seive()
{
	int i,j;
	int MAX=100001;
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
typedef struct node
{
	ll val,cnt,inh;
}node;
node store[100001];
vector<int> arr;
map<int,int> flag;
int main()
{
	int n,k,i,sizeit,j,count;
	seive();
	si(n);
	si(k);
	rep(i,n)
	{
		int val;
		si(val);
		arr.pb(val);
	}
	sort(arr.begin(),arr.end());
	count=0;
	rep(i,100001)
		store[i].val=0;
	rep(i,n)
	{
		node temp;
		temp.val=arr[i];
		temp.cnt=1;
		temp.inh=arr[i];
		if(k==1)
		{
			if(isprime[arr[i]]==0)
				count++;
		}
		else
		{
			store[arr[i]]=temp;
		}
	}
	if(k==1)
	{
		pin(count);
		return 0;
	}
	rep(i,n)
	{
		vector<int> ith;
		rep(j,100001)
		{
			if(store[j].val!=0)
			{
				ith.pb(j);
			}
		}
		sizeit=ith.size();
		rep(j,sizeit)
		{
			
		}
		rep(j,100001)
		{
			if(store[j].val!=0 && !(store[j].cnt==1 && store[j].val==arr[i]) && store[j].inh!=arr[i])
			{
				printf("hie\n");
				store[j+arr[i]].val=store[j].val+arr[i];
				store[j+arr[i]].cnt=store[j].cnt+1;
				store[j+arr[i]].inh=store[j].inh;
			}
		}
	}
	count=0;
	rep(i,100001)
	{
		if(store[i].cnt==k && isprime[store[i].val]==0)
		{
			count++;
		}
	}
	pin(count);
	return 0;
}










