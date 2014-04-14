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
int l,a[1000000];
string ans;
int compare(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,n,k,j,k1;
	long long int max,min,min1;
	si(n);
	si(k1);
	rep(i,n)
		si(a[i]);
	qsort(a,n,sizeof(a[0]),compare);
	/*rep(i,n)
		pi(a[i]);
	printf("\n");
	prntf("k=%d\n",k1);*/
	min1=1000000000;
	for(j=0;j<n-k1;j++)
	{
		min=a[j];
		max=a[j+k1-1];
		if((max-min)<min1)
			min1=max-min;
		//printf("min=%lld max=%lld ",min,max);
		//printf("%lld\n",min1);
	}
	printf("%lld\n",min1);
	return 0;
}











