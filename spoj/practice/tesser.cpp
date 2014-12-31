/*******************
  	Akash Agrawall
	IIIT HYDERABAD
	***********************/

#include<bits/stdc++.h>
using namespace std;
int a[100006],lcp[100006];
int matchit(string ch, string txt)
{
	int i,j,n,m;
	//cout<<ch<<endl<<txt<<endl;
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
			return 1;
		if(ch[j]!=txt[i])
		{
			//printf("i=%d j=%d %c %c\n",i,j,ch[j],txt[i]);
			if(j!=0)
			{
				j=lcp[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	return 0;
}
void pattern(string ch)
{
	int i,sz,len;
	sz=ch.size();
	lcp[0]=0;
	len=0;
	for(i=1;i<sz;i++)
	{
		if(ch[i]==ch[len])
		{
			lcp[i]=++len;
		}
		else
		{
			while(len>0 && ch[len]!=ch[i])
				len=lcp[len-1];
			if(ch[len]==ch[i])
				lcp[i]=++len;
			else
				lcp[i]=len;
		}
	}
}
int main()
{
	int t,n,ans,i;
	string ch;
	scanf("%d",&t);
	while(t--)
	{
		string txt="";
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<n;i++)
		{
			if(a[i]>a[i-1])
				txt+='G';
			else if(a[i]<a[i-1])
				txt+='L';
			else
				txt+='E';
		}
		cin>>ch;
		pattern(ch);
		/*cout<<ch<<endl;
		cout<<txt<<endl;*/
		n=ch.size();
		/*for(i=0;i<n;i++)
			printf("%d",lcp[i]);
		printf("\n");*/
		ans=matchit(ch,txt);
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
