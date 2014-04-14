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
int a[100007][4];
int main()
{
	int n,x,i,p,cnt=0;
	si(n);
	FOR(i,1,100001)
		a[i][2]=1;
	FOR(i,1,n+1)
	{
		si(x);
		p=a[x][0];
		a[x][0]=i;
		if(a[x][3]==0)
		{
			a[x][1]=0;
			a[x][2]=0;
			a[x][3]=1;
		}
		else
		{
			if(a[x][1]!=i-p && a[x][3]==1)
			{
				a[x][1]=i-p;
				a[x][2]=0;
				a[x][3]=2;
			}
			else if(a[x][1]==i-p)
			{
				a[x][1]=i-p;
				a[x][2]=0;
				a[x][3]=2;
			}
			else
			{
				a[x][2]=1;
				a[x][3]=2;
			}
		}
		//printf("%d %d %d %d\n",x,a[x][0],a[x][1],a[x][2]);
	}
	FOR(i,1,100001)
	{
		if(a[i][2]==0)
			cnt++;
	}
	pil(cnt);
	FOR(i,1,100000+1)
	{
		if(a[i][2]==0)
		{
			printf("%d %d\n", i, a[i][1]);
		}
	}
	return 0;
}
