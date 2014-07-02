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
ll merge(int arr[],int,int,int);
int arr[100010],temp[100010],n;
ll merge_sort(int arr[],int left,int right)
{
	ll inv_count=0;
	int mid;
	if(right>left)
	{
		mid=(left+right)/2;
		inv_count=merge_sort(arr,left,mid);
		inv_count+=merge_sort(arr,mid+1,right);
		inv_count+=merge(arr,left,mid,right);
	}
	return inv_count;
}
ll merge(int arr[],int left,int mid,int right)
{
	int i,j,k=0,l;
	ll inv_count=0;
	i=left,j=mid+1;
	while(i<=mid && j<=right)
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
			//printf("mid=%d i=%d j=%d k=%d mid-i+1=%d\n",mid,i,j-1,k,mid-i+1);
			inv_count+=mid-i+1;
		}
	}
	while(i<=mid)
		temp[k++]=arr[i++];
	while(j<=right)
		temp[k++]=arr[j++];
	k=0;
	for(i=left;i<=right;i++)
		arr[i]=temp[k++];
	/*rep(l,n)
		printf("%d ",arr[l]);
	printf("\n");
	printf("left=%d mid=%d right=%d inv_count=%d\n",left,mid,right,inv_count);*/
	return inv_count;
}
int main()
{
	int x,y,q,i;
	ll ans;
	si(n);
	si(q);
	rep(i,n)
	{
		si(arr[i]);
	}
	ans=merge_sort(arr,0,n-1);
	ans%=2;
	rep(i,q)
	{
		si(x);si(y);
		ans=1-ans;
		pln(ans);
	}
	return 0;
}















