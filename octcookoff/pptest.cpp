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
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
string S;
int l;
typedef struct doit
{
	int c,p,tm,s;
}doit;
int compare(const void *a, const void *b)
{
	doit *x=(doit*)a;
	doit *y=(doit*)b;
	return -x->s+y->s;
}
doit *a;
int main()
{
	int t,n,w,ans,k,j,x,mx;
	si(t);
	a=(doit*)malloc(sizeof(int)*1000);
	while(t--)
	{
		ans=0,mx=-1;
		si(n);si(w);
		a=(doit*)malloc(sizeof(int)*1000);
		rep(i,n)
		{
			si(a[i].c);si(a[i].p);si(a[i].tm);
			a[i].s=a[i].c*a[i].p;
		}
		qsort(a,n,sizeof(a[0]),compare);
		for(k=0;k<n;k++)
		{
			x=0;ans=0;j=k;
			while(x<=w && j<n)
			{
				if(x+a[j].tm<=w)
				{
					x+=a[j].tm;
					ans+=a[j].s;
				}
				j++;
				//printf("x=%d ans=%d\n",x,ans);
			}
			//pil(ans);
			mx=max(ans,mx);
		}
		pil(mx);
	}
	return 0;
}







