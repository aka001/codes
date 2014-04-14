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
int a[1000001],p[1000000];
int main()
{
	int i,l=0,j,s=0,ans,max=-123,max1=-1,cnt;
	a[0]=0;
	a[1]=0;
	for(i=2;i<=1000000;i++)
		a[i]=1;
	for(i=2;i<=1000;i++)
	{
		if(a[i])
		for(j=i*i;j<=1000000;j+=i)
		{
			a[j]=0;
		}
	}
	for(i=2;i<=1000000;i++)
	{
		if(a[i])
			p[l++]=i;
	}
	for(i=0;i<l;i++)
	{
		cnt=0;
		s=0;
		for(j=i;j<l;j++)
		{
			s+=p[j];
			cnt++;
			if(s<1000000 && a[s]==1)
			{
				if(cnt>=max1)
				{
					max=s;
					max1=cnt;
				}
			}
			else if(s>=1000000)
				break;
		}
	}
	pil(max);
	pil(max1);
	return 0;
}






