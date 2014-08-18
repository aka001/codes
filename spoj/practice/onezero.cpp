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
char arr[100000];
ll n;
ll findmod(string ch)
{
	int i=0,lenit=ch.length();
	ll calc=0;
	rep(i,lenit)
	{
		calc=calc*10+ch[i]-'0';
		calc%=n;
	}
	calc%=n;
	return calc;
}
int visited[1000009];
void printit(string ch)
{
	int i,lenit=ch.length();
	rep(i,lenit)
		printf("%c",ch[i]);
	printf("\n");
}
ll getlong()
{
	ll calc=0;
	char ch;
	ch=getchar();
	while(ch!=' ' && ch!='\0' && ch!='\n')
	{
		calc=calc*10+ch-'0';
		ch=getchar();
	}
	return calc;
}
void recurseit(string strit, int modit)
{

}
int main()
{
	int k,i;
	ll modit,calc,calc1,flagit,ans,binit,binit1;
	char chit;
	k=1;
	while(k--)
	{
		queue< pair<int,int> > numbers;
		sl(n);
		calc=n;
		while(calc!=0)
		{
			calc1=calc%10;
			if(calc1!=1 && calc1!=0)
			{
				flagit=0;
				break;
			}
			calc/=10;
		}
		if(flagit==1)
		{
			printf("%lld\n",n);
			continue;
		}
		
		numbers.push(mp(1,1));
		rep(i,n)
			visited[i]=0;
		visited[1]=1;
		while(!numbers.empty())
		{
			binit=numbers.front().first;
			binit1=binit*2;
			modit=(numbers.front().second*10)%n;
			numbers.pop();
			if(modit==0)
			{
				ans=binit1;
				break;
			}
			else if(visited[modit]==0)
			{
				numbers.push(mp(binit1,modit));
				//printit(strit1);
				//printf("modit=%lld visited[modit]=%d sizeit=%d\n",modit,visited[modit],(int)numbers.size());
				visited[modit]=1;
			}
			binit1=binit1+1;
			modit=modit+1;
			if(modit==0 || modit==n)
			{
				ans=binit1;
				break;
			}
			else if(visited[modit]==0)
			{
				numbers.push(mp(binit1,modit));
				//printit(strit1);
				//printf("modit=%lld visited[modit]=%d sizeit=%d\n\n",modit,visited[modit],(int)numbers.size());
				visited[modit]=1;
			}
		}
		string ansit="";
		while(ans!=0)
		{
			ansit=(char)(ans%2+48)+ansit;
			ans>>=1;
		}
		printit(ansit);
	}
	return 0;
}











