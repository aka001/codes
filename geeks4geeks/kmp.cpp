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


int findpattern(string ch, string txt,int f[1000])
{
	int i,m,n,ans=0,j;
	m=ch.size();
	n=txt.size();
	i=0;
	j=0;
	while(i<n)
	{
		if(ch[j]==txt[i])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			ans++;
			//printf("i=%d j=%d\n",i,j);
			j=f[j-1];
		}
		else if(ch[j]!=txt[i])
		{
			if(j!=0)
				j=f[j-1];
			else
				i++;
		}
	}
	return ans;
}
void lcs(string ch,int f[1000])
{
	int i,sz,len;
	sz=ch.size();
	f[0]=0;
	len=0;	
	i=1;
	while(i<sz)
	{
		if(ch[i]==ch[len])
		{
			len++;
			f[i]=len;
		}
		else
		{
			while(len>0 && ch[i]!=ch[len])
				len=f[len-1];
			if(ch[i]==ch[len])
			{
				f[i]=++len;
			}
			else
				f[i]=0;
		}
		i++;
	}
}
int main()
{
	int f[1000],sz,i,ans;
	string ch,txt;
	cin>>ch;
	cin>>txt;
	lcs(ch,f);
	cout<<ch<<endl;
	sz=ch.size();
	for(i=0;i<sz;i++)
		printf("%d",f[i]);
	printf("\n");
	ans=findpattern(ch,txt,f);
	printf("%d\n",ans);
	return 0;
}















