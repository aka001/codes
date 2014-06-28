/*******************
  Akash Agrawall
  IIIT HYDERABAD
  akash.agrawall094@gmail.com
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
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
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
#define min(a,b) ((a)<(b)?(a):(b))
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n)
#define pdl(n) printf("%lf\n",n)
#define pin(n) printf("%d\n",n)
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define MAX 70000

long long int gcd(long long int a,long long int b)
{
	long long int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

ll powerit(ll a, ll b)
{
	ll x=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			x*=a;
			if(x>=mod)
				x%=mod;
		}
		a=a*a;
		if(a>=mod)
			a%=mod;
		b>>=1;
	}
	return x;
}
struct node
{
	ll lf,rf,mf;
};
node treeit[4*MAX+1];
vector<int> arr;
int sumit[MAX+1];
ll maxit(ll a, ll b)
{
	if(a>b)
		return a;
	return b;
}
void buildtree(int nodeit,int i,int j)
{
	if(i==j)
	{
		//printf("i=%d\n",i);
		treeit[nodeit]=((node){
				arr[i],arr[i],arr[i]
				});
		/*treeit[nodeit].lf=arr[i];
		  treeit[nodeit].rf=arr[i];
		  treeit[nodeit].mf=arr[i];*/
	}
	else
	{
		//printf("i=%d j=%d\n",i,j);
		buildtree(2*nodeit,i,(i+j)/2);
		buildtree(2*nodeit+1,(i+j)/2+1,j);
		node x1,x2;
		x1=treeit[2*nodeit];
		x2=treeit[2*nodeit+1];
		treeit[nodeit].lf=maxit(x1.lf,x2.rf+sumit[(i+j)/2]-sumit[i-1]);
		treeit[nodeit].rf=maxit(x2.rf,x1.lf+sumit[j]-sumit[(i+j)/2]);
		treeit[nodeit].mf=maxit(x1.mf,maxit(x2.mf,x1.mf+x2.mf));
	}
}
node querytree(int nodeit,int i,int j,int q1,int q2)
{
	node left,right;
	if(q1==i && q2==j)
	{
		return treeit[nodeit];
	}
	else if(q2<=(i+j)/2)
		querytree(2*nodeit,i,(i+j)/2,q1,q2);
	if(q1>=(i+j)/2+1)
		querytree(2*nodeit+1,(i+j)/2+1,j,q1,q2);
	left=querytree(2*nodeit,i,(i+j)/2,q1,q2);
	right=querytree(2*nodeit+1,(i+j)/2+1,j,q1,q2);
	return ((node){
			maxit(left.lf,right.rf+sumit[(i+j)/2]-sumit[i-1]),
			maxit(right.rf,left.lf+sumit[j]-sumit[(i+j)/2]),
			maxit(left.mf,maxit(right.mf,left.mf+right.mf))
			});
}
int main()
{
	int n,m,a,b,i,sum=0;
	si(n);
	rep(i,n)
	{
		int val;
		si(val);
		sum+=val;
		arr.pb(val);
		sumit[i]=sum;
	}
	buildtree(1,0,n-1);
	si(m);
	rep(i,m)
	{
		si(a);si(b);
		a--;
		b--;
		printf("%lld\n",querytree(1,0,n-1,a,b).mf);
	}
	return 0;
}





