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
typedef struct node
{
	int l,r;
}node;
typedef struct node1
{
	int inp;
	int color;
}node1;
node *arr;
node1 *arr1;
int changeflag[200];
int compare(const void *a, const void *b)
{
	node x=*(node*)a;
	node y=*(node*)b;
	if(x.l==y.l)
		return x.r-y.r;
	return x.l-y.l;
}
int compare1(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,m,i,low,hig,j,r,b,num,fill,val,bnd;
	si(n);si(m);
	arr=(node*)malloc(m*sizeof(arr[0]));
	arr1=(node1*)malloc(m*sizeof(arr1[0]));
	rep(i,n)
	{
		si(arr1[i].inp);
		arr1[i].color=0;
	}
	rep(i,m)
	{
		si(arr[i].l);
		si(arr[i].r);
	}
	qsort(arr,m,sizeof(arr[0]),compare);
	rep(i,m)
	{
		r=b=0;
		low=arr[i].l;
		hig=arr[i].r;
		bnd=n-1;
		rep(j,n)
		{
			val=arr1[j].inp;
			if(val>=low && val<=hig)
			{
				if(arr1[j].color==0)
					r++;
				else
					b++;
			}
			else if(val>hig)
			{
				bnd=j-1;
				break;
			}
		}
		if(abs(r-b)>1)
		{
			//printf("%d %d %d\nbound=%d\n",r,b,i,bnd);
			if(r-b>1)
			{
				//printf("here\n");
				num=ceil((r-b-1)/2.0);
				fill=1;
			}
			else
			{
				num=ceil((b-r-1)/2.0);
				fill=0;
			}
			if(num>bnd)
			{
				printf("-1\n");
				return 0;
			}
			for(j=bnd;num>0 && j>=0;num--,j--)
			{
				//printf("j=%d \n",j);
				if(changeflag[j]==0 || (changeflag[j]==1 && arr1[j].color==fill))
				{
					arr1[j].color=fill;
					changeflag[j]=1;
				}
				else
				{
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	rep(i,n-1)
		printf("%d ",arr1[i].color);
	printf("%d\n",arr1[n-1].color);
	return 0;
}













