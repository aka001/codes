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
int a[10000],b[10000],c[10000];
int main()
{
	int i,j,n,cnt=0,flag=1;
	si(n);
	rep(i,n)
		si(a[i]);
	for(i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1])
		{
			b[cnt]=a[i];
			c[cnt]=a[i+1];
		}
		else
		{
			b[cnt]=a[i+1];
			c[cnt]=a[i];
		}
		cnt++;
	}
	for(i=0;i<cnt;i++)
	{
		for(j=0;j<cnt;j++)
		{
			if(!((b[i]>=b[j] && c[i]<=c[j]) || (b[i]<=b[j] && c[i]>=c[j]) || (b[i]<=b[j] && c[i]<=b[j]) || (b[i]>=c[j] && c[i]>=c[j])))
			{
				flag=0;
				break;
			}
		}
	}
	if(flag==1)
		printf("no\n");
	else
		printf("yes\n");
	return 0;
}










