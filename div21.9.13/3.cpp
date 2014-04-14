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
typedef struct doit
{
	int x,y,z;
}doit;
string S;
int l;
string ans;
int compare(const void *a, const void *b)
{
	doit p=*(doit*)a;
	doit q=*(doit*)b;
	if(p.z-q.z>0)
		return 1;
	else
		return 0;
}
int main()
{
	doit *a;
	int t,x,i,y,calc=0;
	si(t);
	a=(doit*)malloc(sizeof(doit)*t);
	rep(i,t)
	{
		si(a[i].x);
		si(a[i].y);
		//a[i].z=a[i].x*a[i].x+a[i].y*a[i].y;
		a[i].z=(int)sqrt(abs(a[i].x)*abs(a[i].x)+abs(a[i].y)*abs(a[i].y));
	}
	qsort(a,t,sizeof(a[0]),compare);
	rep(i,t)
	{
		if(a[i].x==0 || a[i].y==0)
			calc+=4;
		else
			calc+=6;
	}
	printf("%d\n",calc);
	rep(i,t)
	{
		if(a[i].x==0 || a[i].y==0)
		{
			if(a[i].y==0)
			{
				if(a[i].x>0)
				{
					printf("1 %d  R\n",a[i].x);
					printf("2\n");
					printf("1 %d  L\n",a[i].x);
					printf("3\n");
				}
				else
				{
					printf("1 %d  L\n",-a[i].x);
					printf("2\n");
					printf("1 %d  R\n",-a[i].x);
					printf("3\n");
				}

			}
			if(a[i].x==0)
			{
				if(a[i].y>0)
				{
					printf("1 %d  U\n",a[i].y);
					printf("2\n");
					printf("1 %d  D\n",a[i].y);
					printf("3\n");
				}		
				else
				{
					printf("1 %d  D\n",-a[i].y);
					printf("2\n");
					printf("1 %d  U\n",-a[i].y);
					printf("3\n");
				}
			}
		}
		else
		{
			if(a[i].x>0)
			{
				printf("1 %d R\n",a[i].x);
				if(a[i].y>0)
				{
					printf("1 %d U\n",a[i].y);
					printf("2\n");
					printf("1 %d D\n",a[i].y);
				}
				else
				{
					printf("1 %d D\n",-a[i].y);
					printf("2\n");
					printf("1 %d U\n",-a[i].y);
				}
				printf("1 %d L\n",a[i].x);
				printf("3\n");
			}
			if(a[i].x<0)
			{
				printf("1 %d L\n",-a[i].x);
				if(a[i].y>0)
				{
					printf("1 %d U\n",a[i].y);
					printf("2\n");
					printf("1 %d D\n",a[i].y);
				}
				else
				{
					printf("1 %d D\n",-a[i].y);
					printf("2\n");
					printf("1 %d U\n",-a[i].y);
				}
				printf("1 %d R\n",-a[i].x);
				printf("3\n");
			}
		}
	}
	return 0;
}




