/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/


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
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
#define gc getchar_unlocked
vector<int> arr[204], grph[201];
int visited[204],flag[2][201],ar[1000006], str[201][201];
void dfs(int orig, int node, int depth)
{
	if(visited[node])
		return;
	str[orig][node]=1;
	//grph[orig].pb(node);
	visited[node]=1;
	int i,sz; sz=arr[node].size();
	rep(i,sz)
	{
		dfs(orig, arr[node][i], depth+1);
	}
}
void scanint(int &x)
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
	int t,i,j,sz,m,k,n,x,y,low,high,n1,val,fl,lit,ans,i1,hit,v,temp,var,ait,io;
	scanint(t);
	//si(t);
	while(t--)
	{
		fl=1;
		scanint(m);
		scanint(k);
		scanint(n);
		/*si(m);
		si(k);
		si(n);*/
		FOR(i,0,m+1)
		{
			arr[i].clear();
			//str[i].clear();
		}
		rep(i,k)
		{
			scanint(x);
			scanint(y);
			//sl(x);
			//sl(y);
			arr[x].pb(y);
			arr[y].pb(x);
		}
		FOR(i,1,m+1)
		{
			sort(arr[i].begin(), arr[i].end());
			arr[i].erase(unique(arr[i].begin(), arr[i].end()), arr[i].end());
		}
		rep(i,m+1)
		{
			flag[0][i]=mod;
			rep(j,m+1)
				str[i][j]=mod;
		}
		FOR(i,1,m+1)
		{
			rep(j,m+1)
				visited[j]=0;
			dfs(i, i, 0);
			str[i][i]=0;
			/*FOR(j, 1, m+1)
			  {
			  if(str[i][j] != mod)
			  trace3(i, j, str[i][j]);
			  }*/
		}
		//printf("hie\n");
	/*	FOR(i, 1, m+1)
		{
			sort(grph[i].begin(), grph[i].end());
			grph[i].erase(unique(grph[i].begin(), grph[i].end()), grph[i].end());
		}*/
		/*FOR(i,1,m+1)
		  {
		  FOR(j, 1, m+1)
		  {
		  if(str[i][j]!=mod)
		  trace3(i, j, str[i][j]);
		  }
		  }*/
		rep(i,n)
		{
			scanint(ar[i]);
			//sl(ar[i]);
		}
		rep(i,m+1)
		{
			if(str[ar[0]][i] != mod)
			{
				flag[0][i]=str[ar[0]][i];
			}
		}
		FOR(i,1,n)
		{
			i1=ar[i];
			io=ar[i-1];
			FOR(j, 1, m+1)
				flag[1][j]=mod;
			low=1;
			ait=mod;
			//sz=grph[i1].size();
			FOR(k,1,m+1)
			{
				j=k;
				if(str[i1][j]<mod)
				{
					while(low<=j)
					{
						if(str[io][low] != mod)
							ait=min(ait, flag[0][low]);
						low++;
					}
					flag[1][j]=ait;
					//trace3(i1, j, ait);
					if(j!=i1)
						flag[1][j]++;
				}
			}
			/*FOR(j, 1, m+1)
			  {
			  if(str[i1][j]<mod)
			  {
			  ait=mod;
			  FOR(k,1,j+1)
			  {
			  if(str[io][k] != mod)
			  ait=min(ait, flag[0][k]);
			  }
			  flag[1][j]=ait;
			  if(j!=i1)
			  flag[1][j]++;
			//trace3(i1,j, flag[1][j]);
			}
			}*/
			FOR(j,1,m+1)
				flag[0][j]=flag[1][j];
		}
		ans=mod;
		FOR(i, 1, m+1)
		{
			ans=min(ans, flag[0][i]);
		}
		if(ans>n)
			ans=-1;
		pin(ans);
	}
	return 0;
}













