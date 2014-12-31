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
long long int a[1000000];
char ch[1000000];
int len;
int searchit(int s, int n)
{
	int i=s+1,flag=1,t=i+len;
	for(;i<t;i++)
	{
		if(ch[i-s-1]=='G')
		{
			if(!(a[i]>a[i-1]))
			{
				flag=0;
				break;
			}
		}
		if(ch[i-s-1]=='L')
		{
			if(!(a[i]<a[i-1]))
			{
				flag=0;
				break;
			}
		}
		if(ch[i-s-1]=='E')
		{
			if(a[i]!=a[i-1])
			{
				flag=0;
				break;
			}
		}
	}
	return flag;
}
int main()
{
	int t,n,ans,i;
	si(t);
	while(t--)
	{
		si(n);
		ans=0;
		rep(i,n)
		{
			sl(a[i]);
		}
		ss(ch);
		len=strlen(ch);
		for(i=0;i<n-len;i++)
		{
			ans=searchit(i,n);
			if(ans)
				break;
		}
		if(ans==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}








