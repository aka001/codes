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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
char ch[1000006],ch1[1000006],ch2[1000006];
int visited[100006];
/*int start[1000006],end[1000006];
int time=0;
int dfs(int node)
{
	int sz,itit;
	sz=arr[node].size();
	if(visited[node]==1)
		return;
	time++;
	start[node]=time;
	visited[node]=1;
	rep(i,sz)
	{
		itit=arr[node][i];
		dfs(itit);
	}
	end[node]=time;
}*/
int checkit=0;
vector<int> arr[56];
void dfsit(int node, int node1)
{
	if(visited[node]==1)
		return;
	visited[node]=1;
	if(node==node1)
	{
		checkit=1;
		return;
	}
	int i,sz,itit;
	sz=arr[node].size();
	rep(i,sz)
	{
		itit=arr[node][i];
		dfsit(itit,node1);
	}
}
int ansit[27][27];
void dfs(int node, int node1)
{
	int i,sz,itit;
	ansit[node][node1]=1;
	if(visited[node1]==1)
		return;
	//printf("node=%d node1=%d\n",node,node1)
	visited[node1]=1;
	sz=arr[node1].size();
	rep(i,sz)
	{
		itit=arr[node1][i];
		dfs(node,itit);
	}
}
int main()
{
	int p,flg,i,mp,j,l1,l2,flag;
	char c,c1;
	si(p);
	while(p--)
	{
		ss(ch);
		ss(ch1);
		rep(i,27)
			rep(j,27)
				ansit[i][j]=0;
		rep(i,27)
			arr[i].clear();
		si(mp);
		getchar();
		while(mp--)
		{
			ss(ch2);
			c=ch2[0];
			c1=ch2[3];
			c-='a';
			c1-='a';
			arr[c].pb(c1);
		}
		l1=strlen(ch);
		l2=strlen(ch1);
		rep(i,l1)
			ch[i]-='a';
		rep(i,l2)
			ch1[i]-='a';
		if(l1!=l2)
		{
			printf("NO\n");
			continue;
		}
		/*rep(i,300)
		{
			if(check[i]==1 && visited[i]==0)
			{
				dfs(i);
			}
		}*/
		rep(i,27)
		{
			rep(j,27)
				visited[j]=0;
			dfs(i,i);
		}
		/*rep(i,27)
		{
			rep(j,27)
			{
				printf("%c %d ",j+'a',ansit[i][j]);
			}
			printf("\n");
		
		}*/
		flg=0;
		rep(i,l1)
		{
			/*rep(j,27)
				visited[j]=0;
			checkit=0;
			dfsit(ch[i],ch1[i]);
			if(checkit==0)
			{
				printf("NO\n");
				flg=1;
				break;
			}*/
			if(ansit[ch[i]][ch1[i]]==0)
			{
				printf("NO\n");
				flg=1;
				break;
			}
		}
		if(flg)
			continue;
		printf("YES\n");
	}
	return 0;
}












