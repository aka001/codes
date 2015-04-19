/*******************
  Akash Agrawall
  IIIT HYDERABAD
 ***********************/


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
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<functional>
#include<numeric>
using namespace std;
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define INF INT_MAX
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz(x) int(x.size())
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n);
#define pdl(n) printf("%lf\n",n);
#define pin(n) printf("%d\n",n)
#define pln(n) printf("%lld\n",n)
#define pl(n) printf("%lld ",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
#define ll long long int
#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
int freq[1000];
vector<int> str[1005];
pair<int,int> ans[1002][27];
char ch[1000006];
void lcs(string X, string Y, int m, int n )
{
	int L[m+1][n+1];

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	   that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}

	// Following code is used to print LCS
	int index = L[m][n];

	// Create a character array to store the lcs string
	char lcs[index+1];
	lcs[index] = '\0'; // Set the terminating character

	// Start from the right-most-bottom-most corner and
	// one by one store characters in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (X[i-1] == Y[j-1])
		{
			lcs[index-1] = X[i-1]; // Put current character in result
			i--; j--; index--;     // reduce values of i, j and index
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}
	printf("%s\n",lcs);
	//cout << lcs <<endl;
}
int main()
{
	int t,i,sz,ptr,j,fl,calc,cnt=0;
	string c1,c2;
	si(t);
	while(t--)
	{
		cnt=0;
		c1=c2="";
		rep(i,1001)
		{
			str[i].clear();
			freq[i]=0;
		}
		ss(ch);
		sz=strlen(ch);
		rep(i,sz)
			freq[ch[i]-'a']++;
		rep(i,26)
		{
			if(freq[i]==0)
				continue;
			str[freq[i]].pb(i);
			//trace2(i,freq[i]);
		}
		FOR(i,1,1001)
		{
			sz=str[i].size();
			//trace2(i,sz);
			sort(str[i].begin(), str[i].end());
			rep(j,sz)
			{
				cnt++;
				c1+=(str[i][j]+'a');
			}
		}
		rep(i,26)
			c2+=('a'+i);
		lcs(c1,c2,cnt,26);
		//sz=str[1].size();
		/*ptr=-1;
		  FOR(i,1,1001)
		  {
		  sz=str[i].size();
		  rep(j,sz)
		  {
		  fl=0;
		  if(ptr==-1)
		  fl=1;
		  if(ptr>=0 && str[i][j]<ans[ptr])
		  ptr--;
		  if((ptr>=0 && str[i][j]>ans[ptr]) || (fl==1))
		  ans[++ptr]=str[i][j];
		  else
		  ++ptr;
		//trace3(ptr,ans[ptr],str[i][j]);
		}
		}
		rep(i,ptr+1)
		{
		printf("%c",ans[i]+'a');
		}
		cout<<endl;*/
	}
	return 0;
}













