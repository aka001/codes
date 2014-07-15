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
typedef struct node
{
	ll t,l,val;
}node;
bool compare(const node &x, const node &y)
{
	//node x=*(node*)a;
	//node y=*(node*)b;
	if(x.t==y.t)
		return x.l<y.l;
	return x.t<y.t;
}
vector<node> arr;
int main()
{
	int t,n,i;
	ll min,n1,pos,flagit,flagit1,sum=0,sum1=0,calc;
	si(n);
	n1=n;
	rep(i,n)
	{
		node temp;
		//node temp=(node)malloc(sizeof(node));
		sl(temp.t);
		sl(temp.l);
		temp.val=temp.l-temp.t;
		arr.pb(temp);
	}
	sort(arr.begin(),arr.end(),compare);
	i=0;
	sum+=arr[0].l+arr[0].t;
	sum1+=sum-arr[0].t;
	arr.erase(arr.begin()+0);
	n--;
	while(n)
	{
		flagit=0;
		flagit1=0;
		i=0;
		min=mod;
		pos=-1;
		while(i<n)
		{
			if(arr[i].t<=sum)
			{
				flagit1=1;
				if(sum-arr[i].t+arr[i].l<min)
				{
					min=sum-arr[i].t+arr[i].l;
					pos=i;
				}
			}
			else
			{
				flagit=1;
				if(flagit1==0)
				{
					calc=arr[0].t+arr[0].l-sum;
					sum+=calc;
					sum1+=arr[0].l;
					arr.erase(arr.begin()+0);
				}
				else
				{
					sum+=arr[pos].l;
					sum1+=sum-arr[pos].t;
					arr.erase(arr.begin()+pos);
				}
				break;
			}
			i++;
		}
		/*if(flagit1==0)
		  {
		  printf("hie ONE n=%d sum=%lld\n",n,sum);
		  calc=arr[0].l+arr[0].t-sum;
		  sum+=calc;
		  sum1+=arr[0].t;
		  printf("calc=%lld sum=%lld sum1=%lld\n",calc,sum,sum1);
		  arr.erase(arr.begin()+0);
		  printf("hie\n");
		  }*/
		if(flagit==0)
		{
			//printf("pos=%d sum=%lld\n",pos,sum);
			//printf("hie before n=%d pos=%lld\n",n,pos);
			if(pos==-1)
				pos=0;
			sum+=arr[pos].l;
			sum1+=sum-arr[pos].t;
			//printf("sum1=%lld sum=%lld \n",sum1,sum);
			arr.erase(arr.begin()+pos);
			//printf("hie after\n");
		}
		//printf("hie n=%d\n",n);
		n--;
	}
	//pln(sum1);
	sum1/=n1;
	pln(sum1);
	return 0;
}

















