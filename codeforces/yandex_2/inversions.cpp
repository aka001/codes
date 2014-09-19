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
#define FOR(i,a,b) for(int i= a ; i < b ; ++i)
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
int arr[1000006];
int main()
{
	int k,ind,ind1,i,n,x,temp,val,val1,k1;
	ll mid,low,high,calc,calc1;
	si(k);
	low=0;
	high=100000;
	while(low<=high)
	{
		mid=(low+high)/2;
		calc=(mid*(mid-1))/2;
		calc1=((mid-1)*(mid-2))/2;
		if(calc>=k && calc1<k)
		{
			break;
		}
		else if(calc>k)
			high=mid-1;
		else
			low=mid+1;
	}
	if(k==0)
	{
		mid=1;
	}
	FOR(i,1,mid+1)
		arr[i]=i;
	if(mid==1)
	{
		printf("1\n1\n");
		return 0;
	}
	n=mid;
	val=n;
	x=(k+1)/2;
	if(x*2!=(k+1))
		x++;
	val1=n;
	ind1=1;
	ind=n;
	while(1)
	{
		temp=arr[ind];
		arr[ind]=arr[ind1];
		arr[ind1]=temp;
		if(x>=ind-ind1)
			x=ind-ind1;
		//printf("first x=%d\n",x);
		k1=k-(x*2-1);
		x=x*2-1-k;
		k=k1;
		//printf("second x=%d k=%d\n",x,k);
		if(x>=0)
			break;
		if(x==-1)
			x=-x;
		ind--;
		ind1++;
		//printf("x=%d\n",x);
	}
	ind=ind1;
	//ind-=1;
	while(x>0)
	{
		calc=n-ind1;
		if(calc<=x)
		{
			ind1=n;
		}
		else
			ind1=ind+x;
		temp=arr[ind];
		arr[ind]=arr[ind1];
		arr[ind1]=temp;
		x-=calc;
	}
	//printf("%d\n",n);
	FOR(i,1,n+1)
	{
		printf("%d",arr[i]);
		if(i!=n)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}








