#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define lld long long
#define ld long double
#define pb push_back 
#define MOD 1000000007
#define PI 3.14159265
lld modpow(lld a,lld n,lld temp){lld res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;}
long long mul_inv(long long  a, long long b)
{
    return modpow(a,b-2,b);
}


int main()
{
    int t;

    cin >> t;
    int count=1;
    while(t--)
    {
    long long n,i;
    cin >> n;
    multiset<int> k;

    for(i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        k.insert(temp);        
    }

    long long ans=0;
    auto p = k.end();
    p--;
    long long val = *(p);
    long long first =val;

    while(val>=4)
    {
        //cout << val <<endl;
        if(k.count(val)+val/2 + val%2 >= val)
        {
            break;
        }
        first=min(first,ans+val);
        k.insert(val/2);
        k.insert(val/2+val%2);
        auto p = k.end();
        p--;
        k.erase(p);
        p = k.end();
        p--;
        val = *(p);
        ans++;

    }
    ans+=val;
    if(ans>first)
        ans=first;

    cout << "Case #" <<count << ": " << ans <<endl;
    count++;
    }

    return 0;
}
