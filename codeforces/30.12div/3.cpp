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
typedef struct node
{
	int v,ind;
}node;
int compare(const void *a, const void *b) 
{
	node *x=(node*)a;
	node *y=(node*)b;
	return x->v-y->v;
}
long long int ans[1000000];
int main()
{
	long long int prev,n,i,val,x;
	sl(n);
	vector<pair<long long int,long long int> > a(n);
	rep(i,n)
	{
		sl(val);
		a[i]=make_pair(val,i);
	}
	sort(a.begin(),a.end());
	x=a[0].first;
	ans[a[0].second]=a[0].first;
	prev=a[0].first;
	for(x=1;x<n;x++)
	{
		if(a[x].first<=prev)
		{
			prev=prev+1;
		}
		else
			prev=a[x].first;
		//printf("%d %d\n",a[i].ind,a[i].v);
		//printf("%d %d %d\n",a[i].ind,a[i].v,x);
		ans[a[x].second]=prev;
	}
	rep(i,n)
	{
		printf("%lld",ans[i]);
		if(i!=n-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}











