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
map<int,int> mapit;
int main()
{
	int n,k,i,a=mod,d=mod,maxit,cnt=0,val,j,pres;
	si(n);
	si(k);
	rep(i,n)
		si(arr[i]);
	for(i=n-1;i>=1;i--)
	{
		cnt=0;
		val=arr[i]-arr[i-1];
		if(mapit[val]==1)
			continue;
		mapit[val]=1;
		pres=arr[i];
		for(j=i+1;j<n;j++)
		{
			if(arr[j]-pres!=val)
			{
				cnt++;
				pres=pres+val;
			}
			else
				pres=arr[j];
			if(cnt>k)
				break;
		}
		if(cnt>k)
			continue;
		pres=arr[i-1];
		for(j=i-2;j>=0;j--)
		{
			//printf("arr[%d]=%d pres=%d val=%d\n",j,arr[j],pres,val);
			if(pres-arr[j]!=val)
			{
				cnt++;
				pres=pres-val;
			}
			else
				pres=arr[j];
			if(cnt>k)
				break;
		}
		if(cnt>k)
			continue;
		if(pres<a)
		{
			a=pres;
			d=val;
		}
		else if(pres==a && val<d)
		{
			d=val;
		}
		/*printf("i=%d arr=%d val=%d arr[i]=%d arr[i-1]=%d\n",i,arr[0],val,arr[i],arr[i-1]);
		rep(i,n)
		{
			printf("%d",pres);
			if(i!=n-1)
				printf(" ");
			else
				printf("\n");
			pres+=val;
		}*/
	}
	val=a;
	rep(i,n)
	{
		printf("%d",val);
		if(i!=n-1)
			printf(" ");
		else
			printf("\n");
		val+=d;
	}
	return 0;
}










