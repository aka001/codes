#include<stdio.h>
int main()
{
	int i,t,d=0,cnt,a[36],b[36],temp;
	char s[100],ch;
	long long int calc=0,val=1,calc1;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;calc=0;d=0;
		scanf("%s",s);
		for(i=0;i<36;i++)
		{
			a[i]=0;
			b[i]=-1;
		}
		for(i=0;s[i]!='\0';i++)
		{
			ch=s[i];
			if(ch>='a' && ch<='z')
				ch-='a';
			else if(ch>='0' && ch<='9')
				ch=ch-'0'+26;
			if(d==0 && a[ch]==0)
				b[ch]=1;
			else if(d==1 && a[ch]==0)
				b[ch]=0;
			else if(a[ch]==0)
				b[ch]=d;
			if(a[ch]==0)
			{
				d++;
				a[ch]=1;
			}
			//printf("%d %d %c %d\n",d,a[ch],s[i],ch);
		}
		cnt=i;
		//printf("d=%d\n",d);
		cnt--;
		calc1=1;
		if(d==1)
			d=2;
		for(;cnt>=0;cnt--)
		{
			ch=s[cnt];
			if(ch>='a' && ch<='z')
				ch-='a';
			else if(ch>='0' && ch<='9')
				ch=ch-'0'+26;
			calc+=calc1*b[ch];
			calc1*=d;
		}
		printf("%lld\n",calc);
	}
	return 0;
}



