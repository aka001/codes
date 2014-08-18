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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}

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
string strit(ll n)
{
	ll calc;
	string rit="";
	if(n==0)
	{
		rit+='0';
		return rit;
	}
	while(n!=0)
	{
		calc=n%10;
		rit=(char)(calc+48)+rit;
		n/=10;
	}
	return rit;
}
int main()
{
	ll t,i,sizeit,flagit=0,flagit1=0,caseit;
	ll calc1,calc2,calc3,ans;
	char ch;
	string prt;
	sl(t);
	ch=getchar();
	while(t--)
	{
		prt="";
		flagit=flagit1=0;
		calc1=calc2=calc3=0;
		ch=getchar();
		ch=getchar();
		while(ch!='\n' && ch!='\0')
		{
			if(ch=='+')
				flagit=1;;
			if(ch=='=')
				flagit1=1;
			if(flagit==0)
			{
				if(ch=='m')
					caseit=1;
				else if(ch>='0' && ch<='9')
				{
					calc1=calc1*10+ch-'0';
				}
			}
			else if(flagit==1 && flagit1==0)
			{
				if(ch=='m')
					caseit=2;
				else if(ch>='0' && ch<='9')
				{
					calc2=calc2*10+ch-'0';
				}
			}
			else
			{
				if(ch=='m')
					caseit=3;
				else if(ch>='0' && ch<='9')
				{
					calc3=calc3*10+ch-'0';
				}
			}
			ch=getchar();
		}
		//pin(caseit);
		if(caseit==1)
		{
			ans=calc3-calc2;
			prt+=strit(ans)+" + "+strit(calc2)+" = "+strit(calc3)+"\n";
		}
		else if(caseit==2)
		{
			ans=calc3-calc1;
			prt+=strit(calc1)+" + "+strit(ans)+" = "+strit(calc3)+"\n";
		}
		else
		{
			ans=calc1+calc2;
			prt+=strit(calc1)+" + "+strit(calc2)+" = "+strit(ans)+"\n";
		}
		cout << prt;
	}
	return 0;
}












