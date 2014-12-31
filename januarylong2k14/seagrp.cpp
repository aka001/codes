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
#define lli		long long int
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
int M,N;
bool bpGraph[300][300];
int matchR[300];
int getint()
{
	char ch;
	int s=0;
	ch=getchar();
	while(ch!=' ' && ch!=' ')
	{
		s=s<<1 + s<<3 + ch-'0';
		ch=getchar();
	}
	return s;
}
bool bpm(bool bpGraph[300][300], int u, bool seen[], int matchR[])
{
	for (int v = 0; v < N; v++)
	{
		if (bpGraph[u][v] && !seen[v])
		{
			seen[v] = true;

			if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
			{
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

int maxBPM(bool bpGraph[300][300])
{

	memset(matchR, -1, sizeof(matchR));

	int result = 0;
	for (int u = 0; u < M; u++)
	{
		bool seen[N];
		memset(seen, 0, sizeof(seen));
		if (bpm(bpGraph, u, seen, matchR))
			result++;
	}
	return result;
}
int main()
{
	int t,x,y,m,ans;
	si(t);
	while(t--)
	{
		si(N);si(m);
		M=N;
		rep(i,N)
			rep(j,N)
				bpGraph[i][j]=0;
		rep(i,m)
		{
			si(x);si(y);
			bpGraph[x-1][y-1]=1;
		}
		ans=maxBPM(bpGraph);
		/*rep(i,N)
		{
			printf("%d %d\n",i,matchR[i]);
		}*/
		//printf("%d\n",ans);
		if(m&01==1)
			printf("NO\n");
		else if(ans==m/2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
