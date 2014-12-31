/**Author: Akash Agrawall
Institution: IIIT Hyderabad **/
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

#define FOR(i,a,b) 	for(i= (int )a ; i < (int )b ; ++i)
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
#define pill(n)         printf("%lld\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
int a[100];
int checkprime(int x)
{
	int a=sqrt(x),i,flag=1;
	for(i=2;i<=a;i++)
	{
		if(x%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int cnt=0,i,j;
	long long int x,x1;
	sl(x);
	if(x==0 || x==1)
	{
		pill(x);
		return 0;
	}
	while(checkprime(x))
	{
		x=1000000007+x;
	}
	cnt=1;
	while(1)
	{
		rep(i,10)
			a[i]=0;
		x1=x;
		for(i=9;i>1;i--)
		{
			cnt=0;
			if(x%i==0)
			{
				while(x!=0 && x%i==0)
				{
					x/=i;
					cnt++;
					if(x==1)
						break;
				}
				a[i-1]=cnt;
			}
		}
		if(x==1)
			break;
		else
		{
			x=x1;
			x+=1000000007;
			continue;
		}
	}
	for(i=1;i<9;i++)
	{
		cnt=a[i];
		for(j=0;j<cnt;j++)
		{
			printf("%d",i+1);
		}
	}
	printf("\n");
	return 0;
}









