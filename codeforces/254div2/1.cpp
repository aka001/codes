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
int arr[1000][1000];
char ch[10000];
int main()
{
	int n,m,i,j,len,flag;
	si(n);
	si(m);
	rep(i,n)
	{
		ss(ch);
		len=strlen(ch);
		rep(j,len)
		{
			flag=2;
			if(i>0 && arr[i-1][j]!=2)
			{
				flag=arr[i-1][j];
			}
			if(j>0 && arr[i][j-1]!=2)
			{
				flag=arr[i][j-1];
			}
			if(ch[j]=='-')
			{
				arr[i][j]=2;
				continue;
			}
			if(flag==2)
			{
				if(i>0 && j<=m-2 && arr[i-1][j+1]!=2)
					arr[i][j]=arr[i-1][j+1];
				else
					arr[i][j]=1;
			}
			else
				arr[i][j]=1-flag;
		}
	}
	rep(i,n)
	{
		rep(j,m)
		{
			if(arr[i][j]==0)
				cout<<'W';
			else if(arr[i][j]==1)
				cout<<'B';
			else
				cout<<'-';
		}
		cout<<endl;
	}
	return 0;
}









