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
char ch[1000000];
int checkit(char arr[], int posi,int posj, int pos1i, int pos1j)
{
	while(posi<=posj)
	{
		if(ch[posi]<ch[pos1i] || ch[posi]==48 || ch[pos1i]==48)
		{
			return 0;
		}
		posi++;
		pos1i++;
	}
	return 1;
}
int divideandconquer(char ch[],int posi,int posj,int pos1i,int pos1j)
{
	if(posi==posj || pos1i==pos1j)
	{
		return 1;
	}
	if(checkit(ch,posi,posj,pos1i,pos1j)==1)
	{
		int calc,calc2;
		calc=divideandconquer(ch,posi,(posi+posj)/2,(posi+posj)/2+1,posj);
		calc2=divideandconquer(ch,pos1i,(pos1i+pos1j)/2,(pos1i+pos1j)/2+1,pos1j);
		printf("calc=%d calc2=%d\n",calc,calc2);
		return 2+calc+calc2;
	}
	else
		return 0;
}
int main()
{
	int i,n,ans=0;
	ss(ch);
	n=strlen(ch);
	ans=divideandconquer(ch,0,n/2-1,n/2,n-1);
	if(ans==0)
	{
		if(checkit(ch,0,n/2-1,n/2,n-1))
			ans=2;
		else
			ans=1;
	}
	printf("%d\n",ans);
	return 0;
}









