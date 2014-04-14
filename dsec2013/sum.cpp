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
int a[100001],b[100001];
int main()
{
	int t,n,i,j,m,k,ar,ans;
	si(t);
	rep(i,t)
	{
		ans=0;
		rep(j,100001)
		{
			a[j]=0;b[j]=0;
		}
		si(n);si(m);si(k);
		rep(j,n)
		{
			si(ar);
			ar=(m-ar)/k+1;
			//printf("ar=%d\n",ar);
			if(ar>=0)
				a[ar]++;
		}
		rep(j,100001)
		{
			if(a[j]!=0)
			{
				ans++;
				//printf("a[%d]=%d\n",j,a[j]);
				//b[a[j]]=1;
			}
		}
		/*rep(j,100001)
			if(b[j]!=0)
			{
				//printf("b[%d]=%d\n",j,b[j]);
				ans++;
			}*/
		pil(ans);
	}
	return 0;
}









