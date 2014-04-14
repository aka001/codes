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
int a[1000000],b[1000000][2];
int main()
{
	int n,i,lp,min=1000000000,calc,rn,z=0;
	si(n);
	lp=0;rn=0;
	FOR(i,0,n)
	{
		si(a[i]);
		if(a[i]<0)
			rn++;
		if(a[i]==0)
			z++;
	}
	rep(i,n)
	{
		if(a[i]<0)
			rn--;
		b[i][0]=lp;
		b[i][1]=rn;
		if(a[i]>0)
		{
			lp++;
		}
		//printf("%d %d\n",b[i][0],b[i][1]);
	}
	rep(i,n)
	{
		calc=b[i][0]+b[i][1]+z;
		if(calc<min)
			min=calc;
	}
	pil(min);
	return 0;
}













