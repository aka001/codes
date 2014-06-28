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
int arr[20];
int calcall[1000000];
int randit[20];
vector<int> akash;
int main()
{
	int calc,i,cnt=0,j,val=0,n=0,flag=0;
	char ch;
	rep(i,10)
	{
		arr[i]=-1;
	}
	ch=getchar();
	calc=ch-'0';
	while(ch!='\0' && ch!='\n' && ch!=EOF)
	{
		n++;
		calc=ch-'0';
		randit[calc]++;
		akash.pb(calc);
		ch=getchar();
	}
	rep(i,n)
	{
		if(arr[akash[i]]==-1)
		{
			val=val+1;
			arr[akash[i]]=val;
		}
		else
		{
			if(arr[akash[i]]<val)
			{
				val=arr[akash[i]]+1;
			}
			else
				val++;
		}
		calcall[i]=val;
		if(arr[akash[i]]>val)
			arr[akash[i]]=val;
	}
	for(i=n-2;i>=0;i--)
	{
		if(calcall[i+1]<calcall[i] && arr[akash[i+1]]!=-1)
			calcall[i]=calcall[i+1]+1;
	}
	flag=0;
	for(j=n-1;j>=0;j--)
	{
		if(randit[akash[j]]>1)
		{
			flag=1;
			rep(i,n-1)
			{
				if(akash[j]==akash[i])
				{
					val=calcall[i]+1;
					break;
				}
			}
			val+=n-1-j;
			break;
		}
	}
	rep(i,10)
		arr[i]=-1;
	rep(i,n)
	{
		if(arr[akash[i]]==-1)
		{
			if(arr[akash[i+1]]==-1)
			{
				if(i>0 && i<n-1)
					calcall[i]=min(calcall[i],min(calcall[i+1]+1,calcall[i-1]+1));
				else if(i==0 && i<n-1)
					calcall[i]=min(calcall[i],calcall[i+1]+1);
				else if(i>0 && i==n-1)
					calcall[i]=min(calcall[i],calcall[i-1]+1);
			}
			else
			{
				if(i>0 && i<n-1)
					calcall[i]=min(calcall[i],min(calcall[i+1]+1,min(calcall[i-1]+1,arr[akash[i+1]]+2)));
				else if(i==0 && i<n-1)
					calcall[i]=min(calcall[i],min(arr[akash[i+1]]+2,calcall[i+1]+1));
				else if(i>0 && i==n-1)
					calcall[i]=min(calcall[i],calcall[i-1]+1);
			}
			arr[akash[i]]=calcall[i];
		}
		else if(arr[akash[i]]!=-1)
		{
			if(arr[akash[i+1]]==-1)
			{
				if(i>0 && i<n-1)
					calcall[i]=min(calcall[i],min(calcall[i+1]+1,min(calcall[i-1]+1,arr[akash[i]]+1)));
				else if(i==0 && i<n-1)
					calcall[i]=min(calcall[i],min(calcall[i+1]+1,arr[akash[i]]+1));
				else if(i>0 && i==n-1)
					calcall[i]=min(calcall[i],min(calcall[i-1]+1,arr[akash[i]]+1));
			}
			else
			{
				if(i>0 && i<n-1)
				{
					calcall[i]=min(calcall[i],min(calcall[i+1]+1,min(calcall[i-1]+1,min(arr[akash[i]]+1,arr[akash[i+1]]+2))));
				}
				else if(i==0 && i<n-1)
					calcall[i]=min(calcall[i],min(calcall[i+1]+1,min(arr[akash[i]]+1,arr[akash[i+1]]+2)));
				else if(i>0 && i==n-1)
					calcall[i]=min(calcall[i],min(calcall[i-1]+1,arr[akash[i]]+1));
			}
		}
		arr[akash[i]]=min(arr[akash[i]],calcall[i]);
		//printf("arr[%d]=%d\n",akash[i],arr[akash[i]]);
		//printf("%d",calcall[i]);
	}
	val=calcall[n-1];
	printf("%d\n",val-1);
	return 0;
}











