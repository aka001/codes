/*Author : Akash Agrawall
 Institution: IIIT Hyderabad*/

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
#define lli		long long int
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sd(n)		scanf("%lf",&n)
#define sl(n)		scanf("%lld",&n)
#define pl(n)		printf("%lld\n",n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

int getint()
{
	char ch;
	int s=0;
	ch=getchar();
	while(ch!=' ' && ch!=' ')
	{
		s=s<<1 + s<<3 + ch-'0';
		ch=getchar();
	}
	return s;
}
char ch[1000000],ch1[1000000];
int main()
{
	int calc,len,c1=0,c2=0,flag=1,len1;
	ss(ch);
	ss(ch1);
	len=strlen(ch);
	len1=strlen(ch1);
	rep(i,len)
	{
		if(ch[i]=='|')
		{
			flag=0;
		}
		if(flag)
			c1++;
		else
			c2++;
	}
	c2-=1;
	if(c1>c2)
	{
		calc=len1-c1+c2;
		if((calc>0 && calc%2==0)||(calc==0))
		{
			rep(j,calc/2)
				printf("%c",ch1[j]);
			printf("%s",ch);
			calc>>=1;
			rep(j,c1-c2+calc)
				printf("%c",ch1[j+calc]);
			printf("\n");
		}
		else
			printf("Impossible\n");
	}
	else if(c1<c2)
	{
		calc=len1-c2+c1;
		if((calc>=0 && calc%2==0)||(calc==0))
		{
			rep(j,c2-c1+calc/2)
				printf("%c",ch1[j]);
			printf("%s",ch);
			rep(j,calc/2)
				printf("%c",ch1[j+(c2-c1 + calc/2)]);
			printf("\n");
		}
		else
			printf("Impossible\n");
	}
	else
	{
		if(len1%2==0)
		{
			len1>>=1;
			rep(j,len1)
				printf("%c",ch1[j]);
			printf("%s",ch);
			rep(j,len1)
				printf("%c",ch1[j+len1]);
			printf("\n");
		}
		else
			printf("Impossible\n");
	}
	return 0;
}





