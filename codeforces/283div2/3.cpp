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
char ch[1006][1006];
int flg[1006],flg1[1006];
int main()
{
	int n,m,ans=0,i,j,x,flag;
	si(n);
	si(m);
	rep(i,n)
	{
		ss(ch[i]);
	}
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	rep(i,m)
	{
		x=ch[0][i];
		flag=1;
		FOR(j,1,n)
			flg1[j]=flg[j];
		FOR(j,1,n)
		{
			if(flg[j]==0 && ch[j][i]<x)
			{
				flag=0;
				break;
			}
			else if(ch[j][i]>x)
			{
				flg[j]=1;
			}
			x=ch[j][i];
		}
		if(flag==0)
		{
			FOR(j,1,n)
				flg[j]=flg1[j];
			//cout<<i<<endl;
			ans++;
		}
	}
	pin(ans);
	return 0;
}












