/*Author : Akash Agrawall
 Institution: IIIT Hyderabad*/

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
#define sd(n)		scanf("%lf",&n)
#define sl(n)		scanf("%lld",&n)
#define pl(n)		printf("%lld\n",n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
long long int power(long long int a, long long int b)
{
	long long int s=a,ans=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			ans*=s;
		}
		if(ans>1000000007)
			return ans;
		s=s*s;
		if(s>1000000000)
			return s;
		b>>=1;
	}
	return ans;
}
int main()
{
	int t;
	long long int ans,l,d,s,c,ans1;
	si(t);
	while(t--)
	{
		sl(l);sl(d);sl(s);sl(c);
		ans=power(1+c,d-1);
		//printf("%lld %lld %lld\n",1+s,d-2,ans);
		if(ans>1000000000)
			printf("ALIVE AND KICKING\n");
		else
		{
			ans1=ans*s;
			//printf("%lld\n",ans1);
			if(ans1>=l)
				printf("ALIVE AND KICKING\n");
			else
				printf("DEAD AND ROTTING\n");
		}
	}
	return 0;
}






