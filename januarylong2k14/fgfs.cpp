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
int getint()
{
	char ch; 
	int s=0;
	ch=getchar();
	while(ch!=' ' && ch!='\n')
	{   
		//s=s<<1 + s<<3 + ch-'0';
		s=s*10+ch-'0';
		ch=getchar();
	}   
	return s;
}

typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef struct node
{
	int s,f;
	int v;
}node;
node *arr;
int compare(const void *a, const void *b)
{
	node *x=(node*)a;
	node *y=(node*)b;
	if(x->v==y->v)
	{
		return x->f - y->f;
		/*if(x->f==y->f)
		{
			if(x->s-y->s>0)
				return 1;
			else
				return -1;
		}
		else
		{
			if(x->f-y->f>=0)
				return 1;
			else
				return -1;	
		}*/
	}
	else
		return x->v-y->v;
}
int main()
{
	int t,n,k,i,ans,fn,st,com,fnlt,comlt;
	t=getint();
	while(t--)
	{
		ans=1;
		arr=(node*)malloc(sizeof(node)*1000000);
		n=getint();
		k=getint();
		rep(i,n)
		{
			//scanf("%d %d %d",&arr[i].s,&arr[i].f,&arr[i].v);
			arr[i].s=getint();
			arr[i].f=getint();
			arr[i].v=getint();
		}
		qsort(arr,n,sizeof(arr[0]),compare);
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		//printf("\n");
		//rep(i,n)
		//	printf("%d %d %d\n",arr[i].s, arr[i].f, arr[i].v);
		fnlt=arr[0].f;
		comlt=arr[0].v;
		FOR(i,1,n)
		{
			st=arr[i].s;
			fn=arr[i].f;
			com=arr[i].v;
			if(st>=fnlt && com==comlt && com>=1 && com<=k)
			{
				fnlt=fn;
				ans++;
				//printf("1. st=%d fn=%d fnlt=%d com=%d\n",st,fn,fnlt,com);
			}
			else if(com!=comlt && com>=1 && com<=k)
			{
				ans++;
				comlt=com;
				fnlt=fn;
				//printf("2. st=%d fn=%d fnlt=%d com=%d\n",st,fn,fnlt,com);
			}
		}
		pil(ans);
	}
	return 0;
}












