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
int arr[11000],brr[11000];
int main()
{
	int m,s,i,s1;
	si(m);
	si(s);
	s1=s;
	if(s<1 || s>9*m)
	{
		if(s==0 && m==1)
			printf("0 0\n");
		else
			printf("-1 -1\n");
		return 0;
	}
	else
	{
		rep(i,m-1)
			arr[i]=0;
		arr[m-1]=1;
		s--;
		rep(i,m-1)
		{
			if(s<=0)
				break;
			if(s>=9)
				arr[i]+=9;
			else
				arr[i]+=s;
			s-=9;
		}
		if(s>=0)
			arr[m-1]+=s;
		vector<int> v;
		for(i=m-1;i>=0;i--)
		{
			//v.pb(arr[i]);
			printf("%d",arr[i]);
		}
		printf(" ");
		rep(i,m)
			arr[i]=0;
		s=s1;
		rep(i,m)
		{
			if(s<=0)
				break;
			if(s>=9)
				arr[i]=9;
			else
				arr[i]=s;
			s-=9;
		}
		rep(i,m)
			printf("%d",arr[i]);
		printf("\n");
		/*if(arr[0]==0)
		{
			for(i=m-1;i>=0;i--)
			{
				printf("%d",arr[i]);
			}
		}
		else
		{
		*/
	}
	return 0;
}








