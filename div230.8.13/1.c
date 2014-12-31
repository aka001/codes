#include<stdio.h>
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	long long int cnt=0,c,a,b,z;
	int x,y,g;
	scanf("%d %d %lld %lld",&x,&y,&a,&b);
	g=gcd(x,y);
	z=(x*y)/g;
	c=a/z;
	while(c*z<a)
		c++;
	//printf("%lld\n",c);
	cnt=b/z-c+1;

	printf("%lld\n",cnt);
	return 0;
}
