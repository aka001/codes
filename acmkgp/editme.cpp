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
int a[1000],b[1000],c[100][100];
int main()
{
	int i,j,x,t,m,n;
	si(t);
	while(t--)
	{
		si(m);
		rep(i,m)
			si(a[i]);
		si(n);
		rep(i,n)
			si(b[i]);
		rep(i,m)
		{
			rep(j,n)
			{
				if(i==0 && j==0)
				{
					if(a[i]==b[j])
					{
						c[i][j]=0;
					}
					else
						c[i][j]=1;
				}
				else
				{
					if(a[i]==b[j])
						c[i][j]=c[i-1][j-1];
					else
					{
						x=min(min(1+c[i][j-1],1+c[i-1][j]),(1+c[i-1][j-1]));
						c[i][j]=x;
					}
				}
			}
		}
		printf("%d\n",c[m-1][n-1]);
	}
	return 0;
}










