/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	akash.agrawall094@gmail.com
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

int arr[1000006],n,m,cnt,brr[1000006],crr[1000006];
int compare(pair<int,int> s1, pair<int,int> s2)
{
	return s1.first<s2.first;
}
void merge_them(vector< pair<int,int> > pairit)
{
	int fir,sec,i,val1,val2;
	fir=pairit[0].first;
	sec=pairit[0].second;
	//printf("fir=%d sec=%d\n",fir,sec);
	brr[0]=fir;
	crr[0]=sec;
	cnt++;
	//printf("m=%d\n",m);
	FOR(i,1,m)
	{
		fir=pairit[i].first;
		sec=pairit[i].second;
		val1=brr[cnt-1];
		val2=crr[cnt-1];
		//printf("val1=%d val2=%d fir=%d sec=%d\n",val1,val2,fir,sec);
		if(val2<fir)
		{
			//printf("fir=%d sec=%d\n",fir,sec);
			brr[cnt]=fir;
			crr[cnt]=sec;
			cnt++;
		}
		else if(val2<sec)
		{
			crr[cnt-1]=sec;
		}
	}
}
int main()
{
	int t,flagit,a,b,i,flagit1,j;
	si(t);
	while(t--)
	{
		cnt=0;
		vector< pair<int,int> > pairit;
		flagit=1;
		si(n);
		si(m);
		rep(i,n)
			si(arr[i]);
		rep(i,m)
		{
			si(a);
			si(b);
			a--;
			b--;
			pairit.pb(mp(a,b));
		}
		sort(pairit.begin(),pairit.end(),compare);
		//printf("%d %d\n",pairit[0].first,pairit[0].second);
		merge_them(pairit);
		//printf("cnt=%d\n",cnt);
		rep(i,cnt)
		{
			a=brr[i];
			b=crr[i];
			flagit1=1;
			FOR(j,a,b+1)
			{
				if(arr[j]>b+1 || arr[j]<a+1)
				{
					flagit1=0;
					flagit=0;
					//printf("i=%d arr[i]=%d a=%d b=%d\n",i,arr[i],a,b);
					break;
				}
			}
			if(flagit1==0)
			{
				break;
			}
			/*if(!(minit==a+1 && maxit==b+1))
			{
				//printf("a=%d b=%d minit=%d maxit=%d\n",a,b,minit,maxit);
				flagit=0;
				break;
			}*/
		}
		if(flagit==1)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	return 0;
}












