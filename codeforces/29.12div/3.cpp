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
int a[501][501],vis[501][501],cit=0,n,m;
int arr[1000001][2];
void dfs(int v,int x, int y)
{
	if(v==1 && vis[x][y]==0 && x>=0 && x<n && y>=0 && y<m)
	{
		vis[x][y]=1;
		arr[cit][0]=x;
		arr[cit][1]=y;
		cit++;
		dfs(a[x-1][y],x-1,y);
		dfs(a[x+1][y],x+1,y);
		dfs(a[x][y+1],x,y+1);
		dfs(a[x][y-1],x,y-1);
	}
}
int main()
{
	int i,j,k,hx,hy;
	char ch;
	hx=hy=-1;
	si(n);si(m);si(k);
	ch=getchar();
	rep(i,n)
	{
		rep(j,m)
		{
			ch=getchar();
			if(ch=='#')
				a[i][j]=0;
			else
			{
				a[i][j]=1;
				if(hx==-1)
				{
					hx=i;
					hy=j;
				}
			}
		}
		ch=getchar();
	}
	dfs(a[hx][hy],hx,hy);
	rep(i,k)
	{
		//printf("%d %d\n",arr[cit-i-1][0],arr[cit-i-1][1]);
		a[arr[cit-i-1][0]][arr[cit-i-1][1]]=2;
	}
	rep(i,n)
	{
		rep(j,m)
		{
			if(a[i][j]==0)
				printf("#");
			else if(a[i][j]==1)
				printf(".");
			else
				printf("X");
		}
		printf("\n");
	}
	return 0;
}





