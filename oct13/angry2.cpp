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
int l,a[1000000],sum[1000000],b[1000000];
string ans;
int compare(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,k,i,j,s;
	si(n);
	si(k);
	for(i=0;i<n;i++)
		si(a[i]);
	qsort(a,n,sizeof(a[0]),compare);
	for(i=0;i<k;i++)
		s+=a[i];
	sum[0]=s;
	for(i=k;i<n;i++)
	{
		s+=a[i]-a[i-k];
		sum[i-k+1]=s;
	}
	for(i=0;i<=n-k;i++)
		printf("%d ",sum[i]);
	printf("\n");
	b[0]=k*a[k-1]-sum[0];
	pil(b[0]);
	return 0;
}









