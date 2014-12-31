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
	int c1,d1,calc1,calc,calc2,a,b,c,d,e,f,cnt=1,a1,b1;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	e=gcd(a,b);
	f=gcd(c,d);
	a/=e;b/=e;
	c/=f;d/=f;
	a1=a;b1=b;
	c1=c;d1=d;
	cnt=1;
	while(c1<a || d1<b)
	{
		cnt++;
		c1=c*cnt;
		d1=d*cnt;
	}
	if(c<a && d<b)
	{
		c1=(c1*(cnt-1))/cnt;
		d1=(d1*(cnt-1))/cnt;
	}
	printf("%d %d %d\n",c1,d1,cnt);
	c=c1;d=d1;
	cnt=1;
	while(a1<c || b1<d)
	{
		cnt++;
		a1=a*cnt;
		b1=b*cnt;
	}
	a=a1;b=b1;
	printf("%d/%d %d/%d\n",a,b,c,d);
	calc1=a*b;
	calc2=c*d;
	//printf("%d %d\n",calc1,calc2);
	calc=calc1;
	calc1-=calc2;
	calc2=calc;
	//printf("%d %d\n",calc1,calc2);
	calc=gcd(calc1,calc2);
	calc1/=calc;calc2/=calc;
	printf("%d/%d\n",calc1,calc2);
	return 0;
}
