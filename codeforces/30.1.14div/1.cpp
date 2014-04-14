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
char s[20],t[20],ans[20];
int main()
{
	int h1=0,m1,h2,m2,h3,m3,calc;
	ss(s);
	ss(t);
	h1=(s[0]-'0')*10+(s[1]-'0');
	m1=(s[3]-'0')*10+(s[4]-'0');
	h2=(t[0]-'0')*10+(t[1]-'0');
	m2=(t[3]-'0')*10+(t[4]-'0');
	if(h1==0)
		h1=24;
	m3=m1-m2;
	if(m2>m1)
	{
		m3=60+m1-m2;
		h1--;
	}
	if(h2>h1)
	{
		h1+=24;
	}
	h3=h1-h2;
	//h3=calc/60;
	//m3=calc%60;
	if(h3==24)
		h3=0;
	ans[0]=h3/10+'0';
	ans[1]=h3%10+'0';
	ans[2]=':';
	ans[3]=m3/10+'0';
	ans[4]=m3%10+'0';
	printf("%s\n",ans);
	return 0;
}











