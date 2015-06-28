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

#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define INF		INT_MAX
#define FOR(i,a,b) 	for(int  i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define FORAB(i,a,b)      for(int i=(int)a; i<=b; i++)
#define PB push_back
#define MP make_pair
#define fill(a,b) memset(a,b,sizeof(a))
#define mod (int)(1e9 + 7)
#define F first
#define S second
#define asd(x) cout << "Here for " << #x << " :" <<x << endl
#define asdf(x, y)  cout << "Here FOR " << #x << " :" << x << " " << #y  << " :" << y << endl
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d ",n)
#define pil(n) printf("%d\n",n)
#define pl(n) printf("%lld ",n)
#define pll(n) printf("%lld\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)

typedef long long int LL;
typedef vector <int> VI;
typedef pair < int ,int > PII;
int main()
{
	long long int n;
	sl(n);
	LL digit=0;
	LL temp=n;
	while(temp!=0)
  	{
      temp/=10; 
      //pil(temp);
      digit++;
 	}
 	//cout<<digit<<endl;
 	//pil(digit);
 	//asd(digit);
 	LL ans=0;
 	LL t=0;
 	LL no=9;
 	for (LL i=1;i<digit;i++)
 	{
 		t=i-1;
 		ans+=(no*i);
		no*=10;
 	}
 	//pll(ans);
	LL ne=1;
	rep(i,digit-1)
		ne*=10;
	ne--;
 	//pil
 	//asd(ne);
 	LL nn=(n-ne);
 	//asd(nn);
 	//ans+=
 	LL teee=(nn*digit);
 	//asd(teee);
 	ans+=teee;
 	pll(ans);
	return 0;
}


