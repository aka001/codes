import java.io.*;
public class armstrong
{
	public static void main(String args[]) throws java.lang.Exception
	{
		int i,calc,calc1,sum,calcit;
		for(i=100;i<=1000;i++)
		{
			calc1=i;
			calc=i;
			sum=0;
			while(calc!=0)
			{
				calcit=calc%10;
				calcit=calcit*calcit*calcit;
				sum+=calcit;
				calc/=10;
			}
			if(sum==calc1)
				System.out.println(calc1);
		}
	}
}
