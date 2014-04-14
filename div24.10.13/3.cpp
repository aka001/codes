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
int compare(const void *a, const void *b)
{
	double x;
	x=*(double*)a-*(double*)b;
	if(x>=0)
		return -1;
	else
		return 1;
}
double a[100000];
int main()
{
	int t,i,st,i1,st1;
	double x,calc=0,calc1=0,ax,bx,cx,dx,save;
	si(t);
	t=2*t;
	rep(i,t)
	{
		sd(x);
		a[i]=x-(int)x;
	}
	qsort(a,t,sizeof(double),compare);
	//rep(i,t)
	//	printf("%lf\n",a[i]);
	i=0;
	while(a[i]!=0)
		i++;
	st=i;
	if(st&01==1)
	{
		i1=1;
		st1=st+2;
		calc=calc1=0;
		FOR(i1,1,st1/2)
		{
			calc=calc+1-a[st1-i1-2]-a[i1];
			//printf("%d %d %lf\n",i1,st1-i1-2,calc);
		}
		FOR(i1,1,st1/2)
			calc1=calc1-a[st1-i1-2]+1-a[i1];
		printf("%lf %lf\n",calc,calc1);
		ax=max(calc+1-a[0],calc-a[0]);
		bx=min(calc+1-a[0],calc-a[0]);
		cx=min(calc+1-a[0],calc-a[0]);
		dx=max(calc+1-a[0],calc-a[0]);
		ax=abs(ax);bx=abs(bx);cx=abs(cx);dx=abs(dx);
		if(bx<ax)
			ax=bx;
		if(cx<ax)
			ax=cx;
		if(dx<ax)
			ax=dx;
		save=ax;
	}
	calc=calc1=0;
	rep(i,st/2)
		calc=calc+1-a[st-i-1]-a[i];
	rep(i,st/2)
		calc1=calc1-a[st-i-1]+1-a[i];
	if(st&01)
	{
		ax=max(calc+1-a[st],calc-a[0]);
		bx=min(calc+1-a[st],calc-a[0]);
		cx=min(calc+1-a[st],calc-a[0]);
		dx=max(calc+1-a[st],calc-a[0]);
		ax=abs(ax);bx=abs(bx);cx=abs(cx);dx=abs(dx);
		if(bx<ax)
			ax=bx;
		if(cx<ax)
			ax=cx;
		if(dx<ax)
			ax=dx;
		if(ax<save)
			save=ax;
		printf("%.3lf\n",save);
		return 0;
	}
	//printf("%lf %lf\n",calc,calc1);
	calc=abs(calc);
	calc1=abs(calc1);
	//printf("%lf %lf\n",calc,calc1);
	if(calc1<calc)
		calc=calc1;
	printf("%.3lf\n",calc);
	return 0;
}
