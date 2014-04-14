#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[20];
int vis[20];
int cnt;
int step[1010];
int l,r,ans;
int m;


bool dfs(int x,int flag,int sum)
{
    if(sum>=m)
        return true;
    for(int i=0;i<cnt;i++)
    {
        if(i==x)
            continue;
        if(flag==0)
        {
            if(r+vis[i]<=l)
                continue;
            r+=vis[i];
            step[sum+1] = vis[i];
            if(dfs(i,1,sum+1))
                return true;
            r-=vis[i];
        }
        else
        {
            if(l+vis[i]<=r)
                continue;
            l+=vis[i];
            step[sum+1] = vis[i];
            if(dfs(i,0,sum+1))
                return true;
            l-=vis[i];
        }
    }
    return false;
}

int main()
{

    while(~scanf("%s",&s))
    {
        cnt = 0;
        for(int i=0;i<10;i++)
        {
            if(s[i]=='1')
            {
                vis[cnt++] = i+1;
            }
        }
        cin>>m;

        if(cnt == 0)
        {
            printf("NO\n");
            continue;
        }

        if(m>1 && cnt==1)
        {
            printf("NO\n");
            continue;
        }
        else if(m==1)
        {
            printf("YES\n");
            printf("%d\n",vis[0]);
            continue;
        }
        else
        {
            bool f=false;
            for(int i=0;i<cnt;i++)
            {
                l=r=0;
                step[1] = vis[i];
                l+=vis[i];
                if(dfs(i,0,1))
                {
                    f=true;
                    break;
                }
            }
            if(!f)
                printf("NO\n");
            else
            {
                printf("YES\n");
                for(int i=1;i<m;i++)
                    cout<<step[i]<<" ";
                cout<<step[m]<<endl;
            }
        }
    }
    return 0;
}
