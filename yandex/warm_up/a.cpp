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
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
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
#define pi(n) printf("%d ",n)
#define pd(n) printf("%lf ",n)
#define pdl(n) printf("%lf\n",n)
#define pin(n) printf("%d\n",n)
#define pl(n) printf("%lld",n)
#define pln(n) printf("%lld\n",n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define scan(v,n) vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
int rook(int wk1,int wk2,int wr1, int wr2, int bk1,int bk2)
{
	if((wr1==bk1 && !(wk1==wr1 && ((wk2>=wr2 && wk2<=bk2) || (wk2<=wr2 && wk2>=bk2)))) || (wr2==bk2 && !(wk2==wr2 && ((wk1>=wr1 && wk1<=bk1) || (wk1<=wr1 && wk1>=bk1)))))
		return 1;
	return 0;
}
int attack(int wk1,int wk2,int wr1,int wr2,int bk1,int bk2)
{
	int flag=0;
	if(bk1>7 || bk2>7 || bk1<0 || bk2<0)
		return 1;
	if(bk1==wr1 && bk2==wr2)
		flag=1;
	if((wk1+1<=7 && wk1+1==bk1 && wk2==bk2) || (wk1-1>=0 && wk1-1==bk1 && wk2==bk2) || (wk2+1<=7 && wk1==bk1 && wk2+1==bk2) || (wk2-1>=0 && wk1==bk1 && wk2-1==bk2) || (wk1+1<=7 && wk1+1==bk1 && wk2+1==bk2) || (wk1-1>=0 && wk1-1==bk1 && wk2-1==bk2) || (wk1+1<=7 && wk2-1>=0 && wk1+1==bk1 && wk2-1==bk2) || (wk1-1>=0 && wk2+1<=7 && wk1-1==bk1 && wk2+1==bk2) || (rook(wk1,wk2,wr1,wr2,bk1,bk2) && !flag))
		return 1;
	return 0;
}
int main()
{
	char ch,ch1;
	int wk1,wk2,wr1,wr2,bk1,bk2,cnt=0;
	ch=getchar();
	ch1=getchar();
	wk1=ch-'a';
	wk2=ch1-'0';
	ch=getchar();
	ch=getchar();
	ch1=getchar();
	wr1=ch-'a';
	wr2=ch1-'0';
	ch=getchar();
	ch=getchar();
	ch1=getchar();
	bk1=ch-'a';
	bk2=ch1-'0';
	ch=getchar();
	wk2--;
	wr2--;
	bk2--;
	if(((wk1+1==bk1 && wk2==bk2) || (wk1-1==bk1 && wk2==bk2) || (wk1==bk1 && wk2+1==bk2) || (wk1==bk1 && wk2-1==bk2) || (wk1+1==bk1 && wk2+1==bk2) || (wk1-1==bk1 && wk2-1==bk2) || (wk1+1==bk1 && wk2-1==bk2) || (wk1-1==bk1 && wk2+1==bk2)))
	{
		printf("Strange\n");
		return 0;
	}
	if(attack(wk1,wk2,wr1,wr2,bk1,bk2) && (attack(wk1,wk2,wr1,wr2,bk1+1,bk2) && attack(wk1,wk2,wr1,wr2,bk1,bk2+1) && attack(wk1,wk2,wr1,wr2,bk1+1,bk2+1) && attack(wk1,wk2,wr1,wr2,bk1+1,bk2-1) && attack(wk1,wk2,wr1,wr2,bk1-1,bk2+1) && attack(wk1,wk2,wr1,wr2,bk1-1,bk2-1) && attack(wk1,wk2,wr1,wr2,bk1,bk2-1) && attack(wk1,wk2,wr1,wr2,bk1-1,bk2)))
	{
		printf("Checkmate\n");
		return 0;
	}
	if(attack(wk1,wk2,wr1,wr2,bk1,bk2))
	{
		printf("Check\n");
		return 0;
	}
	if((attack(wk1,wk2,wr1,wr2,bk1+1,bk2) && attack(wk1,wk2,wr1,wr2,bk1,bk2+1) && attack(wk1,wk2,wr1,wr2,bk1+1,bk2+1) && attack(wk1,wk2,wr1,wr2,bk1+1,bk2-1) && attack(wk1,wk2,wr1,wr2,bk1-1,bk2+1) && attack(wk1,wk2,wr1,wr2,bk1-1,bk2-1) && attack(wk1,wk2,wr1,wr2,bk1-1,bk2+1) && attack(wk1,wk2,wr1,wr2,bk1-1,bk2)))
	{
		printf("Stalemate\n");
		return 0;
	}
	printf("Normal\n");
	return 0;	
}











