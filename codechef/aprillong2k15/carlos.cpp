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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
vector<ll> arr[204],str[204];
ll visited[204],flag[2000006][3],ar[1000006];
void dfs(int orig, int node, int depth)
{
	if(visited[node])
		return;
	str[orig].pb(node);
	visited[node]=1;
	ll i,sz; sz=arr[node].size();
	rep(i,sz)
	{
		dfs(orig, arr[node][i], depth+1);
	}
}
int binary_search(int val, int i)
{
	int low,high,mid,sz;
	sz=str[i].size();
	low=0;
	high=sz-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		//trace4(mid, str[i][mid], str[i][mid+1], val);
		if(str[i][mid]>=val && (mid==0 || str[i][mid-1]<val))
		{
			//trace1(mid);
			return mid;
		}
		else if(val>str[i][mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
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
	int t,i,j,sz,m,k,n,x,y,low,high,n1,val,fl,lit,ans,i1,hit,v,temp,var,x1,mit;
	sl(t);
	while(t--)
	{
		fl=1;
		sl(m);
		sl(k);
		sl(n);
		FOR(i,0,201)
		{
			arr[i].clear();
			str[i].clear();
		}
		rep(i,k)
		{
			sl(x);
			sl(y);
			arr[x].pb(y);
			arr[y].pb(x);
		}
		FOR(i,1,201)
		{
			rep(j,201)
				visited[j]=0;
			dfs(i, i, 0);
			str[i].pb(i);
		}
		rep(i,201)
		{
			sort(str[i].begin(),str[i].end());
			str[i].erase( unique( str[i].begin(), str[i].end() ), str[i].end() );
			sz=str[i].size();
			if(sz>1)
			{
				//trace1(i);
				//rep(j,sz)
				//	trace3(i, j, str[i][j]);
			}
		}
		//binary_search(1, 2);
		rep(i,n)
		{
			sl(ar[i]);
			flag[i][0]=flag[i][1]=flag[i][2]=mod;
		}
		n1=ar[0];
		high=n1;
		flag[0][1]=0;
		sz=str[n1].size();
		if(sz!=0)
		{
			low=str[n1][0];
			flag[0][0]=0;
			if(low>n1)
				low=n1;
			if(low!=n1)
				flag[0][0]=1;
		}
		else
		{
			low=n1;
			flag[0][0]=0;
		}
		mit=n1;
		flag[0][2]=0;
		//trace5(n1, flag[0][0], flag[0][1],low,high);
		FOR(i, 1, n)
		{
			i1=ar[i];
			x=binary_search(low,i1);
			y=binary_search(high,i1);
			x1=x;
			//trace3(i1,x,y);
			lit=hit=mod;
			if(x==-1)
				flag[i][0]=mod;
			else
			{
				x=str[i1][x];
				if(x>=low && x>=high && x>=mit)
					flag[i][0]=min(flag[i-1][0], min(flag[i-1][1],flag[i-1][2]));
				else if(x>=low && x>=mit)
					flag[i][0]=min(flag[i-1][0], flag[i-1][2]);
				else if(x>=low && x>=high)
					flag[i][0]=min(flag[i-1][0], flag[i-1][1]);
				else if(x>=mit && x>=high)
					flag[i][0]=min(flag[i-1][1], flag[i-1][2]);
				else if(x>=low)
					flag[i][0]=flag[i-1][0];
				else if(x>=high)
					flag[i][0]=flag[i-1][1];
				else if(x>=mit)
					flag[i][0]=flag[i-1][2];
				if(x!=i1)
					flag[i][0]++;
				lit=x;
			}
			if(y==-1)
				flag[i][1]=mod;
			else
			{
				y=str[i1][y];
				if(y>=low && y>=high && y>=mit)
					flag[i][1]=min(flag[i-1][0], min(flag[i-1][1],flag[i-1][2]));
				else if(y>=low && y>=mit)
					flag[i][1]=min(flag[i-1][0], flag[i-1][2]);
				else if(y>=low && y>=high)
					flag[i][1]=min(flag[i-1][0], flag[i-1][1]);
				else if(y>=mit && y>=high)
					flag[i][1]=min(flag[i-1][1], flag[i-1][2]);
				else if(y>=low)
					flag[i][1]=flag[i-1][0];
				else if(y>=high)
					flag[i][1]=flag[i-1][1];
				else if(y>=mit)
					flag[i][1]=flag[i-1][2];
				if(y!=i1)
					flag[i][1]++;
				hit=y;
			}
			{
				y=i1;
				if(y>=low && y>=high && y>=mit)
					flag[i][2]=min(flag[i-1][0],min(flag[i-1][1],flag[i-1][2]));
				else if(y>=low && y>=mit)
					flag[i][2]=min(flag[i-1][0], flag[i-1][2]);
				else if(y>=low && y>=high)
					flag[i][2]=min(flag[i-1][0], flag[i-1][1]);
				else if(y>=mit && y>=high)
					flag[i][2]=min(flag[i-1][1], flag[i-1][2]);
				else if(y>=low)
					flag[i][2]=flag[i-1][0];
				else if(y>=high)
					flag[i][2]=flag[i-1][1];
				else if(y>=mit)
					flag[i][2]=flag[i-1][2];
				if(y!=i1)
					flag[i][2]++;
			}
			low=lit; high=hit; mit=i1;
			//trace6(x, i1, flag[i][0], flag[i][1], low, high);
		}
		ans=min(flag[n-1][0], min(flag[n-1][1], flag[n-1][2]));
		if(ans>n)
			ans=-1;
		pln(ans);
	}
	return 0;
}













