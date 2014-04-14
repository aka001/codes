/**Author: Akash Agrawall
  Institution: IIIT Hyderabad **/
#include<stdio.h>
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
int l;
int main()
{
	int c,n,m,t,calc;
	si(c);
	while(c--)
	{
		si(n);si(m);si(t);
		if(n<m)
		{
			printf("%d\n",2*t);
			continue;
		}
		if(n%m==0)
			calc=(n/m)*2*t;
		else
			calc=(n/m+1)*2*t;
		printf("%d\n",calc);
	}
	return 0;
}





