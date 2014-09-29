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
int bit[1000006]={0};
int arr[1000006],n;
int bt,maxval;
void update(int val,int calc)
{
	while(val<maxval)
	{
		bit[val]+=calc;
		val+=(val&(-val));
	}
}
int findit(int val, int low)
{
	int idx=0,mid;
	while(bt!=0 && idx<maxval)
	{
		mid=idx+bt;
		//printf("mid=%d aray=%d val=%d\n",mid,bit[mid],val);
		if(val==bit[mid])
		{
			return mid;
		}
		else if(val>bit[mid])
		{
			idx=mid;
			val-=bit[mid];
		}
		bt>>=1;
	}
}
int findsum(int val)
{
	int sum=0;
	while(val>0)
	{
		sum+=bit[val];
		val=val-(val&(-val));
	}
	return sum;
}
int main()
{
	int t,sv,cnt,n1,i,val,val1,rot;
	si(t);
	while(t--)
	{
		si(n);
		memset(bit,0,n+1);
		n++;
		n1=n;
		sv=0;
		cnt=0;
		while(n1!=0)
		{
			cnt++;
			if(n1%2==1)
			{
				sv=cnt;
			}
			n1>>=1;
		}
		bt=1<<(sv-1);
		maxval=(bt<<1)-1;
		printf("bt=%d maxval=%d\n",bt,maxval);
		FOR(i,1,n)
		{
			update(i,1);
		}
		val=1;
		cnt=n;
		rot=1;
		while(cnt>0)
		{
			val1=findsum(val);
			val=findit(rot+val1,0);
			printf("cnt=%d val1=%d val=%d rot=%d  %d %d\n",cnt,val1,val,rot,bit[2],bit[3]);
			val=val%n;
			if(val==0)
				val=n;
			update(val,-1);
			arr[val]=rot;
			val=(val+1)%n;
			if(val==0)
				val=n;
			rot++;
			cnt--;
		}
		FOR(i,1,n)
			printf("%d\n",arr[i]);
	}
	return 0;
}














