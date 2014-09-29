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
void initialize(int,int,int);
int queryit(int,int,int,int,int);
int binary(int,int,int);
int sg[10000006],n;
int arr[1000006];
void initialize(int node, int b, int e)
{
	if(b==e)
	{
		sg[node]=1;
	}
	else
	{
		initialize(2*node,b,(b+e)/2);
		initialize(2*node+1,(b+e)/2+1,e);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
void update(int node, int b, int e, int pos, int clc)
{
	if(b==e)
	{
		if(b==pos)
		{
			sg[node]=clc;
		}
	}
	else
	{
		update(2*node,b,(b+e)/2,pos,clc);
		update(2*node+1,(b+e)/2+1,e,pos,clc);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
int queryit(int node,int b, int e, int i, int j)
{
	if(e<i || b>j)
		return -1;
	else if(b>=i && e<=j)
		return sg[node];
	else
	{
		int p1,p2;
		p1=queryit(2*node,b,(b+e)/2,i,j);
		p2=queryit(2*node+1,(b+e)/2+1,e,i,j);
		if(p1==-1)
			return p2;
		else if(p2==-1)
			return p1;
		else
			return p1+p2;
	}
}
int binary(int low, int high, int val)
{
	int mid,cl,v1,mid1,cl1,nw=low;
	cl=queryit(1,0,n-1,low,n-1);
	while(val>cl)
	{
		//printf("val=%d cl=%d\n",val,cl);
		val-=cl;
		low=0;
		nw=low;
		cl=queryit(1,0,n-1,0,n-1);
	}
	while(nw<=high)
	{
		cl=queryit(1,0,n-1,low,nw);
		if(cl==val)
			return nw;
		nw++;
	}
	/*mid=(low+high)/2;
	while(mid>=low && mid<=high)
	{
		cl=queryit(1,0,n-1,low,mid);
		if(mid!=0)
			cl1=queryit(1,0,n-1,low,mid-1);
		else
			cl1=mod;
		//printf("cal=%d low=%d mid=%d high=%d val=%d\n",cl,low,mid,high,val);
		if(cl==val && cl1!=val)
		{
			return mid;
		}
		else if(val>cl)
		{
			mid1=mid;
			mid=(mid+high)/2;
			if(mid==mid1)
				mid++;
		}
		else
		{
			mid1=mid;
			mid=(low+mid)/2;
			high=mid1;
		}
	}*/
}
int main()
{
	int p,t,v,cnt=0,rot,calc,val,i,cl,v1,rot1;
	si(t);
	while(t--)
	{
		cnt=0;
		si(n);
		initialize(1,0,n-1);
		//val=queryit(1,0,n-1,0,2);
		//printf("val=%d\n",val);
		v=0;
		cnt=0;
		rot=1;
		rot1=1;
		while(cnt<n)
		{
			//printf("v=%d calc=%d rot=%d cnt=%d\n",v,calc,rot,cnt);
			rot=rot1%(n-cnt)+1;
			v%=n;
			//printf("v=%d calc=%d rot=%d cnt=%d\n",v,calc,rot,cnt);
			calc=binary(v,n-1,rot);
			calc=calc%n;
			arr[calc]=cnt+1;
			//printf("v=%d calc=%d rot=%d cnt=%d\n",v,calc,rot,cnt);
			v=calc;
			v1=v;
			v++;
			update(1,0,n-1,v1,0);
			arr[calc]=cnt+1;
			val=calc;
			rot1++;
			cnt++;
		}
		FOR(i,0,n)
		{
			printf("%d",arr[i]);
			if(i==n-1)
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}










