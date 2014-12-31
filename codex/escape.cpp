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
#define lli		long long int
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

int getint()
{
	char ch;
	int s=0;
	ch=getchar();
	while(ch!=' ' && ch!=' ')
	{
		s=s<<1 + s<<3 + ch-'0';
		ch=getchar();
	}
	return s;
}
int x[10000],y[10000];
std::map<int, std::map<int,int> > mymap;
int main()
{
	int n,stx,sty,a,b,i,min,minx,miny,iter=10;
	long long int calc,ans=0;
	si(n);
	rep(i,n)
	{
		si(x[i]);
		si(y[i]);
	}
	si(x[n]);si(y[n]);
	stx=0;
	sty=0;
	min=1000000000;
	while(1)
	{
		min=100000000;
		rep(i,n+1)
		{
			if(mymap[x[i]][y[i]]!=1 && )
			//if(mymap.find(x[i]) != mymap.end() && mymap[x[i]].find(y[i])!=mymap[x[i]].end())
			{
				calc=(stx-x[i])*(stx-x[i])+(sty-y[i])*(sty-y[i]);
				if(calc<min)
				{
					min=calc;
					minx=x[i];
					miny=y[i];

				}
			}
		}
		mymap[minx][miny]=1;
		ans+=min;
		if(minx==x[n] && miny==y[n])
		{
			break;
		}
		stx=minx;
		sty=miny;
	}
	printf("%lld\n",ans);
	return 0;
}








