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
typedef struct node
{
	long long int s,f,d;
}node;
node *a;
int compare(const void *a, const void *b)
{
	node *x=(node*)a;
	node *y=(node*)b;
	long long int v=x->s-y->s;
	if(v>0)
		return 1;
	else
		return -1;
}
long long int best[1000000];
int main()
{
	int t,n,i,flag,j,k;
	a=(node*)malloc(sizeof(node)*1000000);
	si(t);
	while(t--)
	{
		si(n);
		for(i=0;i<n;i++)
		{
			sl(a[i].s);
			sl(a[i].f);
			a[i].d=a[i].f-a[i].s+1;
		}
		qsort(a,n,sizeof(a[0]),compare);
		rep(i,n)
			printf("%lld %lld %lld\n",a[i].s,a[i].f,a[i].d);
		best[n-1]=a[n-1].d;
		for(i=n-2;i>=0;i--)
		{
			flag=1;
			for(j=n;j>=1;j--)
			{
				if(a[j-1].f<=a[i-1].s)
				{
					flag=0;
					break;
				}
			}
			if(flag)
				best[i]=best[i-1];
			else
				best[i]=max(best[i-1], best[j]+a[i-1].d);
		}
		pill(best[n]);
	}
	return 0;
}






