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
int a[2001],b[1000][1000];
int main()
{
	int i,n,x,m,k,val,change[101],j,r,flag,val1;
	rep(i,2001)
	{
		a[i]=100000000;
	}
	a[42]=0;
	si(n);si(m);si(r);
	rep(i,n)
		rep(j,m)
		si(b[i][j]);
	rep(i,101)
		change[i]=-1;
	rep(k,n)
		rep(i,n)
		{
			val=100000000;
			flag=0;
			rep(j,m)
			{
				if(a[b[i][j]]!=-1)
				{
					flag=1;
					val=min(a[b[i][j]],val);
				}
			}
			val+=1;
			if(flag!=0)
			{
				rep(j,m)
				{
					if(a[b[i][j]]!=val-1)
					{
						if(a[b[i][j]]!=-1)
							a[b[i][j]]=min(a[b[i][j]],val);
						else
							a[b[i][j]]=val;
					}
				}
				change[i]=1;
				a[val1]=val-1;
			}
		}
	rep(i,r)
	{
		si(val);
		if(a[val]==100000000)
			printf("-1 ");
		else
			printf("%d ",a[val]);
	}
	printf("\n");
	return 0;
}









