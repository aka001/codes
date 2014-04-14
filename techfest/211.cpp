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
long long int a[100001],b[100001];
int compare(const void *a, const void *b)
{
	long long int x,y;
	x=*(long long int*)a;
	y=*(long long int*)b;
	if(x-y>=0)
		return 1;
	else
		return -1;
}
int check(long long int n)
{
	return !(n & (n-1));
}
int main()
{
	long long int j,ans,n,i,v,cnt,cnt1,len=0,c;
	sl(n);
	rep(i,n)
		sl(a[i]);
	while(1)
	{
		c=0;
		for(i=0;i<n;)
		{
			cnt=cnt1=1;
			v=a[i];
			i++;
			while(v==a[i] && i<n)
			{
				cnt++;
				i++;
			}
			cnt1=cnt;
			while(1)
			{
				if(check(cnt)==1)
					break;
				cnt--;
			}
			//printf("cnt=%lld\n",cnt);
			b[len++]=(int)log2(cnt)+v;
			//printf("%lld\n",b[len-1]);
			for(j=0;j<cnt1-cnt;j++)
				b[len++]=v;
			c++;
		}
		if(c==n)
			break;
		else
		{
			rep(i,len)
				a[i]=b[i];
			n=len;
			len=0;
			qsort(a,len,sizeof(a[0]),compare);
		}
	}
	qsort(b,len,sizeof(b[0]),compare);
	ans=b[len-1]-(len-1);
	//rep(i,len)
	//	printf("%lld\n",b[i]);
	/*cnt=0;
	ans=0;
	rep(i,len)
	{
		if(b[i]==cnt)
			ans+=0;
		else
			ans+=b[i]-cnt-1;
		cnt=b[i];
	}*/
	pill(ans);
	return 0;
}
















