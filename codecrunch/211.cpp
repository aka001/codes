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
int main()
{
	std::map<char,string> d;
	d['0']="-----";
	d['1']=".----";
	d['2']="..---";
	d['3']="...--";
	d['4']="....-";
	d['5']=".....";
	d['6']="-....";
	d['7']="--...";
	d['8']="---..";
	d['9']="----.";
	int t,len,i;
	long long cnt,calc;
	char ch1;
	string ch;
	si(t);
	getchar();
	while(t--)
	{
		ch="";len=0;cnt=0;
		scanf("%lld",&calc);
		while(calc!=0)
		{
			//ch.append(d[ch1]);
			ch=d[calc%10+'0']+ch;
			calc/=10;
			//len+=5;
		}
		cout<<ch;
		//printf("%s",ch);
		len=ch.length();
		for(i=0;i<len;i++)
		{
			if(ch[i]=='.')
				cnt++;
		}
		printf("\n%d\n",cnt);
	}
	return 0;
}















