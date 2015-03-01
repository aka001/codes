/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/


#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<stdlib.h>
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
int n,ans=-1,arr[1000006],str[1000006];
void solve(int i1, int val)
{
	if(i1>=n)
	{
		ans=max(ans,val);
		return;
	}
	int cnt=0,val1,val2,cnt1=0,i;
	val1=arr[i1]+val;
	char s[50];
	cnt=0;
	while(val1!=0)
	{
		val2=val1%10;
		str[cnt++]=val2;
		val1/=10;
	}
	sort(str,str+cnt);
	cnt1=0;
	rep(i,cnt)
	{
		s[cnt1++]=str[i]+'0';
	}
	s[cnt1]='\0';
	do
	{
		val1=atoi(s);
		//printf("i1=%d val1=%d arr[i]=%d val=%d %s cnt=%d\n",i1,val1,arr[i1],val,s,cnt);
		solve(i1+1,val1);
	}while(std::next_permutation(s,s+cnt1));
}
int main()
{
	int i;
	si(n);
	rep(i,n)
	{
		si(arr[i]);
	}
	solve(0,0);
	pin(ans);
	return 0;
}








