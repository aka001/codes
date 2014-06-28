#include<bits/stdc++.h>
using namespace std;
 
#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >
// dp[rlen][mask][less]
LL dp[20][1024][2];
int len, dig[32];
int bits[1024];
int burn = 0, vis[20][1024][2];
LL rec(int rlen, int mask, int less) {
  if(vis[rlen][mask][less] != burn) {
    vis[rlen][mask][less] = burn;
    if(less == 0)
      dp[rlen][mask][less] = -1;
  }
  LL& ret = dp[rlen][mask][less];
  if(ret == -1) {
    ret = 0;
    if(rlen == 0) {
      ret = bits[mask];
    } else {
      for(int i=(mask==0);i<10;i++) {
        if(less == 0 && i > dig[len-rlen])
          break;
        ret += rec(rlen-1, mask | (1<<i), less | (i<dig[len-rlen]));
      }
    }
  }
  return ret;
}
 
void precomp(void) {
  for(int i=0;i<1024;i++) {
    bits[i] = 0;
    int tmp = i;
    while(tmp) {
      bits[i] += (tmp&1);
      tmp/=2;
    }
  }
}
 
int main() {
  LL t, n;
  cin>>t;
  memset(dp, -1, sizeof(dp));
  precomp();
  while(t--) {
    cin>>n;
    burn++;
    LL tmp = n;
    int ind = 0;
    while(tmp) {
      dig[ind++] = tmp%10;
      tmp/=10;
    }
    reverse(dig, dig+ind);
    len = ind;
    LL P = 0;
    for(int i=1;i<=len;i++) {
      P += rec(i, 0, i!=len);
    }
    LL Q = 10*n;
    LL gcd = __gcd(P, Q);
    Q/=gcd;
    P/=gcd;
    printf("%lld/%lld\n",P,Q);
  }
  return 0;
}
