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
int n1,arr[1000006];
void bubbleup(int n)
{
	int calc,temp;
	while(n!=1 && n!=0)
	{
		calc=n/2;
		if(arr[calc]>arr[n])
		{
			temp=arr[calc];
			arr[calc]=arr[n];
			arr[n]=temp;
		}
		else
			break;
		n=calc;
	}
}
void bubbledown(int n)
{
	int calc,calc1,m1,v,temp;
	//printf("n=%d n1=%d\n",n,n1);
	while(2*n<=n1)
	{
		calc=2*n;
		calc1=2*n+1;
		m1=calc;
		v=arr[calc];
		//printf("arr[%d]=%d m1=%d\n",calc,arr[calc],m1);
		if(calc1<=n1 && arr[calc1]<v)
		{
			m1=calc1;
		}
		//printf("arr[%d]=%d  arr[%d]=%d\n",n,arr[n],m1,arr[m1]);
		if(arr[m1]>arr[n])
			break;
		temp=arr[m1];
		arr[m1]=arr[n];
		arr[n]=temp;
		n=m1;
	}
}
void insert(int val)
{
	n1++;
	arr[n1]=val;
	bubbleup(n1);
}
int delit()
{
	int val;
	val=arr[1];
	arr[1]=arr[n1];
	n1--;
	bubbledown(1);
	return val;
}
int main()
{
	int i,n,val,cal,j;
	n1=0;
	si(n);
	rep(i,n)
	{
		si(val);
		insert(val);
	}
	FOR(i,1,n+1)
	{
		//printf("here %d\n",arr[i]);
	}
	rep(i,n)
	{
		cal=delit();
		pin(cal);
		//printf("i=%d\n",i);
	}
	return 0;
}










