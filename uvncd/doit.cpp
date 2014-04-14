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
int a[1000],b[1000],c[10000000],d[1000000];
int compare(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int i,cnt=0,j,cnt1=0;
	for(i=1;i<=1000;i++)
	{
		a[i-1]=i*i;
	}
	for(i=0;i<1000;i++)
	{
		for(j=i+1;j<1000;j++)
		{
			c[cnt++]=a[i]+a[j];
		}
	}
	printf("%d\n",cnt);
	qsort(c,cnt,sizeof(c[0]),compare);
	for(i=0;i<cnt;i++)
	{
		if(c[i]!=c[i+1])
			d[cnt1++]=c[i];
	}
	pil(cnt1);
	printf("a[1000]={");
	for(i=0;i<cnt1;i++)
	{
		printf("%d",d[i]);
		if(i==cnt1-1)
			printf("};\n");
		else
			printf(",");
	}
	return 0;
}





