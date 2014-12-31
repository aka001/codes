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
char a[15];
int main()
{
	long long int calc;
	int ans=0,i;
	rep(i,32768)
	{
		if(i&1)
			a[0]='7';
		else
			a[0]='5';
		if(i&2)
			a[1]='7';
		else
			a[1]='5';
		if(i&4)
			a[2]='7';
		else
			a[2]='5';
		if(i&8)
			a[3]='7';
		else
			a[3]='5';
		if(i&16)
			a[4]='7';
		else
			a[4]='5';
		if(i&32)
			a[5]='7';
		else
			a[5]='5';
		if(i&64)
			a[6]='7';
		else
			a[6]='5';
		if(i&128)
			a[7]='7';
		else
			a[7]='5';
		if(i&256)
			a[8]='7';
		else
			a[8]='5';
		if(i&512)
			a[9]='7';
		else
			a[9]='5';
		if(i&1024)
			a[10]='7';
		else
			a[10]='5';
		if(i&2048)
			a[11]='7';
		else
			a[11]='5';
		if(i&4096)
			a[12]='7';
		else
			a[12]='5';
		if(i&8192)
			a[13]='7';
		else
			a[13]='5';
		if(i&16384)
			a[14]='7';
		else
			a[14]='5';
		calc=atoll(a);
		if(i<=20)
		{
			//printf("%d %d %s\n",i,i&2,a);
		}
		if(calc%35==0)
			ans++;
	}
	pil(ans);
	return 0;
}












