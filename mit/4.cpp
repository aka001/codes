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
int a[1000000],b[1000000];
void doit(int n)
{
	int i=0,cnt,l,j;
	rep(i,n)
	{
		a[i]=i+1;
	}
	cnt=n;
	rep(i,100000)
	{
		//printf("n=%d\n",n);
		cnt=0;
		if(n%2==1)
		{
			b[cnt++]=a[n-1];
			n--;
		}
		for(j=1;j<n;j+=2)
		{
			b[cnt++]=a[j];
			//printf("b[%d]=%d\t",cnt-1,b[cnt-1]);
		}
		//printf("\n");
		//printf("cnt=%d\n",cnt);
		n=cnt;
		rep(j,n)
			a[j]=b[j];
		if(cnt==2 || cnt==3)
		{
			printf("%d\n",b[1]);
			return;
		}
	}
}
int main()
{
	int i,n;
	while(1)
	{
		si(n);
		if(n==0)
		{
			break;
		}
		if(n==1 || n==2)
		{
			printf("%d\n",n);
			continue;
		}
		else if(n==3)
		{
			printf("2\n");
			continue;
		}
		doit(n);
	}
	return 0;
}












