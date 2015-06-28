/*******************
  Ashish Kumar - IIIT Hyderabad
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
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 

int main()
{
	string a,b,c;
	int i,j,k;
	int req[150]={0};
	int cur[150]={0};
	int cur2[150]={0};
	int req2[150]={0};
	cin >> a >> b >> c;
	int l = b.length();
	for(i=0;i<l;i++){
		req[b[i]-'a']++;
	}
	l = a.length();
	for(i=0;i<l;i++){
		cur[a[i]-'a']++;
		cur2[a[i]-'a']++;
	}
	l = c.length();
	for(i=0;i<l;i++){
		req2[c[i]-'a']++;
	}
	int nb = INT_MAX;
	int nc = INT_MAX;
	for(i=0;i<=26;i++){
		if(req[i]!=0){
			nb=min(nb,(cur[i]/req[i]));
		}
		/*if(req2[i]!=0){
		  nc = min(nc,(cur[i]/req2[i]));
		  }*/
	}
	//cout << nb <<" "<< nc << endl;
	int tot = 0, bac1 = 0, bac2 = 0, tot2 = 0;
	string s1="", s2="";
	for(j=0;j<=nb;j++){
		//cout << j << endl;
		int temp[150]={0};
		s1 = "";
		for(i=0;i<=26;i++){
			temp[i] = cur[i];
			if(req[i]!=0){
				cur[i]-=(j*req[i]);
			}
		}
		bac1 = INT_MAX;
		for(i=0;i<=26;i++){
			if(req2[i]!=0){
				bac1=min(bac1,cur[i]/req2[i]);
			}
		}
		if(bac1==INT_MAX)
			bac1 = 0;
		/*for(i=0;i<j;i++){
		  s1+=(b);
		  }
		  for(i=0;i<bac1;i++){
		  s1+=(c);
		  }
		  for(i=0;i<=26;i++){
		  if(req2[i]!=0){
		  cur[i]-=(bac1*req2[i]);
		  }
		  }*/
		/*for(i=0;i<=26;i++){
		  while(cur[i]!=0){
		  s1+=(char)('a'+i);
		  cur[i]--;
		  }
		  }*/
		if((j+bac1)>tot){
			tot2 = j;
			bac2 = bac1;
			tot = j+bac1;
		}
		for(i=0;i<=26;i++){
			cur[i]=temp[i];
		}
		//tot = nb+bac1;
	}
	for(i=0;i<tot2;i++){
		s2+=(b);
	}
	for(i=0;i<bac2;i++){
		s2+=(c);
	}
	for(i=0;i<=26;i++){
		if(req2[i]!=0){
			cur[i]-=(bac2*req2[i]);
		}
		if(req[i]!=0){
			cur[i]-=(tot2*req[i]);
		}
	}
	for(i=0;i<=26;i++){
		while(cur[i]!=0){
			s2+=(char)('a'+i);
			cur[i]--;
		}
	}

	cout << s2 << endl;
	return 0;
}










