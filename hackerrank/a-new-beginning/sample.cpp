#include<iostream>
#include<string>
#define LL long long int
#define rep(i,x,n) for(i=x;i<n;i++)
using namespace std;

LL kmh[25],p=0,dp[16][136];

//returns string value of an integer
string convert(LL n)
{
    LL i,j,k;
    if(n==0)return "0";
    string str;
    for(i=n;i!=0;i/=10)
    {
        str=(char)(i%10+48)+str;
    }
    return str;
}

LL cal(LL n)
{
    string str=convert(n);
    LL x=0,ans=0,i,j,k,bits,l=str.length();
    rep(i,0,l)
    {
        bits=l-i;
        rep(j,0,str[i]-48)
        {
            rep(k,0,p)
            {
                if(kmh[k]-x-j>=0)ans+=dp[bits-1][kmh[k]-x-j];
            }
        }
        x+=(str[i]-48);
    }
    return ans;
}

int main()
{
    LL i,j,k,n,t,a,b;

    //compute KMH numbers
    LL d[136]={0};
    for(i=2;i<136;i++)
    {
        if(!d[i])
        {
            for(j=i;j<136;j+=i)
            d[j]+=i;
        }
    }
    for(i=2;i<136;i++)if((d[i]&(d[i]-1))==0)kmh[p++]=i;

    //dp to compute number of integers of x bits with s sum as dp[x][s]
    rep(i,0,10)dp[1][i]=1;
    dp[0][0]=1;
    rep(i,2,16) //bits
    {
        rep(j,0,136)  //sum
        {
            rep(k,0,10) //setting MSB as k
            {
                if(j-k>=0)
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }

    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<cal(b+1)-cal(a)<<endl;
    }
    return 0;
}

