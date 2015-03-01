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
int sg[1000006];
int sz;
//Initializing the segment tree
void initialize(int node,int b, int e)
{
	if(b==e)
	{
		sg[node]=0;
	}
	else
	{
		initialize(2*node,b,(b+e)/2);
		initialize(2*node+1,(b+e)/2+1,e);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
//Updating the segment tree for the values which are to be deleted/inserted
void update(int node, int b, int e, int ch)
{
	if(b>ch || e<ch)
		return;
	if(b==e && b==ch)
		sg[node]=1;
	else if(b!=e)
	{
		update(2*node, b, (b+e)/2, ch);
		update(2*node+1, (b+e)/2+1, e, ch);
		sg[node]=sg[2*node]+sg[2*node+1];
	}
}
//Finding the count of the numbers lesser than a given number
int sumit(int node, int b, int e, int x, int y)
{
	if(b>y || e<x)
		return 0;
	else if(b>=x && e<=y)
		return sg[node];
	else
	{
		int p1,p2;
		p1=sumit(2*node, b, (b+e)/2, x, y);
		p2=sumit(2*node+1, (b+e)/2+1, e, x, y);
		return p1+p2;
	}
}
int binary_search(int n)
{
	int low=n,high=sz,mid,calc,calcit;
	mid=(low+high)/2;
	while(low<=high)
	{
		mid=(low+high)/2;
		calc=sumit(1,0,sz,low,mid);
		//printf("low=%d high=%d  mid=%d calc=%d\n",low,high,mid,calc);	
		if(mid==low)
		{
			if(calc==1)
				return low;
			else
				return -1;
		}
		calcit=sumit(1,0,sz,low,mid-1);
		if(calc==1 && calcit==0)
			return mid;
		else if(calc>=1)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
vector<int> arr;
int a[100006],hashit[100006];
ll lit[100006],rit[100006];
map<int,int> mapit;
int main()
{
	int n,cnt=1,i,calc,maxit;
	ll ans;
	si(n);
	rep(i,n)
	{
		si(a[i]);
		arr.pb(a[i]);
	}
	sort(arr.begin(),arr.end());
	rep(i,n)
	{
		if(mapit[arr[i]]==0)
			mapit[arr[i]]=cnt++;
	}
	sz=cnt;
	//pin(sz);
	rep(i,n)
	{
		a[i]=mapit[a[i]];
		//printf("%d ",a[i]);
	}
	initialize(1,0,sz);
	maxit=-mod;
	rep(i,n)
	{
		if(maxit<=a[i])
		{
			hashit[a[i]]=i+1;
			update(1,0,sz,a[i]);
			maxit=max(maxit,a[i]);
			continue;
		}
		//printf("i=%d a=%d maxit=%d\n",i,a[i],maxit);
		calc=binary_search(a[i]+1);
		if(calc==-1)
			lit[i]=0;
		else
			lit[i]=hashit[calc];
		if(hashit[a[i]]==0)
			update(1,0,sz,a[i]);
		hashit[a[i]]=i+1;
	}
	/*rep(i,n)
		printf("%lld ",lit[i]);
	printf("\n");*/
	rep(i,sz+1)
		hashit[i]=0;
	initialize(1,0,sz);
	maxit=-mod;
	for(i=n-1;i>=0;i--)
	{
		if(lit[i]==0 || maxit<=a[i])
		{
			hashit[a[i]]=i+1;
			update(1,0,sz,a[i]);
			maxit=max(maxit,a[i]);
			continue;
		}
		calc=binary_search(a[i]+1);
		if(calc==-1)
			rit[i]=0;
		else
			rit[i]=hashit[calc];
		if(hashit[a[i]]==0)
			update(1,0,sz,a[i]);
		update(1,0,sz,a[i]);
		hashit[a[i]]=i+1;
	}
	ans=-mod;
	rep(i,n)
	{
		ans=max(ans,lit[i]*rit[i]);
	}
	pln(ans);
	return 0;
}












