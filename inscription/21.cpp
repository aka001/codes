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

#define FOR(i,a,b) 	for(i= (int )a ; i < (int )b ; ++i)
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
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define pill(n)         printf("%lld\n",n)
#define sl(n)		scanf("%lld",&n)
#define sd(n)		scanf("%lf",&n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
int main()
{
	int t,p,max,temp,q,a,b,c,oa,ob,oc,cnt=1;
	si(t);
	while(t--)
	{
		cnt=1;
		si(a);si(b);si(c);
		oa=a;
		ob=b;
		oc=c;
		max=oa;
		p=ob;
		q=oc;
		if(ob>max)
		{
			max=ob;
			p=oa;
			q=oc;
		}
		if(oc>max)
		{
			max=oc;
			p=oa;
			q=ob;
		}
		printf("%d %d %d\n",p,q,max);
		max--;
		while(1)
		{
			cnt++;
			if(p>q)
			{
				p--;
				temp=max;
				max=p;
				p=max;
			}
			else
			{
				q--;
				temp=max;
				max=q;
				q=max;
			}
			printf("%d %d %d\n",p,q,max);
			if(p==0 && q==0 && max==0)
				break;
		}
		printf("%d\n",cnt);
		if(cnt%2==0)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}











