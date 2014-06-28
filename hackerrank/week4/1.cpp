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
 
long long int gcd(long long int a,long long int b)
{
	long long int c;
	while(a!=0)
	{
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

void seive()
{
	int i,j;
	int MAX=1000006;
	int isprime[1000006]; 
	isprime[0] = isprime[1] = 1; 
	for (i = 4; i < MAX; i += 2)
		isprime[i] = 1; 
	for (i = 3; i * i < MAX; i += 2) 
	{
		if (!isprime[i]) 
		{
			for (j = i * i; j < MAX; j += 2 * i)
				{
					isprime[j] = 1; 
				}
		}
	}
}
ll powerit(ll a, ll b)
{
	ll x=1;
	while(b!=0)
	{
		if(b&01==1)
		{
			x*=a;
			if(x>=mod)
				x%=mod;
		}
		a=a*a;
		if(a>=mod)
			a%=mod;
		b>>=1;
	}
	return x;
}

char arr1[1000000];
bool findpallindrome(vector<char> arrit, int lenit)
{
	bool val=true;
	int i,sizeit,sizeit1;
	sizeit1=lenit;
	sizeit=sizeit1/2;
	rep(i,sizeit)
	{
		if(arrit[i]!=arrit[sizeit1-i-1])
		{
			val=false;
			break;
		}
	}
	return val;
}
int main()
{
	int t,lenit,i,flagit,lenit1,calc;
	char ch;
	si(t);
	ch=getchar();
	while(t--)
	{
		vector<char> arr;
		vector<char> copyit;
		string s;
		getline(cin,s);
		lenit=s.length();
		strcpy(arr1,s.c_str());
		lenit1=lenit;
		lenit>>=1;
		flagit=0;
		rep(i,lenit1)
		{
			arr.pb(arr1[i]);
		}
		rep(i,lenit)
		{
			if(arr[i]!=arr[lenit1-i-1])
			{
				copyit=arr;
				copyit.erase(copyit.begin()+i);
				calc=arr.size();
				if(findpallindrome(copyit,lenit1-1))
					printf("%d\n",i);
				else
					printf("%d\n",lenit1-i-1);
				flagit=1;
				break;
			}
		}
		if(flagit==0)
			printf("-1\n");
	}
	return 0;
}

