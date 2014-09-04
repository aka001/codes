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
ll inv_count=0;
int arr[1000000],temp[1000000],a[1000006],b[1000006];
void merge(int left, int mid, int right)
{
	int i=left,j=mid+1,k=0;
	while(i<=mid && j<=right)
	{
		if(a[i]<=b[j])
		{
			i++;
		}
		else
		{
			//printf("left=%d mid=%d right=%d i=%d j=%d a=%d b=%d\n",left,mid,right,i,j,a[i],b[j]);
			j++;
			inv_count+=mid-i+1;
		}
	}
	i=left;j=mid+1;k=0;
	while(i<=mid && j<=right)
	{
		if(a[i]<=a[j])
		{
			//printf("i=%d a=%d\n",i,a[i]);
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
			//printf("i=%d j=%d mid=%d mid-i+1=%d\n",i,j-1,mid,mid-i+1);
		}
	}
	//printf("here left=%d mid=%d right=%d i=%d j=%d a=%d b=%d\n",left,mid,right,i,j,a[i],b[j]);
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=right)
		temp[k++]=a[j++];
	/*rep(i,k)
		printf("%d ",temp[i]);
	printf("\n");*/
	k=0;
	for(i=left;i<=right;i++)
	{
		a[i]=temp[k++];
	}
	i=left,j=mid+1,k=0;
	while(i<=mid && j<=right)
	{
		if(b[i]<=b[j])
		{
			temp[k++]=b[i++];
		}
		else
		{
			temp[k++]=b[j++];
			//printf("i=%d j=%d mid=%d mid-i+1=%d\n",i,j-1,mid,mid-i+1);
		}
	}
	while(i<=mid)
		temp[k++]=b[i++];
	while(j<=right)
		temp[k++]=b[j++];
	k=0;
	for(i=left;i<=right;i++)
		b[i]=temp[k++];

}
void merge_sort(int left,int right)
{
	if(right>left)
	{
		int mid=(left+right)/2;
		merge_sort(left,mid);
		merge_sort(mid+1,right);
		merge(left,mid,right);
	}
}
int main()
{
	int t,n,i;
	si(t);
	while(t--)
	{
		inv_count=0;
		si(n);
		rep(i,n)
		{
			si(a[i]);
		}
		rep(i,n)
		{
			si(b[i]);
		}
		merge_sort(0,n-1);
		pln(inv_count);
	}
	return 0;
}










