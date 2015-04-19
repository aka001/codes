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
#define F first
#define S second
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int arr[1000006][2],sg[1000006],n;
char ch[1000006];
pair<int,int> query(int,int,int,int,int);
void initialize(int node, int l, int u)
{
	if(l==u)
	{
		if(ch[l]=='R')
			arr[node][0]++;
		else
			arr[node][1]++;
	}
	else
	{
		initialize(2*node,l,(l+u)/2);
		initialize(2*node+1, (l+u)/2+1, u);
		int i;
		rep(i,2)
			arr[node][i]=arr[2*node][i]+arr[2*node+1][i];
	}
}
inline void update(int node, int p, int q, int a, int b)
{
	int temp;
	if(sg[node])
	{
		temp=arr[node][0];
		arr[node][0]=arr[node][1];
		arr[node][1]=temp;
		if(p!=q)
		{
			sg[2*node]^=sg[node];
			sg[2*node+1]^=sg[node];
		}
		sg[node]=0;
	}
	if(p>b || q<a || p>q)
		return;
	if(p==q)
	{
		if(p>=a && p<=b)
		{
			temp=arr[node][0];
			arr[node][0]=arr[node][1];
			arr[node][1]=temp;
		}
		return;
	}
	if(p>=a && q<=b)
	{
		temp=arr[node][0];
		arr[node][0]=arr[node][1];
		arr[node][1]=temp;
		sg[2*node]^=1;
		sg[2*node+1]^=1;
		return;
	}
	update(2*node, p, (p+q)/2, a, b);
	update(2*node+1, (p+q)/2+1, q, a, b);
	int i;
	rep(i,2)
		arr[node][i]=arr[2*node][i]+arr[2*node+1][i];
}
inline pair<int,int> query(int node, int p, int q, int a, int b)
{
	int temp;
	if(sg[node])
	{
		temp=arr[node][0];
		arr[node][0]=arr[node][1];
		arr[node][1]=temp;
		if(p!=q)
		{
			sg[2*node]^=sg[node];
			sg[2*node+1]^=sg[node];
		}
		sg[node]=0;
	}
	if(p>b || q<a || p>q)
		return mp(0,0);
	else if(p>=a && q<=b)
		return mp(arr[node][0],arr[node][1]);
	else
	{
		pair<int,int> p1,p2,p3;
		p1=query(2*node, p, (p+q)/2, a, b);
		p2=query(2*node+1, (p+q)/2+1, q, a, b);
		p3.F=p1.F+p2.F;
		p3.S=p1.S+p2.S;
		return p3;
	}
}
//Source: http://codeforces.com/blog/entry/8080
int getint() {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
/*int getint()
  {
  char ch;
  int calc=0;
  ch=getchar();
  while(ch!='\n' && ch!=' '&& ch!='\0')
  {
  calc=calc*10+ch-'0';
  ch=getchar();
  }
  return calc;
  }*/
int main()
{
	//std::ios_base::sync_with_stdio( false );
	int k,ans=0,i,t,val,j;
	pair<int,int> calc,cit;
	si(t);
	while(t--)
	{
		ans=0;
		si(n);
		si(k);
		ss(ch);
		rep(i,1000006)
			rep(j,2)
				arr[i][j]=0;
		initialize(1,0,n-1);
		rep(i,n)
		{
			val=min(n-1,i+k-1);
			calc=query(1,0,n-1,i,val);
			cit=query(1,0,n-1,i,i);
			//printf("i=%d F=%d S=%d val=%d Fit=%d Sit=%d\n",i,calc.F,calc.S,val,cit.F,cit.S);
			if(calc.F==0 || cit.S==1)
				continue;
			if(calc.F>0)
				ans++;
			update(1,0,n-1,i,val);
		}
		pin(ans);
	}
	return 0;
}













