/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	akash.agrawall094@gmail.com
	***********************/

#include<sstream>
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
typedef struct node
{
	ll x,y,z;
}node;
node *arr;
string convert(ll a)
{
	string ch1="";
	while(a!=0)
	{
		ch1+=a%10+48;
		a/=10;
	}
	return ch1;
}
vector<string> storeit;
int main()
{
	int i;
	ll min,max,a,b,c,third,val,ans=0,n;
	string ch="",ch1,ch2,ch3;
	stringstream strstream;
	map<string, int> mapit;
	arr=(node*)malloc(sizeof(node)*100007);
	sl(n);
	rep(i,n)
	{
		ch="";
		sl(a);
		sl(b);
		sl(c);
		min=a;
		max=a;
		if(b<min)
			min=b;
		if(c<min)
			min=c;
		if(b>max)
			max=b;
		if(c>max)
			max=c;
		third=a+b+c-max-min;
		ch+=convert(min)+convert(max)+convert(third);
		if(mapit[ch]==0)
			storeit.pb(ch);
		mapit[ch]++;
		arr[i].x=third;
		arr[i].y=min;
		arr[i].z=max;
	}
	n=storeit.size();
	ans=0;
	rep(i,n)
	{
		if(mapit[storeit[i]]==1)
			ans++;
	}
	pln(ans);
	return 0;
}










