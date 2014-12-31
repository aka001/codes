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
int l;
string ans;
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char c,d;
		int sum=0,flag=0;
		cin >> c;
		cin >> d;
		if(c=='2')
			sum+=2;	
		else if(c=='3')
			sum+=3;
		else if(c=='4')
			sum+=4;
		else if(c=='5')
			sum+=5;
		else if(c=='6')
			sum+=6;
		else if(c=='7')
			sum+=7;
		else if(c=='8')
			sum+=8;
		else if(c=='9')
			sum+=9;
		else if(c=='A')
		{
			if(d=='A')
				sum+=2;
			else
				sum=0;
		}	
		else if(c=='Q')
			sum+=10;
		else if(c=='J')
			sum+=10;
		else if(c=='K')
			sum+=10;
		else 
			flag=1;
		if(d=='2')
			sum+=2;	
		else if(d=='3')
			sum+=3;
		else if(d=='4')
			sum+=4;
		else if(d=='5')
			sum+=5;
		else if(d=='6')
			sum+=6;
		else if(d=='7')
			sum+=7;
		else if(d=='8')
			sum+=8;
		else if(d=='9')
			sum+=9;
		else if(d=='A')
		{
			if(c=='A')
				sum+=12;
			else
				sum=0;
		}
		else if(d=='Q')
			sum+=10;
		else if(d=='J')
			sum+=10;
		else if(d=='K')
			sum+=10;
		else 
			flag=1;
		if(flag==1)
			printf("INVALID\n");
		else
		{
			if(sum<=11)
				printf("HIT\n");
			else
				printf("STAND\n");
		}

	}
	return 0;
}














