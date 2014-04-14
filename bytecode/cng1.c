#include<stdio.h>
int main()
{
	long long int calc,a,b,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		calc=a*b-a-b;
		printf("%lld\n",calc);
	}
	return 0;
}
