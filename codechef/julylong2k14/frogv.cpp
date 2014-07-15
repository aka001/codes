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
#define max(a,b) ((a)>(b)?(a):(b))
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
 
int brr[100009],arr[100009];
map<int,int> flagit;
int compare(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,p,k,i,x,y,calc,x1,y1;
	int val;
	si(n);
	si(p);
	si(k);
	rep(i,n)
	{
		si(val);
		arr[i]=val;
		brr[i]=val;
	}
	sort(brr,brr+n);
	//qsort(brr,n,sizeof(int),compare);
	rep(i,n)
		flagit[brr[i]]=-1;
	flagit[brr[0]]=brr[0];
	FOR(i,1,n)
	{
		calc=brr[i]-brr[i-1];
		if((calc<=k))
			flagit[brr[i]]=flagit[brr[i-1]];
		else
			flagit[brr[i]]=brr[i];
	}
	rep(i,p)
	{
		si(x);
		si(y);
		x--;y--;
		if(x>=n || y>=n)
		{
			printf("No\n");
			continue;
		}
		x1=arr[x];
		y1=arr[y];
		if(flagit.find(x1)==flagit.find(y1))
		{
			//printf("%d %d\n",flagit[x1],flagit[y1]);
			printf("Yes\n");
		}
		else
			printf("No\n");
	}
	return 0;
}













