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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int arr[1000006],sg[1000006],n;
int query(int,int,int,int,int);
void initialize(int node, int l, int u)
{
	if(l==u)
	{
		arr[node]=0;
	}
	else
	{
		initialize(2*node,l,(l+u)/2);
		initialize(2*node+1, (l+u)/2+1, u);
		arr[node]=arr[2*node]+arr[2*node+1];
	}
}
inline void update(int node, int p, int q, int a, int b, int val)
{
	if(sg[node])
	{
		arr[node]+=(q-p+1)*sg[node];
		if(p!=q)
		{
			sg[2*node]+=sg[node];
			sg[2*node+1]+=sg[node];
		}
		sg[node]=0;
	}
	if(p>b || q<a || p>q)
		return;
	if(p==q)
	{
		if(p>=a && p<=b)
			arr[node]+=val;
		return;
	}
	if(p>=a && q<=b)
	{
		arr[node]+=(q-p+1)*val;
		sg[2*node]+=val;
		sg[2*node+1]+=val;
		return;
	}
	update(2*node, p, (p+q)/2, a, b,val);
	update(2*node+1, (p+q)/2+1, q, a, b,val);
	arr[node]=arr[2*node]+arr[2*node+1];
}
inline int query(int node, int p, int q, int a, int b)
{
	if(sg[node])
	{
		arr[node]+=(q-p+1)*sg[node];
		if(p!=q)
		{
			sg[2*node]+=sg[node];
			sg[2*node+1]+=sg[node];
		}
		sg[node]=0;
	}
	if(p>b || q<a || p>q)
		return 0;
	else if(p>=a && q<=b)
		return arr[node];
	else
	{
		int p1,p2;
		p1=query(2*node, p, (p+q)/2, a, b);
		p2=query(2*node+1, (p+q)/2+1, q, a, b);
		return p1+p2;
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
	int q,i,val,val1,val2,calc,sz,val3,t;
	si(t);
	while(t--)
	{
		//si(n);
		n=getint();
		initialize(1,0,n-1);
		//cin>>q;
		//si(q);
		q=getint();
		vector<int> ansit;
		rep(i,q)
		{
			val=getint();
			val1=getint();
			val2=getint();
			val1--;
			val2--;
			//printf("val=%d val1=%d val2=%d i=%d q=%d\n",val,val1,val2,i,q);
			/*si(val);
			  si(val1);
			  si(val2);*/
			if(val==0)
			{
				val3=getint();
				update(1,0,n-1,val1,val2,val3);
			}
			else
			{
				calc=query(1,0,n-1,val1,val2);
				pin(calc);
				//cout<<calc<<endl;
				//ansit.pb(calc);
				//fflush(stdout);
			}
		}
	}
	return 0;
}













