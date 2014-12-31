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
char ch[1000006];
vector<pair<int,int> > arr;
vector<int> brr;
map<int,int> mapit;
int f[1000006];
int main()
{
	int n,cnt,homo=0,hetero=0,i,val,fl,calc;
	si(n);
	rep(i,n)
	{
		ss(ch);
		si(val);
		if(ch[0]=='i')
			fl=1;
		else
			fl=2;
		arr.pb(mp(fl,val));
		brr.pb(val);
	}
	sort(brr.begin(),brr.end());
	cnt=0;
	rep(i,n)
	{
		if(i==n-1 || brr[i]!=brr[i+1])
		{
			mapit[brr[i]]=cnt++;
		}
	}
	rep(i,n)
	{
		fl=arr[i].F;
		val=arr[i].S;
		calc=mapit[val];
		//printf("%d %d\n",fl,val);
		if(fl==1)
		{
			if(f[calc]==0)
				hetero++;
			else if(f[calc]==1)
				homo++;
			f[calc]++;
		}
		else
		{
			if(f[calc]==1)
				hetero--;
			else if(f[calc]==2)
				homo--;
			if(f[calc]!=0)
				f[calc]--;
		}
		//printf("homo=%d hetero=%d val=%d f=%d\n",homo,hetero,val,f[calc]);
		if(homo>=1 && hetero>=2)
			printf("both\n");
		else if(homo>=1)
			printf("homo\n");
		else if(hetero>=2)
			printf("hetero\n");
		else
			printf("neither\n");
	}
	return 0;
}
















