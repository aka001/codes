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
	map<string,string> day;
	day["2"]="A";
	day["22"]="B";
	day["222"]="C";
	day["3"]="D";
	day["33"]="E";
	day["333"]="F";
	day["4"]="G";
	day["44"]="H";
	day["444"]="I";
	day["5"]="J";
	day["55"]="K";
	day["555"]="L";
	day["6"]="M";
	day["66"]="N";
	day["666"]="O";
	day["7"]="P";
	day["77"]="Q";
	day["777"]="R";
	day["7777"]="S";
	day["8"]="T";
	day["88"]="U";
	day["888"]="V";
	day["9"]="W";
	day["99"]="X";
	day["999"]="Y";
	day["9999"]="Z";
	day["0"]=" ";
	day["1"]="";
	day["#"]="";
	day["*"]="";

	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
		string temp="";
		int flag=0;
		string ans="";
		for(int i=0;i<input.length();i++)
		{
			if(i==0)
			{
				temp+=input[i];
			}
			else
			{
				if(input[i]==input[i-1])
				{
					temp+=input[i];
				}
				else
				{
					ans+=day[temp];
					temp="";
					temp+=input[i];

				}
			}
		}
		ans+=day[temp];
		temp="";
		cout << ans <<endl;	
	}
	return 0;
}












