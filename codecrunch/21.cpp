/**Author: Akash Agrawall
  Institution: IIIT Hyderabad **/
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
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
string S;
int l,s;
string ans;
int funct(int n, int s)
{
	if(n==0)
	{
		printf("-----");
		s+=0;
	}
	if(n==1)
	{
		printf(".----");
		s+=1;
	}
	if(n==2)
	{
		printf("..---");
		s+=2;
	}
	if(n==3)
	{
		printf("...--");
		s+=3;
	}
	if(n==4)
	{
		printf("....-");
		s+=4;
	}
	if(n==5)
	{
		printf(".....");
		s+=5;
	}
	if(n==6)
	{
		printf("-....");
		s+=4;
	}
	if(n==7)
	{
		printf("--...");
		s+=3;
	}
	if(n==8)
	{
		printf("---..");
		s+=2;
	}
	if(n==9)
	{
		printf("----.");
		s+=1;
	}
	return s;
}
int main()
{
	int t,s=0;
	char ch;
	si(t);
	getchar();
	while(t--)
	{
		s=0;
		ch=getchar();
		while(ch!='\n')
		{
			s=funct(ch-'0',s);
			//printf("%d\n",s);
			ch=getchar();
		}
		printf("\n%d\n",s);
	}
}














