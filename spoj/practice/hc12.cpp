/*Author : Akash Agrawall
 Institution: IIIT Hyderabad*/

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
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sd(n)		scanf("%lf",&n)
#define sl(n)		scanf("%lld",&n)
#define pl(n)		printf("%lld\n",n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
long long int power(long long int v,long long int v1)
{
	long long int calc=1;
	while(v1!=0)
	{
		if(v1&01==1)
		{
			calc=(calc%1000000007*v%1000000007)%1000000007;
		}
		v=(v*v)%1000000007;
		v1>>=1;
	}
	return calc;
}
int compare(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
long long int a[1000000];
int arr[1000000];
int main()
{
	long long int t,k,n1,calc,calc1,calc2,s,i,n;
	int k1;
	a[0]=1;
	a[1]=1;
	a[2]=2;
	for(i=3;i<=1000000;i++)
	{
		a[i]=(i*a[i-1])%1000000007;
	}
	scanf("%lld",&t);
	rep(k1,t)
	{
		scanf("%lld",&n);
		scanf("%lld",&k);
		s=0;
		rep(i,n)
			si(arr[i]);
		if(n==1 && k==1)
		{
			pil(arr[0]);
			continue;
		}
		else if(n==0)
		{
			continue;
		}
		qsort(arr,n,sizeof(arr[0]),compare);
		//rep(i,n)
		//	pil(arr[i]);
		n1=n-1;
		k--;
		//printf("n1=%llu k=%llu\n",n1,k);
		while(n1>=k && n1>=0)
		{
			calc1=(a[n1-k]*a[k]);
			if(calc1>=1000000007)
				calc1%=1000000007;
			//printf("a[%llu]=%llu a[%llu]=%llu\n",n1-k,a[n1-k],k,a[k]);
			//printf("calc1= %llu\n",calc1);
			calc1=power(calc1,1000000005);
			calc=(calc1*a[n1]);
			if(calc>=1000000007)
				calc%=1000000007;
			calc*=arr[n1];
			if(calc>=1000000007)
				calc%=1000000007;
			s+=calc;
			if(s>=1000000007)
				s%=1000000007;
			n1--;
		}
		printf("Case #%d: %lld\n",k1+1,s);
	}
	return 0;
}





