#include<stdio.h>
int main()
{
	long long int a,b,c,d,e,f,d1,d2,d3;
	int t,cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f);
		d1=(c-a)*(c-a)+(d-b)*(d-b);
		d2=(e-c)*(e-c)+(d-f)*(d-f);
		d3=(e-a)*(e-a)+(f-b)*(f-b);
		if(d1+d2==d3 || d2+d3==d1 || d3+d1==d2)
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
