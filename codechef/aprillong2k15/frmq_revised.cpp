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
#define gc getchar_unlocked
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
//Referred from https://mayanknatani.wordpress.com/2013/07/15/range-minimum-query/
/*void Compute_ST(int N){
	int i,j;
	for(j=1;(1<<j)<=N ;j++){
		for(i=0;i+(1<<j)-1<N;i++){
			if(M[i][j-1]>M[i+(1<<(j-1))][j-1])
				M[i][j]=M[i][j-1];
			else
				M[i][j]=M[i+(1<<(j-1))][j-1];
		}
	}
}*/
/*inline ll RMQ(int s,int e){
	int k=e-s+1;
	//calc=log(k*1.0)/log(2.0);
	k=log2it[k];
	if(M[s][k]>=M[e-(1<<k)+1][k])
		return M[s][k];
	return M[e-(1<<k)+1][k];
}*/
void scanint(int &x) 
{
	register int c = gc();
	x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
// driver programme
int M[18][100002];
//int M[100002][18];
int main(){
	int log2it[100006], xit[100006], yit[100006],n,m,x,y,c1,c2,i,k,j,bw[20],v1,v2;
	double calc;
	ll ans=0;
	scanint(n);
	//si(n);
	rep(i,n)
		scanint(M[0][i]);
		//scanint(M[i][0]);
	log2it[1]=0;
	FOR(i,0,20)
		bw[i]=1<<i;
	FOR(i,2,100004)
	{
		calc=log(i*1.0)/log(2.0);
		log2it[i]=(int)calc;
	}
	for(j=1;(1<<j)<=n ;j++){
		for(i=0;i+(1<<j)-1<n;i++){
			if(M[j-1][i]>M[j-1][i+bw[j-1]])
				M[j][i]=M[j-1][i];
			else
				M[j][i]=M[j-1][i+bw[j-1]];
			/*if(M[i][j-1]>M[i+bw[j-1]][j-1])
				M[i][j]=M[i][j-1];
			else
				M[i][j]=M[i+bw[j-1]][j-1];*/
		}
	}
	scanint(m);
	scanint(x);
	scanint(y);
	FOR(i,0,n)
	{
		xit[i]=(i+7)%(n-1);
		yit[i]=(i+11)%n;
	}
		//sl(A[i]);
	//si(m);si(x);si(y);
	//c1=7%(n-1);
	//c2=11%n;
	//Compute_ST(n);
	rep(i,m)
	{
		if(x<y)
		{
			//k=y-x+1;
			k=log2it[y-x+1];
			c1=y-bw[k]+1;
			v1=M[k][x];
			v2=M[k][c1];
			//v1=M[x][k];
			//v2=M[c1][k];
			if(v1>v2)
				ans=ans+v1;
			else
				ans=ans+v2;
			/*if(M[x][k]>M[c1][k])
				ans+=M[x][k];
			else
				ans+=M[c1][k];*/
		}
		else
		{
			//k=x-y+1;
			k=log2it[x-y+1];
			c1=x-bw[k]+1;
			v1=M[k][y];
			v2=M[k][c1];
			//v1=M[y][k];
			//v2=M[c1][k];
			if(v1>v2)
				ans=ans+v1;
			else
				ans=ans+v2;
			/*if(M[y][k]>M[c1][k])
				ans+=M[y][k];
			else
				ans+=M[c1][k];*/
		}
		/*x=x+7;
		y=y+11;
		if(x>=n-1)
			x-=(n-1);
		if(y>=n)
			y-=n;*/
		x=xit[x];
		y=yit[y];
		//trace3(x,y,ans);
	}
	cout<<ans<<endl;
	//pln(ans);
	return 0;
}













