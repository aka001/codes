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
string ans;
typedef struct doit
{
	long long int x,y;
}doit;
int compare(const void *a, const void *b)
{
	doit d=*(doit*)a;
	doit e=*(doit*)b;
	if(d.x-e.x>=0)
		return 1;
	else
		return -1;
}
int compare1(const void *a, const void *b)
{
	doit d=*(doit*)a;
	doit e=*(doit*)b;
	if(d.y-e.y>=0)
		return 1;
	else
		return -1;
}
doit *a;
int main()
{
	int temp,t,n,i,cnt,cnt1;
	si(t);
	while(t--)
	{
		si(n);
		cnt=cnt1=1;
		a=(doit*)malloc(sizeof(doit)*10000);
		rep(i,n)
		{
			sl(a[i].x);
			sl(a[i].y);	
		}
		qsort(a,n,sizeof(a[0]),compare);
		/*rep(i,n)
			printf("%d %d   ",a[i].x,a[i].y);
		printf("\n");*/
		temp=a[0].x;
		FOR(i,1,n)
		{
			if(temp!=a[i].x)
			{
				cnt++;
			}
			temp=a[i].x;
		}
		//pil(cnt);
		qsort(a,n,sizeof(a[0]),compare1);
		/*rep(i,n)
			printf("%d %d   ",a[i].x,a[i].y);
		printf("\n");*/
		temp=a[0].y;
		FOR(i,1,n)
		{
			if(temp!=a[i].y)
			{
				cnt1++;
			}
			temp=a[i].y;
		}
		//pil(cnt1);
		pil(min(cnt,cnt1));
	}
}











