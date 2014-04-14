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
typedef struct node
{
	int x,y;
}node;
node *a,*b;
int compare1(const void *p, const void *q)
{
	node *a=(node*)p;
	node *b=(node*)q;
	return a->y-b->y;
}
int compare(const void *p, const void *q)
{
	node *a=(node*)p;
	node *b=(node*)q;
	return a->x-b->x;
}
int main()
{
	int i,flag=0;
	a=(node*)malloc(sizeof(node)*8);
	b=(node*)malloc(sizeof(node)*8);
	for(i=0;i<8;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		qsort(a,8,sizeof(node),compare);
	}
	if((a[0].x==a[1].x && a[1].x==a[2].x)&&(a[2].x>a[3].x) && a[3].x==a[4].x && a[4].x>a[5].x && (a[5].x==a[6].x && a[6].x==a[7].x))
		flag=1;
	if(flag==0)
	{
		printf("ugly\n");
		return 0;
	}
	qsort(b,8,sizeof(node),compare1);
	if((b[0].y==b[1].y && b[1].y==b[2].y)&&(b[2].y>b[3].y) && b[3].y==b[4].y && b[4].y>b[5].y && (b[5].y==b[6].y && b[6].y==b[7].y))
		printf("respectable\n");
	return 0;
}





