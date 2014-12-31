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
int maxy=-1,cnt=0,visited[100005],hot[100005],path[100005];
int doit(int i)
{
	cnt++;
	if(path[i]==-1)
		return -5;
	else if(hot[path[i]]==1)
	{
		return cnt;
	}
	else
	{
		printf("%d ",i);
		doit(path[i]);
	}
}
int main()
{
	int t,n,i,g,x;
	si(t);
	rep(i,t)
	{
		si(g);
		if(g)
		{
			hot[i+1]=1;
			path[i+1]=i+1;
		}
	}
	rep(i,t)
	{
		si(g);
		if(g!=0 && hot[g]!=1)
		{
			if(path[g]!=0)
				path[g]=-1;
			else
				path[g]=i+1;
		}
	}
	rep(i,t)
	{
		cnt=0;
		if(hot[i+1]!=1)
		{
			x=doit(i+1);
			maxy=max(maxy,x);
		}
		printf("\n");
	}
	pil(maxy);
	return 0;
}





